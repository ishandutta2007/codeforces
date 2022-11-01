#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = 106;
bool matr[MAX_N][MAX_N];

int color(int v, int n)
{
	return v < n / 2;
}

void solve()
{
	int n;
	cin >> n;

	for(int v = 0; v < n; ++v)
		for(int u = 0; u < v; ++u)
			matr[u][v] = matr[v][u] = (color(v, n) != color(u, n));

	int nedges = 0;

	for(int v = 0; v < n; ++v)
		for(int u = 0; u < v; ++u)
			if(matr[u][v])
				++nedges;

	cout << nedges << endl;

	for(int v = 0; v < n; ++v)
		for(int u = 0; u < v; ++u)
			if(matr[u][v])
				cout << u + 1 << " " << v + 1 << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}