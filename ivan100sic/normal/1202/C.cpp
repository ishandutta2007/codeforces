#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<int> ci;

ci dir(char x) {
	if (x == 'W') return {1, 0};
	if (x == 'A') return {0, 1};
	if (x == 'S') return {-1, 0};
	if (x == 'D') return {0, -1};
	return {0, 0};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string st;
		cin >> st;
		int n = st.size();
		vector<ci> a(n);
		vector<int> p(n+1), q(n+1), r(n+1), s(n+1);
		for (int i=0; i<n; i++) {
			a[i] = dir(st[i]);
		}
		for (int i=n-1; i>=0; i--) {
			p[i] = p[i+1] + a[i].real();
			q[i] = q[i+1] + a[i].real();
			r[i] = r[i+1] + a[i].imag();
			s[i] = s[i+1] + a[i].imag();

			p[i] = min(p[i], 0);
			q[i] = max(q[i], 0);
			r[i] = min(r[i], 0);
			s[i] = max(s[i], 0);
		}

		ll sol = (q[0]-p[0]+1ll) * (s[0]-r[0]+1);

		// cerr << "init " << sol << '\n';

		int pp = 0, qq = 0, rr = 0, ss = 0;

		auto check = [&](int x, int y, int i) {
			int ppp = min(pp, p[i]+x);
			int qqq = max(qq, q[i]+x);
			int rrr = min(rr, r[i]+y);
			int sss = max(ss, s[i]+y);
			sol = min(sol, (qqq-ppp+1ll)*(sss-rrr+1));
		};

		auto check2 = [&](int x, int y, int i) {
			int ppp = pp, qqq = qq, rrr = rr, sss = ss;

			{
				x++;
				pp = min(pp, x);
				qq = max(qq, x);
				rr = min(rr, y);
				ss = max(ss, y);
				check(x, y, i);
				pp = ppp;
				qq = qqq;
				rr = rrr;
				ss = sss;
				x--;
			}

			{
				x--;
				pp = min(pp, x);
				qq = max(qq, x);
				rr = min(rr, y);
				ss = max(ss, y);
				check(x, y, i);
				pp = ppp;
				qq = qqq;
				rr = rrr;
				ss = sss;
				x++;
			}

			{
				y++;
				pp = min(pp, x);
				qq = max(qq, x);
				rr = min(rr, y);
				ss = max(ss, y);
				check(x, y, i);
				pp = ppp;
				qq = qqq;
				rr = rrr;
				ss = sss;
				y--;
			}

			{
				y--;
				pp = min(pp, x);
				qq = max(qq, x);
				rr = min(rr, y);
				ss = max(ss, y);
				check(x, y, i);
				pp = ppp;
				qq = qqq;
				rr = rrr;
				ss = sss;
				y++;
			}
				
		};

		int x=0, y=0;
		for (int i=0; i<n; i++) {
			check2(x, y, i);
			x += a[i].real();
			y += a[i].imag();
			pp = min(pp, x);
			qq = max(qq, x);
			rr = min(rr, y);
			ss = max(ss, y);
		}
		check2(x, y, n);

		cout << sol << '\n';
	}
}