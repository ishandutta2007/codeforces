#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int cc = 0;

int f[MAXN], dep[MAXN], ma[MAXN];
int cnt[MAXN], ncnt[MAXN];
vector<int> E[MAXN];

void addcir(int u, int v){
	if (u > v) return ;
	//cout << u << ' ' << v << endl;
	cc++;
	f[u] = f[v] = cc;
	cnt[cc] = 2;
	while(u != v){
		if (dep[u] > dep[v]){
			u = ma[u];
			f[u] = cc;
			cnt[cc]++;
		}
		else{
			v = ma[v];
			f[v] = cc;
			cnt[cc]++;
		}
	}
	cnt[cc]--;
}

void DFS(int u, int fa){
	dep[u] = dep[fa] + 1;
	ma[u] = fa;
	for (auto & v : E[u]){
		if (v != fa){
			if (dep[v]){
				addcir(u, v);
			}
			else{
				DFS(v, u);
			}
		}
	}
}

typedef pair<PII, int> PPI;

PPI q[MAXN];
int X[MAXN];
ll ans[MAXN];

namespace Segment{
	ll a[MAXN];
	int	tag[MAXN], M;
	void Init(int n){
		for (M = 1; M < n; M *= 2);
		for (int i = 2 * M; i >= 1; i--)
			a[i] = 0, tag[i] = 0;
	}
	void pushdown(int l, int r, int u){
		a[u] += 1ll * (r - l + 1) * tag[u];
		if (l != r){
			tag[2 * u] += tag[u];
			tag[2 * u + 1] += tag[u];
		}
		tag[u] = 0;
	}
	int update(int u, int l, int r, int L, int R, ll x){
		pushdown(l, r, u);
		if (L == l && r == R) return tag[u] += x;
		a[u] += x * (R - L + 1);
		int m = (l + r) / 2;
		if (L <= m) update(u * 2, l, m, L, min(R, m), x);
		if (R > m) update(u * 2 + 1, m + 1, r, max(L, m + 1), R, x);
	}
	ll query(int u, int l, int r, int L, int R){
		pushdown(l, r, u);
		if (L == l && r == R) return a[u];
		int m = (l + r) / 2;
		ll ret = 0;
		if (L <= m) ret += query(u * 2, l, m, L, min(R, m));
		if (R > m) ret += query(u * 2 + 1, m + 1, r, max(L, m + 1), R);
		return ret;
	}
	void Update(int l, int r, int x){
		//cout << "UPD :: " << l << ' ' << r << ' ' << x << endl;
		fflush(stdout);
		update(1, 1, M, l, r, x);
	}
	ll Query(int l, int r){
		return query(1, 1, M, l, r);
	}
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (!dep[i])
			DFS(i, 0);
	cnt[0] = n + 2;
/*	cout << cc << endl;
	for (int i = 0; i <= cc; i++)
		cout << cnt[i] << ' '; cout << endl;
	for (int i = 1; i <= n; i++)
		cout << f[i] << ' '; cout << endl;
*/	Segment::Init(n);
//	puts("!!!");
//	fflush(stdout);
	for (int i = 1, j = 0; i <= n; i++){
		ncnt[f[i-1]]--;
		while(j < n && ncnt[f[j+1]] + 1 < cnt[f[j+1]]){
			j++;
			//cout << "!!!   " << j << ' ' << f[j] << ' ' << ncnt[f[j]] << ' ' << cnt[f[j]] << endl;
			ncnt[f[j]]++;
		}
		Segment::Update(i, X[i] = j, 1);
	}
	int Q;
//	puts("WWW");
//	fflush(stdout);
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++){
		scanf("%d%d", &q[i].first.first, &q[i].first.second);
		q[i].second = i;
	}
	sort(q + 1, q + Q + 1);
//	puts("vvv");
//	fflush(stdout);
	for (int i = 1, j = 1; i <= Q; i++){
		while(j <= n && j < q[i].first.first){
			Segment::Update(j, X[j], -1);
			j++;
		}
//		cout << "??? : " << i << ' ' << j << endl;
		ans[q[i].second] = Segment::Query(q[i].first.first, q[i].first.second);
	}
	for (int i = 1; i <= Q; i++)
		printf("%lld\n", ans[i]);
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