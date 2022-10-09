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
	int x = 0;
	for (char y : s)
		if (y == '7')
			x = 2*x+1;
		else
			x = 2*x;
	cout << x + (1 << s.size()) - 1 << '\n';
}