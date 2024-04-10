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
		string s, p;
		cin >> s;
		int n = s.size();
		for (int i=0; i<n; i++) {
			if (s[i] == '?') {
				int c[3] = {1, 1, 1};
				if (i-1 >= 0)
					c[s[i-1]-'a'] = 0;
				if (i+1 < n && s[i+1] != '?')
					c[s[i+1]-'a'] = 0;
				for (int j=0; j<3; j++)
					if (c[j])
						s[i] = j+'a';
			}
			if (i && s[i] == s[i-1])
				p = "-1";
		}
		if (p.empty())
			p = s;
		cout << p << '\n';
	}
}