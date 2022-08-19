#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, k, a[100005], prv[100005];
queue<int> que[100005];

struct rtree{
	vector<int> tree[270000];
	vector<pi> v;
	int lim;
	void init(){
		for(lim = 1; lim <= n; lim <<= 1);
		for(int i=1; i<=n; i++){
			v.push_back(pi(i, prv[i]));
		}
		sort(v.begin(), v.end(), [&](const pi &a, const pi &b){
			return a.second < b.second;
		});
		for(auto &i : v){
			for(int j=i.first+lim; j; j>>=1){
				tree[j].push_back(i.second);
			}
		}
	}
	int query(int sx, int ex, int sy, int ey){
		auto q = [&](int n, int s, int e){
			return upper_bound(tree[n].begin(), tree[n].end(), e) - lower_bound(tree[n].begin(), tree[n].end(), s);
		};
		 sx += lim;
		 int ret = 0;
		 ex += lim;
		 while(sx < ex){
		 	 if(sx % 2 == 1) ret += q(sx++, sy, ey);
		 	 if(ex % 2 == 0) ret += q(ex--, sy, ey);
		 	 sx >>= 1;
		 	 ex >>= 1;
		 }
		 if(sx == ex) ret += q(sx, sy, ey);
		 return ret;
	}
}rtree;


int main(){
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		que[a[i]].push(i);
		if(que[a[i]].size() > k){
			prv[i] = que[a[i]].front();
			que[a[i]].pop();
		}
		else prv[i] = 0;
	}
	rtree.init();
	int q, ret = 0;
	scanf("%d",&q);
	while(q--){
		int s, e;
		scanf("%d %d",&s,&e);
		s += ret;
		e += ret;
		s = s % n + 1;
		e = e % n + 1;
		if(s > e) swap(s, e);
		ret = rtree.query(s, e, 0, s - 1);
		printf("%d\n", ret);
	}
}