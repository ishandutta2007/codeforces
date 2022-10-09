#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, z;
int b[31];
int a[31];

bool get(int x) {
	if (x == 31)
		return false;

	if (a[x]) {
		a[x]--;
		return true;
	}

	if (get(x+1)) {
		a[x]++;
		return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		for (int j=0; j<=30; j++)
			if (x & (1 << j))
				a[j]++;
	}
	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		b[x]++;
	}

	for (int i=0; i<=30; i++)
		while (b[i]--)
			z += get(i);

	cout << z << '\n';
}