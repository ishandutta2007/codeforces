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

	string s, p;
	cin >> s;

	int tot = 0;

	for (char x : s) {
		if (p.size() && x == p.back()) {
			p.pop_back();
			tot++;
		} else {
			p += x;
		}
	}
	cout << (tot % 2 ? "Yes\n" : "No\n");
}