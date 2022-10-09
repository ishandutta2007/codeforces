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

	int q;
	cin >> q;
	while (q--) {
		string s, t;
		cin >> s >> t;
		int f = 0;
		set<char> ss(s.begin(), s.end()), tt(t.begin(), t.end());
		for (char x : ss)
			if (tt.count(x))
				f = 1;
		cout << (f ? "YES\n" : "NO\n");
	}

}