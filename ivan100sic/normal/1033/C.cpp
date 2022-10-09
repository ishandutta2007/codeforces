#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int w[100005];
int a[100005];

int resi(int x) {
	if (w[x])
		return w[x];

	w[x] = 2;
	for (int i = x + a[x]; i<=n; i+=a[x]) {
		if (a[i] > a[x]) {
			if (resi(i) == 2)
				w[x] = 1;
		}
	}

	for (int i = x - a[x]; i>=1; i-=a[x]) {
		if (a[i] > a[x]) {
			if (resi(i) == 2)
				w[x] = 1;
		}
	}

	return w[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<=n; i++)
		cout << (char)(resi(i) + 'A' - 1);
	cout << '\n';
}