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

	ll n;
	cin >> n;
	ll out = 0;
	if (n < 4) {
		if (n == 1) cout << 3 << endl;
		else if (n == 2) cout << 5 << endl;
		else if (n == 3) cout << 7 << endl;
	} else {
		n -= 4;
		out = 8 + 4 * (n / 3);
		n %= 3;
		if (n == 1) out += 1;
		else if (n == 2) out += 3;
		cout << out << endl;
	}
}