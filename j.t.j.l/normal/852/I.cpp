#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

int n, m;

void prework(){

}

void read(){

}

int LAB;
int in[MAXN], out[MAXN], nd[MAXN << 1];

int bg[MAXN];
int f[MAXN];
vector<int> E[MAXN];

void dfs(int u, int fa){
	in[u] = ++LAB;
	nd[LAB] = u;
	for (auto &v : E[u]){
		if (v != fa){
			dfs(v, u);
		}
	}
	out[u] = ++LAB;
	nd[LAB] = u;
}

int MAKI = 9;


typedef pair<PII, PII> PPP;
PPP q[MAXN << 1];

int cnt[2][MAXN];
ll umi[MAXN];
ll ans;
int vis[MAXN << 1];

void add(int pos){
	int u = nd[pos];
	if (vis[u]){
		vis[u] = 0;
		ans -= cnt[1 - bg[u]][f[u]];
		cnt[bg[u]][f[u]]--;
	}
	else{
		vis[u] = 1;
		ans += cnt[1 - bg[u]][f[u]];
		cnt[bg[u]][f[u]]++;
	}
}

void sub(int pos){
	int u = nd[pos];
	if (vis[u]){
		vis[u] = 0;
		ans -= cnt[1 - bg[u]][f[u]];
		cnt[bg[u]][f[u]]--;
	}
	else{
		vis[u] = 1;
		ans += cnt[1 - bg[u]][f[u]];
		cnt[bg[u]][f[u]]++;
	}
}

int __u[MAXN], __v[MAXN];

struct LowestCommonAncestor{
	static const int MAXNN = ::MAXN, MAXD = 20; // d=log(n-1)+1
	int dep[MAXN];
	int p[MAXNN][MAXD];

	vector<int> *E;

	void DFS(int u, int pre){
		dep[u] = dep[pre] + 1;
		p[u][0] = pre;
		for (int i = E[u].size() - 1; i >= 0; --i)
			if (E[u][i] != pre)
				DFS(E[u][i], u);
	}

	void build(vector<int> tE[], int n, int root = 1){
		E = tE;
		DFS(root, 0);
		for (int j = 1; j < MAXD; ++j)
			for (int i = 1; i <= n; ++i)
				p[i][j] = p[p[i][j - 1]][j - 1];
	}

	int query(int u, int v){
		if (dep[u] > dep[v])
			swap(u, v);
		int diff = dep[v] - dep[u];
		for (int i = 0; diff; ++i, diff >>= 1)
			if (diff & 1)
				v = p[v][i];
		if (u == v)
			return u;

		for (int i = MAXD - 1; i >= 0; --i)
			if (p[u][i] != p[v][i])
				u = p[u][i], v = p[v][i];
		return p[u][0];
	}

	int dist(int u, int v){
		return dep[u] + dep[v] - (dep[query(u, v)] << 1);
	}
} LCA;

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &bg[i]);
	map<int,int>F;
	for (int i = 1; i <= n; i++){
		scanf("%d", &f[i]);
		F[f[i]]=1;
	}
	m = 0;
	for (auto &x : F){
		x.second = ++m;
	}
	for (int i = 1; i <= n; i++)
		f[i] = F[f[i]];
	for (int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	LAB = 0;
	dfs(1, 0);
	LCA.build(E, n, 1);
	/*
	for (int i = 1; i <= 2 * n; i++)
		cout << nd[i] << ' '; cout << endl;
	for (int i = 1; i <= n; i++)
		cout << in[i] << ' '; cout << endl;
	for (int i = 1; i <= n; i++)
		cout << out[i] << ' '; cout << endl;
	*/
	int Q;
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if (in[x] > in[y])
			swap(x, y);
		int L = in[x] + 1;
		int R = in[y];
		q[i] = PPP(PII(L >> MAKI, R), PII(L, i));
		__u[i] = x, __v[i] = y;
	}
	sort(q + 1, q + Q + 1);
	for (int i = 1; i <= m; i++)
		cnt[0][i] = cnt[1][i] = 0;
	int L = 1, R = 0;
	ans = 0;
	// [L, R]
	for (int i = 1; i <= Q; i++){
		//cout << q[i].first.first << ' ' << q[i].first.second << ' ' << q[i].second.first << ' ' << q[i].second.second << endl;
		int LL = q[i].second.first, RR = q[i].first.second;
		while(R < RR) add(++R);
		while(L > LL) add(--L);
		while(R > RR) sub(R--);
		while(L < LL) sub(L++);
		int u = LCA.query(__u[q[i].second.second], __v[q[i].second.second]);
		//cout << "LCA :: " << u << endl;
		umi[q[i].second.second] = ans + cnt[1 - bg[u]][f[u]];
	}
	for (int i = 1; i <= Q; i++)
		printf("%lld\n", umi[i]);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}