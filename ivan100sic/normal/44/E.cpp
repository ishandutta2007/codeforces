#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, x, y;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k >> x >> y >> s;
	n = s.size();
	if (n > y*k || n < x*k) {
		cout << "No solution\n";
		return 0;
	}
	for (int i=0; i<k; i++) {
		cout << s.substr(n*i/k, n*(i+1)/k - n*i/k) << '\n';
	}
}