#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int nmax = int(3e6) + 100;
ll pref[nmax];
ll easy[nmax];
int cnt[nmax];

ll getSum(int l, int r) {
	ll ans = pref[r];
	if (l) {
		ans -= pref[l - 1];
	}
	ll val = easy[r];
	if (l) {
		val -= easy[l - 1];
	}
	ans -= ll(nmax - 1 - r) * val;
	return ans;
}

ll getEasy(int l, int r) {
	ll ans = easy[r];
	if (l) {
		ans -= easy[l - 1];
	}
	return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n;
	cin >> n;
	ll x, y;
	cin >> x >> y;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cnt[a];
		++easy[a];
	}
	for (int i = 1; i < nmax; ++i) {
		easy[i] += easy[i - 1];
	}
	ll d = nmax - 1;
	for (int i = 0; i < nmax; ++i) {
		pref[i] = ll(cnt[i]) * d;
		if (i) {
			pref[i] += pref[i - 1];
		}
		--d;
	}

	ll f = x / y;
	ll ans = ll(n) * x;
	for (int p = 2; p < nmax; ++p) {
		ll sum = 0;
		for (int i = 1; ; ++i) {
			if (p * i - f > p * (i - 1)) {
				sum += getSum(p * i - f, p * i) * y;
				sum += getEasy(p * (i - 1) + 1, p * i - f - 1) * x;
			} else {
				sum += getSum(p * (i - 1) + 1, p * i) * y;
			}
			if (i * p >= int(1e6)) {
				break;
			}
		}
		if (sum == -23) {
			cout << p << endl;
		}
		ans = min(ans, sum);
	}

	cout << ans << "\n";

}