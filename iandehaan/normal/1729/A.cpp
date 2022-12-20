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
		ll a, b, c;
		cin >> a >> b >> c;
		ll amt1 = abs(a-1);
		ll amt2 = abs(b-c) + abs(c-1);
		if (amt1 == amt2) cout << 3 << '\n';
		else if (amt1 > amt2) cout << 2 << '\n';
		else cout << 1 << '\n';
		//cout << min(abs(a-1), abs(b-c)+abs(c-1)) << '\n';
	}
}