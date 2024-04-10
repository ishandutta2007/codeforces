#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, q;
vector<int> pos[200005];
int a[200005], b[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
		pos[a[i]].push_back(i);
	}

	cin >> q;
	while (q--) {
		vector<int> c;
		int cc;
		cin >> cc;
		c.resize(cc);
		for (int& x : c) {
			cin >> x;
		}

		int o = n+1;
		{
			int l = 1, r = n;
			while (l <= r) {
				int m = (l+r) >> 1;

				int br = 0;
				for (int x : c) {
					br += pos[x].end() - lower_bound(pos[x].begin(), pos[x].end(), m);
				}

				if (br == n-m+1) {
					// ok, probaj veci
					o = m;
					r = m-1;
				} else {
					l = m+1;
				}
			}
		}

		o--;
		if (o == 0) {
			cout << "0 0\n";
			continue;
		}

		int aoo = a[o];

		c.push_back(aoo);
		{
			int l = 1, r = o;
			while (l <= r) {
				int m = (l+r) >> 1;

				int br = 0;
				for (int x : c) {
					br += pos[x].end() - lower_bound(pos[x].begin(), pos[x].end(), m);
				}

				if (br == n-m+1) {
					// ok, probaj veci
					o = m;
					r = m-1;
				} else {
					l = m+1;
				}
			}
		}

		o = *lower_bound(pos[aoo].begin(), pos[aoo].end(), o);
		cout << a[o] << ' ' << b[o] << '\n';
		
	}

}