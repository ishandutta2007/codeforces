#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005];
int l[305], r[305];

int q[705], qlo[705], qhi[705], k;

bool ins(int segment, int pos) {
	return l[segment] <= pos && pos < r[segment];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++) {
		cin >> l[i] >> r[i];
		l[i]--;
		q[k++] = l[i];
		q[k++] = r[i];
	}
	q[k++] = 0;
	q[k++] = n;
	sort(q, q+k);
	k = unique(q, q+k) - q;
	for (int i=0; i<k-1; i++) {
		int u = 1123123123, v = -1123123123;
		for (int j=q[i]; j<q[i+1]; j++) {
			u = min(u, a[j]);
			v = max(v, a[j]);
		}
		qlo[i] = u;
		qhi[i] = v;
	}

	int sol = 0;
	basic_string<int> smarate;

	for (int i=0; i<k-1; i++) { // low
		for (int j=0; j<k-1; j++) { // hi
			// ako zahvata j a ne zahvata i, uzmi ga!
			int c = 0;
			basic_string<int> niz;
			for (int x=0; x<m; x++)
				if (ins(x, q[i]) && !ins(x, q[j])) {
					c++;
					niz += x+1;
				}
			int newsol = qhi[j] - qlo[i] + c;
			if (newsol > sol) {
				sol = newsol;
				smarate = niz;
			}
		}
	}

	cout << sol << '\n';
	cout << smarate.size() << '\n';
	for (int x : smarate)
		cout << x << ' ';
	cout << '\n';
}