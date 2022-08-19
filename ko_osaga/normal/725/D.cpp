#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

struct pi{
	lint first, second, idx;
	bool operator<(const pi &p)const{
		return make_pair(first, second) < make_pair(p.first, p.second);
	}
};

int n;
pi a[300005];
priority_queue<lint, vector<lint>, greater<lint> > pq;
map<lint, int> mp;
const lint inf = 2e18;

struct seg{
	int tree1[1050000];
	lint tree2[1050000];
	void add(int pos, int ps, int pe, int p, lint v){
		if(ps == pe){
			tree1[p]++;
			tree2[p] += v;
			return;
		}
		int pm = (ps + pe) / 2;
		if(pos <= pm) add(pos, ps, pm, 2*p, v);
		else add(pos, pm+1, pe, 2*p+1, v);
		tree1[p] = tree1[2*p] + tree1[2*p+1];
		tree2[p] = tree2[2*p] + tree2[2*p+1];
		tree2[p] = min(tree2[p], inf);
	}
	int getelem(int s, int e, int p, lint x){
		if(x < 0) return 0;
		//printf("%lld %lld %lld %lld\n", s, e, p,x );
		if(s == e){
			return tree2[p] <= x ? tree1[p] : 0;
		}
		int ret = 0;
		int m = (s+e)/2;
		if(tree2[2*p] <= x){
			ret += tree1[2*p];
			x -= tree2[2*p];
		}
		else{
			ret += getelem(s, m, 2*p, x);
			x -= tree2[2*p];
		}
		if(tree2[2*p+1] <= x){
			ret += tree1[2*p+1];
			x -= tree2[2*p+1];
		}
		else{
			ret += getelem(m+1, e, 2*p+1, x);
		}
		return ret;
	}
}seg;

void insert(pi x){
//	printf("%d %lld\n",x.idx, x.second);
	seg.add(x.idx, 0, n-1, 1, x.second);
}

int maxelem(lint x){
//	printf("maximum element %lld\n", x);
//	printf("%lld\n", seg.getelem(0, n-1, 1, x));
	return seg.getelem(0, n-1, 1, x);
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%lld %lld",&a[i].first, &a[i].second);
		a[i].second -= a[i].first;
		a[i].second++;
	}
	sort(a+1, a+n, [&](const pi &a, const pi &b){
		return a.second < b.second;
	});
	for(int i=1; i<n; i++){
		a[i].idx = i;
	}
	sort(a+1, a+n);
	reverse(a+1, a+n);
	int p = 1;
	vector<lint> hcnd;
	for(int i=0; i<n; i++){
		if(a[i].first <= a[0].first){
			hcnd.push_back(a[i].first);
		}
	}
	hcnd.push_back(0);
	sort(hcnd.begin(), hcnd.end());
	hcnd.resize(unique(hcnd.begin(), hcnd.end()) - hcnd.begin());
	reverse(hcnd.begin(), hcnd.end());	
	int rank = 1;
	int ret = 1e9;
	for(auto &i : hcnd){
		while(p < n && a[p].first > i){
			insert(a[p]);
			p++;
			rank++;
		}
		ret = min(ret, rank - maxelem(a[0].first - i));
	}
	cout << ret;
}