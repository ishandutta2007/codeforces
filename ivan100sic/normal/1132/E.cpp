#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int DP_HI = 10000;

ll a[9], w, w0;
bool dp[DP_HI];

bool dodaj(int x) {
	bool nesto = 0;
	for (int i=DP_HI-1; i>=x; i--) {
		if (dp[i-x] && !dp[i])
			nesto = dp[i] = 1;
	}
	return nesto;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> w;
	w0 = w;
	dp[0] = 1;

	for (int i=1; i<=8; i++)
		cin >> a[i];

	// rezervisi bar po 64 od svakog za dp
	for (int i=1; i<=8; i++) {
		ll amt = min(64ll, a[i]);
		a[i] -= amt;
		while (amt--)
			dodaj(i);
	}

	// pridji na 256 do cilja greedy
	for (int i=8; i>=1; i--) {
		ll r = max(0ll, w - 256);
		ll amt = min(a[i], r / i);
		a[i] -= amt;
		w -= amt*i;
	}

	// dodaj sve ostale u dp (dok to ima smisla)
	for (int i=1; i<=8; i++) {
		while (a[i] > 0) {
			if (dodaj(i)) {
				a[i]--;
			} else {
				break;
			}
		}
	}

	// nadji dp broj koji je najblizi w
	for (int i=DP_HI-1; i>=0; i--) {
		if (i <= w && dp[i]) {
			cout << w0-(w-i) << '\n';
			return 0;
		}
	}
}