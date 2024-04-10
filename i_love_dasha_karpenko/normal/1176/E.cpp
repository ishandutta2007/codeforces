#include <bits/stdc++.h>

using namespace std;
#define DIM  200007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
struct pp {
	ll a, b;
	bool operator <(const pp& V)const {
		if (a == V.a)return b < V.b;
		return a < V.a;
	}
	bool operator ==(const pp& V)const {
		if (a == V.a && b == V.b)return 1;
		return 0;
	}
};
struct word {
	string s;
	ll num;
	char last;
	bool operator <(const word& V)const {
		if (num == V.num)return last < V.last;
		return num < V.num;
	}
};
set<char> S;
ll t, n,m,res = 0;
arr P,V;

ll F(ll x) {
	if (x == P[x])return x;
	P[x] = F(P[x]);
	return P[x];
}
int ch(ll x, ll y) {
	x = F(P[x]);
	y = F(P[y]);
	if (x == y)return 1;
	return 0;
}

void unite(ll x, ll y) {
	x = F(P[x]);
	y = F(P[y]);
	if (rand() % 2 == 0)P[x] = y;
	else P[y] = x;
}
graph A;

void dfs(ll x,ll col) {
	if (col == 1)res++;
	V[x] = col;
	for (ll to : A[x]) {
		if (V[to] == 0)dfs(to, 3 - col);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	for (int h = 1; h <= t;h++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			P[i] = i;
			V[i] = 0;
			A[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			ll x, y; cin >> x >> y;
			if (!ch(x, y)) {
				unite(x, y);
				A[x].push_back(y);
				A[y].push_back(x);
			}
		}
		res = 0;
		dfs(1,1);
		if (res > n / 2) {
			cout << n - res << endl;
			for (int i = 1; i <= n; i++) {
				if (V[i] == 2)cout << i << ' ';
			}
		}
		else {
			cout << res << endl;
			for (int i = 1; i <= n; i++) {
				if (V[i] == 1)cout << i << ' ';
			}
		}
		cout << endl;
	}
}