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

	int n, m, p;
	cin >> n >> m >> p;
	string s;
	cin >> s;
	list<char> a(s.begin(), s.end());
	auto it = a.begin();
	p--;
	while (p--)
		++it;
	string t;
	cin >> t;
	for (char o : t) {
		if (o == 'L')
			--it;
		else if (o == 'R')
			++it;
		else if (*it == '(') {
			int b = 1;
			a.erase(it++);
			while (b) {
				b += *it == '(' ? 1 : -1;
				a.erase(it++);
			}
			if (it == a.end())
				--it;
		} else {
			int b = -1;
			a.erase(it--);
			bool nub = false;
			while (b) {
				b += *it == '(' ? 1 : -1;
				if (it == a.begin()) {
					a.erase(it);
					it = a.begin();
					nub = true;
					break;
				} else {
					a.erase(it--);
				}
			}
			if (!nub)
				++it;
			if (it == a.end())
				--it;
		}
	}

	for (char c : a)
		cout << c;
	cout << '\n';
}