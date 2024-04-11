#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, m, q;

struct edg{
	int s, e, x, y;
}a[500005];

struct disj{
	int pa[2005];
	void init(int n){
		for(int i=0; i<n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	void uni(int p, int q){
		pa[find(q)] = find(p);
	}
}disj;

int main(){
	cin >> n >> m >> q;
	for(int i=0; i<m; i++){
		scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].x);
		a[i].y = i+1;
	}
	sort(a, a+m, [&](const edg &a, const edg &b){
		return a.x < b.x;
	});
	map<pi, int> cache;
	for(int i=0; i<q; i++){
		disj.init(2*n+2);
		int l, r;
		scanf("%d %d",&l,&r);
		if(cache.find(pi(l, r)) != cache.end()){
			printf("%d\n",cache[pi(l, r)]);
			continue;
		}
		int ret = -1;
		for(int j=m-1; j>=0; j--){
			if(a[j].y > r || a[j].y < l) continue;
			disj.uni(a[j].s + n, a[j].e);
			disj.uni(a[j].s, a[j].e + n);
			if(disj.find(a[j].s) == disj.find(a[j].s + n)){
				ret = a[j].x;
				break;
			}
		}
		cache[pi(l, r)] = ret;
		printf("%d\n", ret);
	}
}