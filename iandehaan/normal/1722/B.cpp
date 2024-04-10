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
		int n;
		cin >> n;

		string s, t;
		cin >> s >> t;
		string out = "YES";
		rep(i, 0, n) {
			if (s[i] == t[i]) continue;

			if (s[i] == 'G' && t[i] == 'B') continue;
			if (s[i] == 'B' && t[i] == 'G') continue;
			out = "NO";
		}
		cout << out << endl;
	}
}