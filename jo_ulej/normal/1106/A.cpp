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

char a[511][511];

void solve()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];

	int cnt = 0;

	for(int i = 1; i < n - 1; ++i)
	{
		for(int j = 1; j < n - 1; ++j)
		{
			if(a[i][j] != 'X')
				continue;

			if(a[i - 1][j - 1] != 'X')
				continue;

			if(a[i + 1][j - 1] != 'X')
				continue;

			if(a[i + 1][j + 1] != 'X')
				continue;

			if(a[i - 1][j + 1] != 'X')
				continue;

			++cnt;
		}
	}

	cout << cnt << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}