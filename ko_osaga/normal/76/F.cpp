#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;

int n, v;
pi a[100005];
int d1[100005], d2[100005];

struct seg{
	int tree[105000];
	void init(){
		fill(tree, tree + 105000, -1e9);
	}
	void add(int x, int v){
		while(x <= n + 5){
			tree[x] = max(tree[x], v);
			x += x & -x;
		}
	}
	int query(int x){
		int ret = -1e9;
		while(x){
			ret = max(ret, tree[x]);
			x -= x & -x;
		}
		return ret;
	}
}seg1, seg2;

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%lld %lld",&a[i].first, &a[i].second);
	}
	cin >> v;
	vector<lint> vy;
	vy.push_back(-1e18);
	for(int i=0; i<=n; i++){
		a[i] = pi(v * a[i].second - a[i].first, v * a[i].second + a[i].first);
		vy.push_back(a[i].second);
	}
	sort(vy.begin(), vy.end());
	vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
	sort(a+1, a+n+1);
	for(int i=0; i<=n; i++){
		a[i].second = lower_bound(vy.begin(), vy.end(), a[i].second) - vy.begin();
	}
	seg1.init();
	seg2.init();
	seg1.add(a[0].second, 0);
	int r1 = 0, r2 = 0;
	for(int i=1; i<=n; i++){
		d1[i] = -1e9;
		if(a[i].first >= 0) d1[i] = seg1.query(a[i].second) + 1;
		d2[i] = max(0, seg2.query(a[i].second)) + 1;
		seg1.add(a[i].second, d1[i]);
		seg2.add(a[i].second, d2[i]);
		r1 = max(r1, d1[i]);
		r2 = max(r2, d2[i]);
	}
	cout << r1 << " " << r2;
}