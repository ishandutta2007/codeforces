#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool vis[5002][5002];
ll cac[5002][5002];
ll nums[300005];
int n;
int k;
int s;

ll dp(int at, int rem)
{
	int wh = (at+s-1)/s;
	if (at == n) return 0ll;
	if (vis[wh][rem]) return cac[wh][rem];
	vis[wh][rem] = true;
	cac[wh][rem] = 1ll << 62;
	if (at+s+rem*(s-1) <= n) cac[wh][rem] = min(cac[wh][rem], nums[at+s-1]-nums[at]+dp(at+s, rem));
	if (rem) cac[wh][rem] = min(cac[wh][rem], nums[at+s-2]-nums[at]+dp(at+s-1, rem-1));
	return cac[wh][rem];
}

int main()
{
	cin.sync_with_stdio(0);
	cin >> n >> k;
	s = (n+k-1) / k;
	for (int i = 0;i < n;i++) cin >> nums[i];
	sort(nums, nums+n);
	cout << dp(0, (k-n%k)%k) << "\n";
	return 0;
}