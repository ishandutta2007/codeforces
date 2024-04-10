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

	int a, b;
	cin >> a >> b;
	while (a <= b) {
		string s = to_string(a);
		set<char> t(s.begin(), s.end());
		if (t.size() == s.size()) {
			cout << a << '\n';
			return 0;
		}
		a++;
	}
	cout << "-1\n";
}