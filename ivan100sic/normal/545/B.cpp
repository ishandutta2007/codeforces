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

	string a, b;
	cin >> a >> b;
	int n = a.size();
	set<int> s;
	for (int i=0; i<n; i++)
		if (a[i] != b[i])
			s.insert(i);
	if (s.size() % 2)
		cout << "impossible\n";
	else {
		while (s.size()) {
			int x = *s.begin();
			s.erase(s.begin());
			s.erase(s.begin());
			a[x] ^= 1;
		}
		cout << a << '\n';
	}
}