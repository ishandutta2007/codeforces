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

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string t;
		cin >> t;
		string s;
		int ind = 0;
		while (true) {
			if (ind >= sz(t)) break;

			if (ind + 2 >= sz(t)) {
				// must be single digit
				s.pb('a'+t[ind]-'0'-1);

				ind++;
			} else {
				if (t[ind+2] != '0') {
					// single digit
					s.pb('a'+t[ind]-'0'-1);

					ind++;
				} else {
					if (ind + 3 < sz(t) && t[ind+3] == '0') {
						// must be single digit
						s.pb('a'+t[ind]-'0'-1);

						ind++;
					} else {
						// double digit
						int amt = 10*(t[ind]-'0') + t[ind+1]-'0';
						s.pb('a' + amt-1);
						ind += 3;
					}
				}
			}
		}
		cout << s << '\n';
	}
}