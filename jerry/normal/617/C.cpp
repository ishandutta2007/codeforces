#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> all[2005], p, q;
int n;

ll dis(pair<ll, ll> a, pair<ll, ll> b)
{
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

ll foo(int i)
{
	if (i == n) return 0;
	ll ans = dis(all[i], q);
	for (i++;i < n;i++)
		ans = max(ans, dis(all[i], q));
	return ans;
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> p.first >> p.second >> q.first >> q.second;
	for (int i = 0;i < n;i++) cin >> all[i].first >> all[i].second;
	sort(all, all+n, [](pair<ll, ll> a, pair<ll, ll> b) -> bool {
		return dis(a, p) < dis(b, p);
	});
	ll ans = foo(0);
	for (int i = 0;i < n;i++)
	{
		ll alt = dis(all[i], p)+foo(i+1);
		if (alt < ans) ans = alt;
	}
	cout << ans << endl;
	return 0;
}