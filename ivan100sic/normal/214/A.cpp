#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, z=0;
	cin >> n >> m;
	for (int a=0; a<=1000; a++)
		for (int b=0; b<=1000; b++)
			z += a*a+b == n && a+b*b == m;
	cout << z << '\n';
}