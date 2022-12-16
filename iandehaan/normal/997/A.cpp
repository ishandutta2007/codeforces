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
	ll x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	ll numzero = 0;
	rep(i, 0, n) {
		if (s[i] == '0') {
			if (i == 0 || s[i-1] != '0') numzero++;
		}
	}

	cout << max((ll)0, min(numzero*y, (numzero-1)*x+y));
}