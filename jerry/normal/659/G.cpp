#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
ll me[1000005], nxt[1000005];
ll h[1000005];
ll ans;
int n;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++) cin >> h[i];
	me[0] = h[0] - 1;
	nxt[0] = min(h[0], h[1]) - 1;
	ans += me[0];
	for (int i = 1;i < n;i++)
	{
		me[i] = (nxt[i-1]*(min(h[i-1], h[i])-1)+h[i]-1) % MOD;
		nxt[i] = (((nxt[i-1]*(min(h[i-1], min(h[i], h[i+1]))-1)) % MOD) + (min(h[i], h[i+1])-1)) % MOD;
		ans += me[i];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}