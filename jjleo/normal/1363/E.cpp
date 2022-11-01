#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;

vector<int> v[maxn];
int a[maxn], b[maxn], c[maxn];

struct Node{
	int x, a, dep;
	
	inline friend bool operator < (Node x, Node y){
		return x.a == y.a ? x.dep < y.dep : x.a < y.a;
	}
};

multiset<Node> st;
int cnt;
int x, y;
int dep[maxn];
int f[maxn], g[maxn];
ll ans;

void dfs(int i, int fa){
	st.insert((Node){i, a[i], dep[i]});
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dep[to] = dep[i] + 1;
		dfs(to, i);
	}
	if(b[i] > c[i]) f[(*(st.begin())).x]++;
	else if(b[i] < c[i]) g[(*(st.begin())).x]++;
	int x = min(f[i], g[i]);
	//printf("%d %d--\n", i, x);
	f[i] -= x, g[i] -= x;
	ans += 1ll * a[i] * x * 2;
	st.erase((Node){i, a[i], dep[i]});
	if(f[i] || g[i]) f[(*(st.begin())).x] += f[i], g[(*(st.begin())).x] += g[i];
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		if(b[i] < c[i]) cnt--;
		else if(c[i] < b[i]) cnt++;
	}
	if(cnt) return printf("-1"), 0;
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1, 0);
	printf("%lld", ans);
}