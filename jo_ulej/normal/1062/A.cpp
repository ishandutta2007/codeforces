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

const ll mod = 1e7 + 9;

void solve()
{
	vector<int> arr;
	int n;

	cin >> n;
	arr.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	int ans = 0;

	for(int i = 0; i < n;)
	{
		int j = i;

		while(j + 1 < n && arr[j + 1] - arr[i] == j + 1 - i)
			++j;

		int delta = j - i - 1;

		if(arr[j] == j + 1)
			++delta;

		if(j - i + 1 >= 2)
		{
			if(arr[j - 1] == 999)
				++delta;
		}

		if(delta > 0)
			ans = max(ans, delta);

		DBG(i); DBG(j); DBG(delta);

		i = j + 1;
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

    return 0;
}