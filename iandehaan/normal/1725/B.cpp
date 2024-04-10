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
	ll d;
	cin >> n >> d;
	ll a[n];
	rep(i, 0, n) cin >> a[i];
	sort(a, a+n);

	int p1 = 0;
	int p2 = n-1;
	int out = 0;
	ll curr = 0;
	while (true) {
		if (p1 > p2) break;
		if (curr > d) {
			out++;
			p2--;
			curr = 0;
			continue;
		}

		if (curr == 0) {
			curr += a[p2];
		} else {
			curr += a[p2];
			p1++;
		}
	}
	cout << out << endl;
}