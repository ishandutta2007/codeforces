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

	string s;
	cin >> s;
	int n = s.size();
	for (int i=0; i<=n; i++) {
		for (char c='a'; c<='z'; c++) {
			string p = s;
			p.insert(p.begin()+i, c);
			string q = p;
			reverse(q.begin(), q.end());
			if (p == q) {
				cout << p << '\n';
				return 0;
			}
		}
	}
	cout << "NA\n";
}