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
		string s;
		cin >> s;
		int n = s.size();
		set<char> ok;
		char last = 0;
		int streak = 0;	
		for (int i=0; i<n; i++) {
			if (s[i] == last)
				streak++;
			else {
				if (streak % 2)
					ok.insert(last);
				streak = 1;
				last = s[i];
			}
		}
		if (streak % 2)
			ok.insert(last);
		for (char c : ok)
			cout << c;
		cout << '\n';
	}
}