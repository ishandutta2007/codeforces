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
		string s, a, b;
		cin >> s;
		for (char c : s)
			(c%2?a:b) += c;
		size_t i=0, j=0;
		while (i<a.size() || j<b.size()) {
			bool l;
			if (i == a.size())
				l = false;
			else if (j == b.size())
				l = true;
			else
				l = a[i] < b[j];
			char t = l ? a[i++] : b[j++];
			s[i+j-1] = t;
		}
		cout << s << '\n';
	}
}