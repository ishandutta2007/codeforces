#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
basic_string<int> a;
ll dp[1000005];

bool kolin(int x) {
	int b[7];
	copy(a.end()-6, a.end(), b);
	b[6] = x;
	if (is_sorted(b, b+7))
		return true;
	reverse(b, b+7);
	return is_sorted(b, b+7);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		while (k >= 6 && kolin(x)) {
			a[k-4] = a[k-3];
			a[k-3] = a[k-2];
			a[k-2] = a[k-1];
			a.pop_back();
			k--;
		}
		a += x;
		k++;
	}

	for (int i=0; i<k; i++) {
		int lo = a[i];
		int hi = a[i];
		for (int j=1; j<=40 && i+j <= k; j++) {
			lo = min(lo, a[i+j-1]);
			hi = max(hi, a[i+j-1]);
			dp[i+j] = max(dp[i+j], dp[i] + hi - lo);
		}
	}
	cout << dp[k] << '\n';
}