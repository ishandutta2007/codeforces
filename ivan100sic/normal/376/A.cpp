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

	string s;
	cin >> s;
	ll w = 0;
	ll p = find(s.begin(), s.end(), '^') - s.begin();
	for (int i=0; i<(int)s.size(); i++) {
		if (isdigit(s[i])) {
			w += (p-i) * (s[i] - '0');
		}
	}
	if (w > 0)
		cout << "left\n";
	else if (w == 0)
		cout << "balance\n";
	else
		cout << "right\n";
}