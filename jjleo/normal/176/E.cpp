#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

typedef long long ll;

struct Edge{
	int x, y;
};

vector<Edge> v[maxn];

int dfn[maxn], cnt;
int dep[maxn], fa[maxn][25], lg[maxn];
ll val[maxn];

void dfs(int i){
	dfn[i] = ++cnt;
	for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].x;
		if(to == fa[i][0]) continue;
		fa[to][0] = i, dep[to] = dep[i] + 1, val[to] = val[i] + v[i][j].y;
		dfs(to);
	}
}

inline int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;i >= 0;i--){
		if(fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

inline bool cmp(const int &x, const int &y){
	return dfn[x] < dfn[y];
}

int num;
set<int, decltype(cmp)*> st(cmp);
int n, q;
int x, y, z;
char s[5];
ll ans;
set<int>::iterator it1, it2;

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back((Edge){y, z}), v[y].push_back((Edge){x, z});
	}
	dfs(1);
	scanf("%d", &q);
	while(q--){
		scanf("%s", s);
		switch(s[0]){
			case '+':
				scanf("%d", &x);
				if(num >= 2){
					it1 = st.upper_bound(x);
					if(it1 == st.begin()) it2 = prev(st.end());
					else it2 = prev(it1);
					if(it1 == st.end()) it1 = st.begin();
					ans -= val[*it1] + val[*it2] - 2 * val[lca(*it1, *it2)];
					ans += val[*it1] + val[x] - 2 * val[lca(*it1, x)] + val[*it2] + val[x] - 2 * val[lca(*it2, x)];
				}else if(num == 1) ans += 2 * (val[*(st.begin())] + val[x] - 2 * val[lca(*(st.begin()), x)]);
				++num, st.insert(x);
				break;
			case '-':
				scanf("%d", &x);
				st.erase(x);
				if(num >= 3){
					it1 = st.upper_bound(x);
					if(it1 == st.begin()) it2 = prev(st.end());
					else it2 = prev(it1);
					if(it1 == st.end()) it1 = st.begin();
					ans += val[*it1] + val[*it2] - 2 * val[lca(*it1, *it2)];
					ans -= val[*it1] + val[x] - 2 * val[lca(*it1, x)] + val[*it2] + val[x] - 2 * val[lca(*it2, x)];
				}else ans = 0;
				--num;
				break;	
			case '?':
				printf("%lld\n", ans >> 1);
				break;	
		}
	}
}