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

ll mod = 1e9 + 7;

int rnd() {
	static ll x = 1348971;

	int c = x;
	x = (x*984983)%mod;
	return c;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	srand(time(NULL));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		while (true) {
			set<int> used;
			
			int amt = 0;
			vector<int> out;
			while (sz(out) < n-1) {
				//cerr << sz(out) << endl;
				int x = rnd();
				x++;
				if (x <= 0) continue;
				if (used.count(x) > 0) continue;

				//cerr << x << endl;

				used.insert(x);
				out.pb(x);
			}
			//err << "done gen" << endl;

			int lor = 0;
			int ror = 0;

			rep(i, 0, sz(out)) {
				if (i % 2 == 0) lor ^= out[i];
				else ror ^= out[i];
			}

			int lastitem = lor ^ ror;
			if (used.count(lastitem)) continue;

			out.pb(lastitem);
			for (int x : out) cout << x << ' ';
			cout << endl;
			break;
		}

	}
}