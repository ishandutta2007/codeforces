// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s, q;
	cin >> s;
	int n;
	cin >> n;
	while (n--) {
		string p;
		cin >> p;
		if (p.size() >= s.size() && equal(begin(s), end(s), begin(p))) {
			if (q.empty()) q = p;
			else q = min(q, p);
		}
	}

	if (q.empty()) q = s;
	cout << q << '\n';
}