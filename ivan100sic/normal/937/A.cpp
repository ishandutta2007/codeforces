#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, z;
int a[666];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		a[x]++;
	}

	for (int i=1; i<=600; i++)
		if (a[i] > 0)
			z++;
	cout << z << '\n';
}