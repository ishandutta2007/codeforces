#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(const vector<ll>& a) {
	ll ret = 0;
	ll last = 0;
	for (ll val : a) {
		ll cnt = (max(last + 1, val) + val - 1) / val;
		ret += cnt;
		last = cnt * val;
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll ret = 1e16;
	for (int i = 0; i < n; ++i) {
		vector<ll> b(a.begin(), a.begin() + i);
		reverse(b.begin(), b.end());
		vector<ll> c(a.begin() + i + 1, a.end());
		ret = min(ret, solve(b) + solve(c));
		if (ret == 8)
			printf("HERE\n");
	}
	cout << ret << endl;
	return 0;
}