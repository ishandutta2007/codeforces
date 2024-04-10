#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;
int a[N];
pair<int, int> b[N];
int pref[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i].first >> b[i].second;
	sort(b + 1, b + m + 1);
	for(int i = 1; i <= m; i++)
		pref[i] = pref[i - 1] + b[i].second;
	for(int i = 1; i <= n; i++)
	{
		int x = a[i];
		pair<int, int> p = {x + 1, 0};
		auto idx = lower_bound(b + 1, b + m + 1, p) - b;
		idx--;
		int ans = pref[idx];
		cout << ans << " ";
	}
	return 0;
}