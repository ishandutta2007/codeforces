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
		vi pos[26];
		rep(i, 0, n) {
			pos[s[i]-'a'].pb(i);
		}

		vi out;
		if (s[0] <= s[n-1]) {
			for (int i = s[0]-'a'; i <= s[n-1]-'a'; i++) {
				for (int x : pos[i]) out.pb(x);
			}
		} else {
			for (int i = s[0]-'a'; i >= s[n-1]-'a'; i--) {
				for (int x : pos[i]) out.pb(x);
			}
		}

		cout << abs(s[0]-s[n-1]) << ' ' << sz(out) << '\n';
		for (int x : out) cout << x+1 << ' ';
		cout << '\n';

		//if (s[0] > s[n-1]) 
	}
}