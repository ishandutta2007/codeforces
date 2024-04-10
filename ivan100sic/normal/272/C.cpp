#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r;
	ll v;
};

basic_string<seg> s;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		s += seg{i, i, x};
	}
	reverse(s.begin(), s.end());

	cin >> m;
	while (m--) {
		int w, h;
		cin >> w >> h;
		ll hmax = 0;
		while (1) {
			hmax = max(hmax, s.back().v);
			if (s.back().r == w) {
				s.pop_back();
				break;
			}
			else if (s.back().r > w) {
				s.back().l = w+1;
				break;
			} else {
				s.pop_back();
			}
		}
		cout << hmax << '\n';
		s += seg{1, w, h+hmax};
	}
}