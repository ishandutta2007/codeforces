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
	int n, k;
	vector<int> arr;

	cin >> n >> k;
	arr.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	int ans = 0;

	for(int b = 0; b < n; ++b)
	{
		int sm = 0;

		for(int i = 0; i < n; ++i)
			if(abs(i - b) % k != 0)
				sm += arr[i];

		ans = max(ans, abs(sm));
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}