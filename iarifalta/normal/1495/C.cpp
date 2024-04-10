/**
 *	author:   fractal
 *	timus: 288481RF
 *	created: 03/10/21 19:03
**/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
#define nl printf("\n");
#define clbuff fflush(stdin);

mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 1e6 + 2;
const int M = 1e5;
const int mod = 0;
const int inf = 2e9 + 3;
const ll INF = 1e18;
const ld pi2 = 2.0 * 3.141592;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void files() {
	#ifndef PC
		freopen(".in", "r", stdin);
		freopen(".out", "w", stdout);
	#endif
}

int T, n, m, mat[505][505];
string s;

int main() {
	speed;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> s;
			for (int j = 1; j <= m; ++j) {
				mat[i][j] = (s[j - 1] == 'X');
			}
		}
		for (int j = 1; j <= m; ++j)
			mat[n + 1][j] = 0;
		for (int i = 1; i <= n; i += 3)
			for (int j = 1; j <= m; ++j)
				mat[i][j] = 1;
		for (int i = 2; i <= n; i += 3) {
			bool f = 0;
			for (int j = 1; j <= m; ++j) {
				if (mat[i][j] == 1 || mat[i + 1][j] == 1) {
					mat[i][j] = mat[i + 1][j] = 1;
					f = 1;
					if (i + 2 <= n)
						break;
				}
			}
			if (!f) {
				mat[i][1] = mat[i + 1][1] = 1;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << ".X"[mat[i][j]];
			}
			cout << '\n';
		}
		cout << '\n';
	}
}