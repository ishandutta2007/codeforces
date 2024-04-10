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
	string p = s;
	sort(p.begin(), p.end());
	if (p != s) {
		cout << "NO\n";
		return 0;
	}
	int a = count(s.begin(), s.end(), 'a');
	int b = count(s.begin(), s.end(), 'b');
	int c = count(s.begin(), s.end(), 'c');
	if (a && b && c && (c == a || c == b)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}