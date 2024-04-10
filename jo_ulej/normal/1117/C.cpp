#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif

#define X first
#define Y second
 
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

string s;
int n;

ll sdx = 0, sdy = 0;

pll wind(ll k)
{
	pll ret;
	ret.X = ret.Y = 0;

	ret.X = (k / (ll)n) * sdx;
	ret.Y = (k / (ll)n) * sdy;
	
	k %= n;

	for(int i = 0; i < k; ++i)
	{
		char chr = s[i];

		if(chr == 'U')
			++ret.Y;
		else if(chr == 'D')
			--ret.Y;
		else if(chr == 'R')
			++ret.X;
		else
			--ret.X;
	}

	return ret;
}

ll X1, Y1, X2, Y2;

ll func(ll k)
{
	auto w = wind(k);

	return abs(X2 - w.X) + abs(Y2 - w.Y);
}

bool good(ll k)
{
	return func(k) <= k;
}

void solve()
{
	cin >> X1 >> Y1 >> X2 >> Y2;
	cin >> n >> s;

	for(auto chr: s)
	{
		if(chr == 'U')
			++sdy;
		else if(chr == 'D')
			--sdy;
		else if(chr == 'R')
			++sdx;
		else
			--sdx;
	}

	X2 -= X1;
	Y2 -= Y1;

	ll L = 0, R = 1e16;

	if(!good(R))
	{
		cout << "-1" << endl;
		return;
	}

	if(good(L))
	{
		cout << "0" << endl;
		return;
	}

	while(R - L > 1)
	{
		ll M = (L + R) / 2;

		if(good(M))
			R = M;
		else
			L = M;
	}

	cout << R << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}