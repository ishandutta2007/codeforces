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
	int n, x, y;
	vector<int> arr, weak;

	cin >> n >> x >> y;
	arr.resize(n);

	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	if(x > y)
	{
		cout << n << endl;

		return;
	}

	for(auto el: arr)
		if(el <= x)
			weak.push_back(el);

	int ans = 0;

	while(!weak.empty())
	{
		sort(weak.begin(), weak.end());

		weak[0] -= x;

		if(weak[0] <= 0)
		{
			++ans;
			weak.erase(weak.begin());
		}

		if(weak.empty())
			break;

		weak[weak.size() - 1] += y;

		if(weak[weak.size() - 1] > x)
			weak.pop_back();
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}