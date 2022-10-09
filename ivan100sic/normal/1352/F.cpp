// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct _in {
	template<class T>
	operator T() {
		T x;
		cin >> x;
		return x;
	}
} in;


int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t = in;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b == 0) {
			if (a || c) {
				cout << (a ? string(a+1, '0') : string()) << (c ? string(c+1, '1') : string()) << '\n';
			} else {
				cout << "0\n";
			}
			continue;
		}
		string s = "0";
		while (b--) {
			s += s.back() ^ 1;
		}
		s.insert(1, string(c, '1'));
		s.insert(1, string(a, '0'));
		cout << s << '\n';
	}
}