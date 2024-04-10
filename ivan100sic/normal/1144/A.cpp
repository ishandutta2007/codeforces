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
		string p = s;
		sort(p.begin(), p.end());
		p.resize(unique(p.begin(), p.end()) - p.begin());
		if (p.size() != s.size())
			cout << "No\n";
		else {
			int ok = 1;
			for (int i=0; i<(int)p.size()-1; i++)
				if (p[i+1] - p[i] != 1)
					ok = 0;
			cout << (ok ? "Yes\n" : "No\n");
		}
	}
}