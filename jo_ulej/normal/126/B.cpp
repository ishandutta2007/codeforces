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

const ll mod = 1e9 + 7;

void solve()
{
	string str;
	vector<int> z;
	int n;

	int best_i, best_len = 0;

	cin >> str;
	n = str.size();
	z.resize(n, 0);

	{
		int l = -1, r = -1;

		for(int i = 1; i < n; ++i)
		{
			if(i <= r)
				z[i] = min(r - i + 1, z[i - l]);

			while(i + z[i] < n && str[i + z[i]] == str[z[i]])
				++z[i];

			if(i + z[i] - 1 > r)
				l = i, r = i + z[i] - 1;
		}
	}

	int zmx = 0;

	for(int i = 1; i < n; ++i)
	{
		if(i + z[i] - 1 == n - 1)
		{
			if(z[i] <= zmx)
			{
				cout << str.substr(i, z[i]) << endl;

				return;
			}
		}

		zmx = max(zmx, z[i]);
	}

	cout << "Just a legend" << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}