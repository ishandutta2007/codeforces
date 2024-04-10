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
	int t = 0;
	for (char x : s) {
		if (t == 0 && x == '1')
			t++;
		else if (t > 0 && x == '0')
			t++;
	}
	cout << (t > 6 ? "yes" : "no") << '\n';
}