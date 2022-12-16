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

	int n;
	cin >> n;
	string s;
	cin >> s;

	int out = 0;
	for (char c : s) if (c == '1') out++;

	int a[n];
	int b[n];
	rep(i, 0, n) cin >> a[i] >> b[i];

	int numiters = 10'000;
	int tm = 0;
	while (numiters--) {
		tm++;
		rep(i, 0, n) {
			if (tm < b[i]) continue;
			if ((tm-b[i]) % a[i] == 0) {
				if (s[i] == '1') s[i] = '0';
				else s[i] = '1';
			}
		}

		int amt = 0;
		rep(i, 0, n) if (s[i] == '1') amt++;
		out = max(out, amt);
	}
	cout << out << endl;
}