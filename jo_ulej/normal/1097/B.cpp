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

const ll mod = 1e7 + 9;

void solve()
{
	int n;
	vector<int> arr;

	cin >> n;
	arr.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	for(int s = 0; s < (1 << n); ++s)
	{
		int sum = 0;

		for(int j = 0; j < n; ++j)
		{
			if(s & (1 << j))
				sum = (sum - arr[j]) % 360;
			else
				sum = (sum + arr[j]) % 360;
		}

		if(sum == 0)
		{
			cout << "YES" << endl;

			return;
		}
	}

	cout << "NO" << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}