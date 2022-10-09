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
		basic_string<pair<int, int>> z;
		for (int a : {1, 2, 3, 4, 6, 12}) {
			int b = 12 / a;
			int ima = 0;
			for (int i=0; i<b; i++) {
				int cnt = 0;
				for (int j=0; j<a; j++) {
					cnt += s[j*b + i] == 'X';
				}
				if (cnt == a)
					ima = 1;
			}
			if (ima)
				z += {a, b};
		}
		cout << z.size() << ' ';
		for (auto p : z)
			cout << p.first << 'x' << p.second << ' ';
		cout << '\n';
	}

}