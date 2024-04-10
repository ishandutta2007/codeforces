#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

bool on_seg(int p, int a, int b)
{
	return p >= a && p <= b;
}

bool intersect(int a, int b, int c, int d)
{
	return on_seg(a, c, d) || on_seg(b, c, d) || on_seg(c, a, b) || on_seg(d, a, b);
}

int main()
{

	int n;
	cin >> n;

	vector<int> l(n), r(n);

	for (int i = 0; i < n; ++i) {
		int s, d;
		cin >> s >> d;
		int lf = s, rg = s + d - 1;
		bool inter = false;
		for (int j = 0; j < i; ++j) {
			if (intersect(l[j], r[j], lf, rg)) {
				inter = true;
			}
		}
		if (!inter) {
			l[i] = lf;
			r[i] = rg;
			continue;
		}
		int pos = 1;
		while (true) {
			inter = false;
			for (int j = 0; j < i; ++j) {
				if (intersect(l[j], r[j], pos, pos + d - 1)) {
					inter = true;
					pos = r[j] + 1;
					break;
				}
			}
			if (inter) {
				continue;
			} else {
				l[i] = pos;
				r[i] = pos + d - 1;
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << l[i] << " " << r[i] << "\n";
	}

}