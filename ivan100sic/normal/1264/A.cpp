#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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
		int last = -1;
		vector<int> a;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			if (x == last)
				a.back()++;
			else
				a.push_back(1);
			last = x;
		}
		int ostalo = n;
		while (2 * ostalo > n) {
			ostalo -= a.back();
			a.pop_back();
		}

		bool no = false;
		int g=0, s=0, b=0;

		if (a.size() == 0) {
			no = true;
		} else {
			g = a[0];
			int l = 1;
			while (l < (int)a.size() && g >= s)
				s += a[l++];
			while (l < (int)a.size())
				b += a[l++];

			if (g < s && g < b && g && s && b)
				;
			else
				no = true;
		}

		if (no)
			cout << "0 0 0\n";
		else
			cout << g << ' ' << s << ' ' << b << '\n';
	}
}