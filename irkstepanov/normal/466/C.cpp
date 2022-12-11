#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;
typedef long long ll;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> a(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	if (sum % 3) {
		cout << "0\n";
		return 0;
	}

	sum /= 3;

	vector<ll> suff(n);
	ll curr = 0;
	for (int i = n - 1; i >= 0; --i) {
		curr += a[i];
		if (i != n - 1) {
			suff[i] = suff[i + 1];
		}
		if (curr == sum) {
			++suff[i];
		}
	}

	ll ans = 0;
	curr = 0;
	for (int i = 0; i < n - 2; ++i) {
		curr += a[i];
		if (curr == sum) {
			ans += suff[i + 2];
		}
	}
	cout << ans << "\n";

}