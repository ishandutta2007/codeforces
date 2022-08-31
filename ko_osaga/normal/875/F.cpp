#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 300005;
const int mod = 1e9 + 7;


struct disj{
	int pa[MAXN], chk[MAXN];
	void init(int n){
		for(int i=0; i<=n; i++){
			pa[i] = i;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	int toggle(int x){
		return chk[find(x)];
	}
	void update(int x){
		x = find(x);
		chk[x] = 1;
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p;
		chk[p] |= chk[q];
		return 1;
	}
}disj;

struct edg{int s, e, x;}a[MAXN];
int n, m, chk[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	disj.init(n);
	for(int i=0; i<m; i++) scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].x);
	sort(a, a+m, [&](const edg &a, const edg &b){
		return a.x > b.x;
	});
	vector<edg> v;
	lint ans = 0;
	for(int i=0; i<m; i++){
		if(disj.find(a[i].s) == disj.find(a[i].e)){
			if(!disj.toggle(a[i].s)){
				ans += a[i].x;
				disj.update(a[i].s);
			}
		}
		else{
			if(disj.toggle(a[i].s) == 0 || disj.toggle(a[i].e) == 0){
				disj.uni(a[i].s, a[i].e);
				ans += a[i].x;
			}
		}
	}
	cout << ans << endl;
}