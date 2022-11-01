#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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
const int MAX_N = 5211;

int tbl[MAX_N][MAX_N], prefsum[MAX_N][MAX_N];

inline int dig2int(char dgt)
{
	if(dgt <= '9')
		return dgt - '0';

	return dgt - 'A' + 10;
}

inline int query(int lx, int ly, int rx, int ry)
{
	++lx, ++rx, ++ly, ++ry;

	int ret = 0;

	ret += prefsum[rx][ry];
	ret -= prefsum[lx - 1][ry];
	ret -= prefsum[rx][ly - 1];
	ret += prefsum[lx - 1][ly - 1];

	return ret;
}

void solve()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for(int j = 0; j < n / 4; ++j)
		{
			int val = dig2int(str[j]);

			for(int k = 0; k < 4; ++k)
				tbl[i][4 * j + k] = bool(val & (1 << (3 - k)));
		}
	}

#ifdef __LOCAL
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			cout << tbl[i][j];

		cout << endl;
	}
#endif

	vector<int> divs;

	for(int x = 1; x * x <= n; ++x)
	{
		if(n % x == 0)
		{
			divs.push_back(x);

			if(x * x != n)
				divs.push_back(n / x);
		}
	}

	prefsum[0][0] = 0;

	for(int i = 1; i <= n; ++i)
		prefsum[i][0] = prefsum[0][i] = 0;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			prefsum[i][j] = prefsum[i - 1][j] + prefsum[i][j - 1] - prefsum[i - 1][j - 1] + tbl[i - 1][j - 1];

	int ans = 1;

	for(auto x: divs)
	{
		bool correct = true;

		for(int i = 0; i + x - 1 < n && correct; i += x)
		{
			for(int j = 0; j + x - 1 < n && correct; j += x)
			{
				int sm = query(i, j, i + x - 1, j + x - 1);

				if(sm != 0 && sm != x * x)
					correct = false;
			}
		}

		if(correct)
			ans = max(ans, x);
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}