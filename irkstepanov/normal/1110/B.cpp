#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	vector<int> d;
	for (int i = 1; i < n; ++i) {
		d.pb(b[i] - b[i - 1]);
	}
	sort(all(d));
	reverse(all(d));
	--k;

	ll ans = b.back() - b[0] + 1;
	for (int i = 0; i < k; ++i) {
		ans -= d[i] - 1;
	}
	cout << ans << "\n";


}