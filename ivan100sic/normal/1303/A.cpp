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

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int kec = count(s.begin(), s.end(), '1');
		if (kec == 0) {
			cout << "0\n";
			continue;
		} else {
			int n = s.size();
			int u = 0;
			while (s[u] == '0')
				u++;
			int v = n-1;
			while (s[v] == '0')
				v--;
			int z = 0;
			for (int i=u; i<v; i++)
				z += s[i] == '0';
			cout << z << '\n';
		}
	}
}