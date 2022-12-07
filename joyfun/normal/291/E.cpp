#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;++i)

struct SAM{ // [0,L] , 0 is virtual , 1 is rt , init!!
	static const int N = 601010 , M = 26;
	int par[N] , l[N] , ne[N][M], to[N], dp[N], tp[N], cnt[N];
	int rt , last , L;
	void add(int c, int u){
		int p = last;
		if(ne[p][c] && l[ne[p][c]] == l[p] + 1){
			last = ne[p][c];
			dp[last]++;
			return;
		}
		assert(L + 1 <= N);
		int np = ++L;
		fill(ne[np] , ne[np] + M , 0);
		l[np] = l[p] + 1;
		last = np; to[u] = np; dp[np] = 1;
		while(p && !ne[p][c]) ne[p][c] = np , p = par[p];
		if(!p) par[np] = rt;
		else{
			int q = ne[p][c];
			if(l[q] == l[p] + 1) par[np] = q;
			else{
				int nq = ++L;
				l[nq] = l[p] + 1;
				copy(ne[q] , ne[q] + M , ne[nq]);
				par[nq] = par[q];
				par[q] = par[np] = nq;
				while(p && ne[p][c] == q) ne[p][c] = nq , p = par[p];
			}
		}
	}
	void ini(){
		rt = last = L = 1;
		fill(ne[rt] , ne[rt] + M , 0);
		l[0] = -1;
	}

	void Toop() {
		for (int i = 0; i < N; i++) cnt[i] = 0;
		for (int i = 1; i <= L; i++) cnt[l[i]]++;
		for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
		for (int i = 1; i <= L; i++) tp[cnt[l[i]]--] = i;
		for (int i = L; i >= 1; i--) {
			int u = tp[i];
			dp[par[u]] += dp[u];
		}
	}
} gao;

const int N = 100005;
vector<pair<int, string> > g[N];
int n;
char s[N * 3];

void dfs(int u) {
	int last = gao.last;
	random_shuffle(g[u].begin() , g[u].end());
	for (int i = 0; i < sz(g[u]); i++) {
		int v = g[u][i].fi;
		string tmp = g[u][i].se;
		gao.last = last;
		for (int j = 0; j < tmp.length(); j++)
			gao.add(tmp[j] - 'a', v);
		dfs(v);
	}
}

int main(){
	srand(time(NULL));
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d%s", &p, s);
		g[p].pb(mp(i, s));
	}
	gao.ini();
	gao.to[1] = gao.last;
	dfs(1);
	gao.Toop();
	scanf("%s", s + 1);
	int m = strlen(s + 1);
	int u = gao.rt, f = 1;
	for (int i = 1; i <= m; i++) {
		int v = gao.ne[u][s[i] - 'a'];
		if (!v) {
			f = 0;
			break;
		}
		u = v;
	}

	if (!f) printf("0\n");
	else printf("%d\n", gao.dp[u]);
	return 0;
}