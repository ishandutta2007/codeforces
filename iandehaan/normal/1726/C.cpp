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
		string s;
		cin >> s;
		int out = 1;
		rep(i, 0, sz(s)-1) {
			if (s[i] == ')' && s[i+1] == ')') out++;
		}
		cout << out << '\n';
	}
}