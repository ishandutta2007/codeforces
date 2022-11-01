#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll v[500005];
ll c1[500005];
ll c2[500005];
int n;

ll foo(string buf)
{
	for (int i = 1;i <= n;i++) c1[i] = c1[i-1] + (buf[i]=='A'?v[i]:0);
	for (int i = 1;i <= n;i++) c2[i] = c2[i-1] + (buf[i]=='B'?v[i]:0);
	ll ans = 0;
	for (int i = 0;i <= n;i++)
		ans = max(ans, c1[i]+c2[n]-c2[i]);
	return ans;
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> v[i];
	string buf; cin >> buf;
	ll ans = foo(' '+buf);
	reverse(v+1, v+n+1);
	reverse(buf.begin(), buf.end());
	ans = max(ans, foo(' '+buf));
	cout << ans << endl;
	return 0;
}