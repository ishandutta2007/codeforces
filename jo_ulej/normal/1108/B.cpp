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
	vector<int> arr;
	int n;

	cin >> n;
	arr.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			vector<int> narr;

			for(int d = 1; d * d <= arr[i]; ++d)
			{
				if(arr[i] % d == 0)
				{
					narr.push_back(d);

					if(d != arr[i] / d)
						narr.push_back(arr[i] / d);
				}
			}

			for(int d = 1; d * d <= arr[j]; ++d)
			{
				if(arr[j] % d == 0)
				{
					narr.push_back(d);

					if(d != arr[j] / d)
						narr.push_back(arr[j] / d);
				}
			}

			sort(narr.begin(), narr.end());

			if(narr == arr)
			{
				cout << arr[i] << " " << arr[j] << endl;

				return;
			}
		}
	}
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}