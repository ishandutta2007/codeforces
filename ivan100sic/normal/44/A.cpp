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

	int n;
	cin >> n;
	set<string> s;
	while (n--) {
		string a, b;
		cin >> a >> b;
		s.insert(a + " " + b);
	}
	cout << s.size() << '\n';
}