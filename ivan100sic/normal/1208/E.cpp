#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int w, n;
int c[1000005];
int cp[1000005], cb[1000005];

ll sol[1000005];
ll zsol[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> w;
	while (n--) {
		int m;
		cin >> m;
		for (int i=0; i<m; i++) {
			cin >> c[i];
		}
		
		if (2*m <= w) {
			cb[m] = cp[0] = -2e9;
			for (int i=0; i<m; i++) {
				cp[i+1] = max(cp[i], c[i]);
			}
			for (int i=m-1; i>=0; i--)
				cb[i] = max(cb[i+1], c[i]);

			for (int i=0; i<m; i++) {
				sol[i] += max(0, cp[i+1]);
			}
			for (int i=w-m; i<w; i++) {
				// i = w-1 => uzimam samo zadnji tj. cb[m-1]
				sol[i] += max(0, cb[i-w+m]);
			}
			if (cp[m] > 0) {
				zsol[m] += cp[m];
				zsol[w-m] -= cp[m];
			}
		} else {
			// events & multiset
			multiset<int> ms;
			for (int i=0; i<w; i++) {
				if (i < m) {
					ms.insert(c[i]);
				}
				int j = i-(w-m)-1;
				if (j >= 0) {
					ms.erase(ms.find(c[j]));
				}
				int t = *ms.rbegin();
				if (i < w-m || i >= m)
					t = max(t, 0);
				sol[i] += t;
			}
		}
	}
	for (int i=0; i<w; i++)
		zsol[i+1] += zsol[i];
	for (int i=0; i<w; i++) {
		cout << sol[i] + zsol[i] << " \n"[i == w-1];
	}
}