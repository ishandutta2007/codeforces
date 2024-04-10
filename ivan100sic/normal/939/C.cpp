#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
int s, f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) 
		cin >> a[i];
	cin >> s >> f;
	f--;

	int ppl = 0;
	for (int i=s; i<=f; i++)
		ppl += a[i];
	int opt = ppl, idx = 1;

	// cerr << "1 " << ppl << '\n';

	for (int i=2; i<=n; i++) {
		ppl -= a[f];
		f--;
		if (f == 0) f = n;

		s--;
		if (s == 0) s = n;
		ppl += a[s];

		if (ppl > opt) {
			opt = ppl;
			idx = i;
		}

		// cerr << i << ' ' << ppl << '\n';
	}

	cout << idx << '\n';
}