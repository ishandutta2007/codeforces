#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll Q, N, x=1;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> Q;
	for (int i=0; i<37; i++) x*=3;
	while (Q--) {
		cin >> N;

		ll ans = 0, tmp = x, cnt = 37;
		bool chk[40]; memset(chk, false, sizeof chk);
		while (tmp) {
			if (ans + tmp < N) {
				ans += tmp; chk[cnt] = true;
			}
			--cnt;
			tmp/=3;
		}

		tmp = 1;
		for (int i=0; i<=38; i++) {
			if (chk[i]) ans -= tmp;
			else { ans += tmp; break; }
			tmp *= 3;
		}

		cout << ans << '\n';
	}
}