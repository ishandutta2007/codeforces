#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll occ[200005];
ll ans;
int n;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++)
	{ int x; cin >> x; occ[--x] = i; }
	for (int at = occ[0], i = 1;i < n;at = occ[i++])
		ans += abs(at-occ[i]);
	cout << ans << endl;
	return 0;
}