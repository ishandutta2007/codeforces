#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, a[1005], b[1005];

// boze sacuvaj, da li sam ja normalan????

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	int w = 0;
	for (int i=0; i<m; i++)
		cin >> a[i], w += a[i];
	sort(a, a+m, greater<int>());
	int z = 0, u = 0, v = 0, r = w - n;	
	for (int i=0; i<m; i++) {
		z += a[i]*(a[i]+1) / 2;
		int q = min(r, a[i]);
		u += q*(q+1)/2;
		r -= q;
	}
	for (int i=0; i<w-n; i++) {
		int k = -1;
		for (int j=0; j<m; j++) {
			if (b[j] < a[j] && (k == -1 || b[j] < b[k]))
				k = j;
		}
		v += ++b[k];
	}

	cout << z-v << ' ' << z-u << '\n';
}