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
	int n;
	vector<int> arr, dp, suff;

	cin >> n;
	arr.resize(n);
	dp.resize(n);
	suff.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	
	suff[n - 1] = arr[n - 1];

	for(int i = n - 2; i >= 0; --i)
		suff[i] = arr[i] + suff[i + 1];

	dp[n - 1] = arr[n - 1];

	for(int i = n - 2; i >= 0; --i)
		dp[i] = max(dp[i + 1], suff[i + 1] - dp[i + 1] + arr[i]);

	cout << suff[0] - dp[0] << " " << dp[0] << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}