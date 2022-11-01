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

string shift(string s, int t)
{
	int n = s.size();

	reverse(s.begin(), s.begin() + (s.size() - t));
	reverse(s.begin() + (s.size() - t), s.end());

	reverse(s.begin(), s.end());

	return s;
}

bool is_palyndrome(string s)
{
	for(int i = 0, j = s.size() - 1; i < j; ++i, --j)
		if(s[i] != s[j])
			return false;

	return true;
}

void solve()
{
	string str;
	cin >> str;
	int n = str.size();

	if(str.size() <= 2)
	{
		cout << "Impossible" << endl;
		return;
	}

	for(int i = 1; i < n; ++i)
	{
		string s = shift(str, i);

		if(is_palyndrome(s) && s != str)
		{
			DBG(s);

			cout << "1" << endl;
			return;
		}
	}

	for(int i = 0, j = n - 1; i < j; ++i, --j)
	{
		if(str.substr(0, i + 1) != str.substr(j, n - j))
		{
			cout << "2" << endl;
			return;
		}
	}

	cout << "Impossible" << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}