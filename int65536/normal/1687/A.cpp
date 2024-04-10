#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, s, t) for (int i = static_cast<int>(s); i < static_cast<int>(t); ++i)
#define REP(i, n) for (int i = 0; i < static_cast<int>(n); ++i)

void one_case()
{
	ll n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	REP(i, n) {
		cin >> a[i];
	}
	vector<ll> s(n + 1);
	REP(i, n) {
		s[i + 1] = s[i] + a[i];
	}
	ll ret = 0;
	if (k <= n) {
		REP(i, n - k + 1) {
			ret = max(ret, s[i + k] - s[i]);
		}
		ret += k * (k - 1) / 2;
	} else {
		ret += s[n];
		ret += k * n;
		ret -= (ll)n * (n + 1) / 2;
	}
	cout << ret << endl;
}
int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		one_case();
	}
	return 0;
}