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

	int n, d=0; string s;
	cin >> n >> s;
	for (int i=1; i<n; i++) {
		if (s[i] == s[i-1]) {
			set<char> t = {'R', 'G', 'B'};
			t.erase(s[i-1]);
			if (i+1 < n) t.erase(s[i+1]);
			s[i] = *t.begin();
			d++;
		}
	}	

	cout << d << '\n' << s << '\n';
}