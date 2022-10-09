#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;

template<class T>
int krug(T& a, int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n)
		return 0;
	if (a[x][y] == 'o')
		return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	vector<string> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	int ok = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int z = 0;
			z += krug(a, i+1, j);
			z += krug(a, i-1, j);
			z += krug(a, i, j+1);
			z += krug(a, i, j-1);
			if (z % 2)
				ok = 0;
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}