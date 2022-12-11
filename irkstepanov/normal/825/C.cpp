
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n;
	ll k;
	cin >> n >> k;

	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(all(a));

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		while (2 * k < a[i]) {
			k *= 2;
			++ans;
		}
		k = max(k, a[i]);
	}

	cout << ans << "\n";
		
}