#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7; 

bool used[N];

int tin[N], fup[N], t;
vector <pair<int,int> > g[N];
vi rb[N];

int n,m, a[N], b[N], p[N], rnk[N], c[N], cnt[N];

ll s[N], d[N], ans;
bool is_bridge[N], ok[N];

void dfs(int v,int p = -1){
	used[v] = 1;
	tin[v] = fup[v] = ++t;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i].f;
		if(to == p) continue;
		if(used[to]){
			fup[v] = min(fup[v],tin[to]);
		}
		else{
			dfs(to,v);
			fup[v] = min(fup[v], fup[to]);
			if(fup[to] > tin[v]){
				is_bridge[g[v][i].s] = 1;
			}
		}
	}
}

int get(int v){
	if(p[v] == v) return v;
	return p[v] = get(p[v]);
}

void Merge(int u,int v){
	u = get(u);
	v = get(v);
	if(u == v) return;
	if(rnk[u] > rnk[v]){
		rnk[u] += rnk[v];
		p[v] = u;
	}
	else{
		rnk[v] += rnk[u];
		p[u] = v;
	}
}

void calc(int v){
	used[v] = 1;
	ok[v] = (cnt[v] > 1);
	for(int i = 0; i < rb[v].size(); i++){
		int to = rb[v][i];
		if(!used[to]){
			calc(to);
			if(ok[to]) ok[v] = 1;
			d[v] = max(d[to], d[v]);
		}
	}
	if(ok[v]){
		ans += s[v];
		d[v] = 0;
	}
	else{
		d[v] += s[v];
	}
}

int main () {
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d",&c[i]);
	}
	for(int i = 1,x,y; i <= m; i++){
		scanf("%d%d",&x,&y);
		g[x].pb(mp(y,i));
		g[y].pb(mp(x,i));
		a[i] = x;
		b[i] = y;
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		p[i] = i;
		rnk[i] = 1;
		g[i].clear();
	}
	for(int i = 1; i <= m; i++){
		if(!is_bridge[i]){
			Merge(a[i], b[i]);
		}
	}
	for(int i = 1,x,y; i <= m; i++){
		if(is_bridge[i]){
			x = get(a[i]);
			y = get(b[i]);
			rb[x].pb(y);
			rb[y].pb(x);
		}
	}
	for(int i = 1; i <= n; i++){
		int v = get(i);
		cnt[v]++;
		s[v] += c[i];
	}
	memset(used, 0, sizeof(used));
	int root;
	scanf("%d", &root);
	calc(get(root));
	ll mx = 0;
	for(int i = 1; i <= n; i++){
		mx = max(mx, d[i]);
	}
	printf("%lld\n", ans + mx);
return 0;
}