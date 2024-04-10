#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int l[1000005], r[1000005], a[1000005];

int cl[1000005], cr[1000005];
basic_string<int> u, v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		cl[x]++;
		cr[y]++;
		l[y] = x;
		r[x] = y;
	}

	if (n % 2 == 0) {
		for (int i=0, j=1; j < n; i=r[i], j+=2)
			a[j] = r[i];

		for (int i=0, j=n-2; j >= 0; i=l[i], j-=2)
			a[j] = l[i];
	} else {
		for (int i=0, j=1; j < n; i=r[i], j+=2)
			a[j] = r[i];

		// broj koji se javlja samo sa leve strane i to jednom
		int k = -1;
		for (int i=1; i<=1000000; i++) {
			if (cl[i] == 1 && cr[i] == 0) {
				k = i;
			}
		}

		// cerr << "k: " << k << '\n';

		for (int i=k, j=0; j < n; i=r[i], j+=2)
			a[j] = i;
	}

	

	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}