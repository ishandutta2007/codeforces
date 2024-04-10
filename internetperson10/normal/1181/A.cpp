#include <bits/stdc++.h>

using namespace std;

int main() {
	long long int x, y, n;
	cin >> x >> y >> n;
	cout << (x+y)/n << ' ';
	if(((x%n)+(y%n)>=n)) cout << min(n-(x%n), n-(y%n)) << '\n';
	else cout << 0 << '\n';
}