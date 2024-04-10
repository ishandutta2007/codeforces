#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = sz(s);
		int a[n];
		rep(i, 0, sz(s)) a[i] = s[i]-'0';

		int pref[n];
		pref[0] = a[0];
		rep(i, 1, n) pref[i] = pref[i-1] + a[i];

		int w, q;
		cin >> w >> q;

		vi places[9];
		rep(i, 0, n) {
			if (i + w -1 >= n) break;
			int val = pref[i+w-1];
			if (i != 0) val -= pref[i-1];
			val %= 9;
			places[val].pb(i);
		}

		while (q--) {
			int l, r, k;
			cin >> l >> r >> k;
			l--; r--;
			int val = pref[r];
			if (l != 0) val -= pref[l-1];
			val %= 9;

			pii out = mp(-2, -2);

			rep(x, 0, 9) rep(y, 0, 9) {
				if ((x*val + y) % 9 == k) {
					if (x != y) {
						if (sz(places[x]) == 0 || sz(places[y]) == 0) continue;
						int l1 = places[x][0];
						int l2 = places[y][0];
						if ((out == mp(-2, -2)) || 
						   (l1 < out.first) ||
						   (l1 <= out.first && l2 < out.second)) {
							out = mp(l1, l2);
						}
					} else {
						if (sz(places[x]) < 2) continue;
						int l1 = places[x][0];
						int l2 = places[x][1];
						if ((out == mp(-2, -2)) || 
						   (l1 < out.first) ||
						   (l1 <= out.first && l2 < out.second)) {
							out = mp(l1, l2);
						}
					}
				}
			}
			cout << out.first+1 << ' ' << out.second+1 << '\n';
		}


	}
}