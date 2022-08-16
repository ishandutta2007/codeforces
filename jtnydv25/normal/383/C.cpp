#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";

#define LSOne(S) (S & (-S))
const int N = 2e5 + 10;
ll Query(ll* ft, int b) {
    ll sum = 0;
    for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}

void Update(ll* ft, int k, ll v) {
    for (; k < N; k += LSOne(k)) ft[k] += v;
}

struct range_bit{
	ll B1[N], B2[N];
	ll query(int b) {
	    return Query(B1, b) * b - Query(B2, b);
	}

	ll range_query(int i, int j)    {
	    return query(j) - query(i - 1);
	}

	void range_update(int i, int j, ll v)   {
	    Update(B1, i, v);
	    Update(B1, j + 1, -v);
	    Update(B2, i, v * (i - 1));
	    Update(B2, j + 1, -v * j);
	}
} odd, even;
vector<int> con[N];
int st[N], en[N], depth[N], a[N], t;
void dfs(int s = 1, int p = 0){
	st[s] = ++t;
	depth[s] = depth[p] + 1;
	for(int v : con[s])
		if(v != p) dfs(v, s);
	en[s] = t;
}

void update(int x, int val){
	if(depth[x] % 2 == 0) val *= -1;
	odd.range_update(st[x], en[x], val);
	even.range_update(st[x], en[x], -val);
}

int get(int x){
	if(depth[x] & 1) return odd.range_query(st[x], st[x]);
	return even.range_query(st[x], st[x]);
}
int main(){
	int n, m;
	sd(n);sd(m);
	for(int i = 1; i <= n; i++) sd(a[i]);
	for(int i = 1; i < n; i++){
		int u,v ;
		sd(u); sd(v);
		con[u].pb(v);
		con[v].pb(u);
	}
	dfs();
	while(m--){
		int type;
		sd(type);
		if(type == 1){
			int x, val;
			sd(x); sd(val);
			update(x, val);
		}
		else{
			int x;
			sd(x);
			printf("%d\n", a[x] + get(x));
		}
	}
}