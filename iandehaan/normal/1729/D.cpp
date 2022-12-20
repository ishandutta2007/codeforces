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

#define MAXN 100'010

pair<ll, ll> b[MAXN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi pos;
		vi neg;
		rep(i, 0, n) cin >> b[i].first;
		rep(i, 0, n) cin >> b[i].second;
		rep(i, 0, n) {
			if ((b[i].first - b[i].second) <= 0) neg.pb(b[i].second - b[i].first);
			else pos.pb(b[i].first - b[i].second);

			//cout <<  b[i].first - b[i].second << ' ';
		}
		//cout << endl;
		sort(all(pos));
		sort(all(neg));

		int out = 0;
		int negi = 0;
		//cout << sz(pos) << endl;
		rep(posi, 0, sz(pos)) {
			//cout << " iter  " <<posi << ' ' << negi << endl;
			if (negi >= sz(neg)) break;

			//cout << pos[posi] << ' ' << neg[negi] << endl;

			if (pos[posi] <= neg[negi]) {
				// match them
				out++;
				negi++;
			} else {
				if (negi + 1 >= sz(neg)) break;
				else {
					// match two neg together
					out++;
					negi += 2;
					posi--;
				}
			}
		}
		while (true) {
			if (negi+1 >= sz(neg)) break;
			out++;
			negi += 2;
		}
		cout << out << '\n';
	}
}