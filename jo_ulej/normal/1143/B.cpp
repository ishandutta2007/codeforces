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

map<string, ll> mem;

ll mypow(ll x, int p)
{
	ll ret = 1;

	for(; p > 0; --p)
		ret *= x;

	return ret;
}

ll calc(string s)
{
	if(s.size() == 1)
		return s.back() - '0';

	if(mem.find(s) != mem.end())
		return mem[s];

	ll ret = mypow(9, s.size() - 1);

	if(s.front() != '1')
		ret = max(ret, (s.front() - '1') * mypow(9, s.size() - 1));

	ret = max(ret, (s.front() - '0') * calc(s.substr(1, s.size() - 1)));

	return (mem[s] = ret);
}

void solve()
{
	string s;
	cin >> s;

	cout << calc(s) << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}