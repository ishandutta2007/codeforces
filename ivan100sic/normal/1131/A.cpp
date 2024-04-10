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

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int z = 4+2*(b+d)+2*max(a, c);
	cout << z << '\n';
}