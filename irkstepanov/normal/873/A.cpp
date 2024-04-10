#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	int n, k, x;
	cin >> n >> k >> x;

	int ans = 0;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	reverse(all(a));

	for (int i = 0; i < k; ++i) {
		ans += x;
	}
	for (int i = k; i < n; ++i) {
		ans += a[i];
	}

	cout << ans << "\n";

}