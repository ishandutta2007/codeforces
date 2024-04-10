#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool good(basic_string<int> a) {
	basic_string<int> st;
	int n = a.size(), nx = 0;
	for (int i=0; i<=n; i++) {
		if (i < n && a[i] == nx) {
			nx++;
		} else if (st.size() && st.back() == nx) {
			st.pop_back();
			nx++;
			i--;
		} else if (i < n) {
			st += a[i];
		}
	}
	return nx == n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	basic_string<int> a(k, 0), ima(n, 0);
	for (int i=0; i<k; i++) {
		cin >> a[i];
		a[i]--;
		ima[a[i]] = 1;
	}

	int l=0, r=0;
	for (int i=0; i<n; i++) {
		if (!ima[i] && l == r) {
			l = i;
			r = i+1;
		} else if (!ima[i]) {
			r++;
		} else if (ima[i] && l < r) {
			for (int j=r-1; j>=l; j--)
				a += j;
			l = r = 0;
		}
	}
	if (l < r) {
		for (int j=r-1; j>=l; j--)
			a += j;
	}
	if (good(a)) {
		for (int x : a)
			cout << x+1 << ' ';
		cout << '\n';
	} else {
		cout << "-1\n";
	}



}