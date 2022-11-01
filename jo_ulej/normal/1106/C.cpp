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

void solve()
{
	vector<ll> arr;
	int n;

	cin >> n;
	arr.resize(n);

	for(auto& el: arr)
		cin >> el;

	sort(arr.begin(), arr.end());

	ll ans = 0;
	int i = 0;
	int j = n - 1;

	while(i < j)
	{
		ans += (arr[i] + arr[j]) * (arr[i] + arr[j]);

		++i;
		--j;
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}