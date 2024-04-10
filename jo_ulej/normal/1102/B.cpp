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

bool has[5100][5100];

void solve()
{
	int n, k;
	vector<int> arr, ans;

	cin >> n >> k;
	arr.resize(n);
	ans.resize(n, -1);

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	for(int color = 1; color <= k; ++color)
	{
		for(int i = 0; i < n; ++i)
		{
			if(!has[arr[i]][color] && ans[i] == -1)
			{
				has[arr[i]][color] = true;
				ans[i] = color;
				break;
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		if(ans[i] != -1)
			continue;

		for(int color = 1; color <= k; ++color)
		{
			if(!has[arr[i]][color])
			{
				has[arr[i]][color] = true;
				ans[i] = color;
				break;
			}
		}
	}

	for(auto el: ans)
	{
		if(el == -1)
		{
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;

	for(auto el: ans)
		cout << el << " ";
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}