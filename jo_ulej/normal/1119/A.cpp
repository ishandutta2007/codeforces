#include <bits/stdc++.h>
 
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);

	for(auto& el: a)
		cin >> el;

	int lst = 0;

	for(int i = 1; i < n; ++i)
		if(a[i] != a[0])
			lst = i;

	int ans = lst;

	reverse(a.begin(), a.end());

	lst = -1;

	for(int i = 1; i < n; ++i)
		if(a[i] != a[0])
			lst = i;

	ans = max(ans, lst);

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}