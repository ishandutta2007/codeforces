#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
	two plus xor of third and min element
*/

int n;
int a[111];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	cout << 2 + (a[3] ^ *min_element(a+1, a+n+1)) << '\n';
}