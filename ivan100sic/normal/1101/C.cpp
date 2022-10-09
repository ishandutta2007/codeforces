#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r, idx;
	bool operator< (seg b) {
		return l < b.l;
	}
};

int ans[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		basic_string<seg> b;
		for (int i=0; i<n; i++) {
			int l, r;
			cin >> l >> r;
			b += {l, r, i};
		}
		sort(b.begin(), b.end());
		int idx = -1;
		int pr = -1;
		for (int i=0; i<n; i++) {
			if (i > 0 && pr < b[i].l) {
				idx = i;
				break;
			}
			pr = max(pr, b[i].r);
		}



		if (idx == -1) {
			cout << "-1\n";
		} else {
			for (int i=0; i<n; i++)
				ans[b[i].idx] = 1 + (i < idx);
			for (int i=0; i<n; i++)
				cout << ans[i] << " \n"[i == n-1];
		}
	}
}