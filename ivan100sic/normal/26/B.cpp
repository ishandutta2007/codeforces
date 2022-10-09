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
	int p=0, l=0;
	for (char x : s) {
		if (x == '(')
			p++;
		else if (x == ')') {
			if (p > 0) {
				p--;
				l += 2;
			}
		}
	}
	cout << l << '\n';
}