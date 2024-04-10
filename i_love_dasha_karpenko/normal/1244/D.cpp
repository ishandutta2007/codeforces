#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
const ll BLOCK = 400;
const ll DIM = 100007;
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = po(20);
const ll bufsize = 500;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
bool const operator>(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc > b.sc;
	return a.fi > b.fi;
}
ll n, col[DIM],col1[DIM], C[DIM][3];
ll cnt[3];
vector<ll> G[DIM];
void dfs(ll v, ll c, ll par) {
	col[v] = c;
	//cnt[c]++;
	if (par == -1) {
		for (ll to : G[v]) {
			c++;
			c %= 3;
			dfs(to, c, v);
		}
		return;
	}
	for (ll to : G[v]) {
		if (to == par)continue;
		c = 3 - col[par] - col[v];
		dfs(to, c, v);
	}
}
void dfs1(ll v, ll c, ll par) {
	col1[v] = c;
	//cnt[c]++;
	if (par == -1) {
		c += 3;
		for (ll to : G[v]) {
			c--;
			if (c < 0)c += 3;
			dfs1(to, c, v);
		}
		return;
	}
	for (ll to : G[v]) {
		if (to == par)continue;
		c = 3 - col1[v] - col1[par];
		dfs1(to, c, v);
	}
}
int main() {
	schnell;
	cin >> n;
	for(ll j = 0;j<3;j++)
	forn(i, n) {
		cin >> C[i][j];
	}
	forn(i, n - 1) {
		ll x, y; cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}
	forn(i, n) {
		if (G[i].size() > 2) {
			cout << "-1\n";
			return 0;
		}
	}
	dfs(1, 0, -1);
	dfs1(1, 0, -1);
	ll r1 = 0, r2 = 0, r3 = 0,r11 = 0,r22 = 0,r33 = 0;
	forn(i, n) {
		r1 += C[i][col[i]];
		r2 += C[i][(col[i] + 1) % 3];
		r3 += C[i][(col[i] + 2) % 3];
		r11 += C[i][col1[i]];
		r22 += C[i][(col1[i] + 1) % 3];
		r33 += C[i][(col1[i] + 2) % 3];
	}
	ll mi = min(min(r1, min(r2, r3)), min(r11, min(r22, r33)));
	if (r1 ==mi) {
		cout << r1 << endl;
		forn(i, n)cout << col[i] + 1 << ' ';
		cout << endl;
		return 0;
	}

	if (r2 == mi) {
		cout << r2 << endl;
		forn(i, n)cout << (col[i]+1)%3 + 1 << ' ';
		cout << endl;
		return 0;
	}
	if (r3 == mi) {
		cout << r3 << endl;
		forn(i, n)cout << (col[i]+2)%3 + 1 << ' ';
		cout << endl;
		return 0;
	}
	if (r11 == mi) {
		cout << r11 << endl;
		forn(i, n)cout << col1[i] + 1 << ' ';
		cout << endl;
		return 0;
	}

	if (r22 == mi) {
		cout << r22 << endl;
		forn(i, n)cout << (col1[i] + 1) % 3 + 1 << ' ';
		cout << endl;
		return 0;
	}
	if (r33 == mi) {
		cout << r33 << endl;
		forn(i, n)cout << (col1[i] + 2) % 3 + 1 << ' ';
		cout << endl;
		return 0;
	}


	return 0;
}