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
	int n, k;
	vector<ll> a;
	string s;

	cin >> n >> k;
	a.resize(n);

	for(auto& el: a)
		cin >> el;

	cin >> s;

	ll ans = 0;

	for(int i = 0; i < n;)
	{
		vector<ll> temp;
		int j = i;
		temp.push_back(a[i]);

		while(j + 1 < n && s[j + 1] == s[i])
		{
			++j;
			temp.push_back(a[j]);
		}

		sort(temp.rbegin(), temp.rend());

		for(int idx = 0; idx < k && idx < temp.size(); ++idx)
			ans += temp[idx];

		DBG(i); DBG(j);

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