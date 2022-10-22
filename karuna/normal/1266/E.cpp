#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;

int N, Q;
ll A[200020], ans;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i=1; i<=N; i++) cin >> A[i], ans += A[i];

	cin >> Q;
	map<pll, ll> mp;

	while (Q--) {
		ll t, s, u; cin >> t >> s >> u;

		if (mp[{t, s}] == 0) {
			mp[{t, s}] = u;
			A[u]--;

			if (A[u]>=0) --ans;
		}
		else {
			if (u==0) {
				u = mp[{t, s}];
				A[u]++;
				if (A[u]>0) ++ans;
				mp[{t, s}] = 0;
			}
			else {
				int tmp = mp[{t, s}];
				A[tmp]++;
				if (A[tmp]>0) ++ans;

				mp[{t, s}] = u;
				A[u]--;
				if (A[u]>=0) --ans;
			}
		}

		cout << ans << '\n';
	}
}