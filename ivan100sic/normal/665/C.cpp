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
	int sol = 0;
	int n = s.size();
	for (int i=1; i<n; i++) {
		if (s[i] == s[i-1]) {
			sol++;
			if (i == n-1) {
				for (char j='a'; j<='z'; j++) {
					if (j != s[i-1])
						s[i] = j;
				}
			} else {
				for (char j='a'; j<='z'; j++) {
					if (j != s[i-1] && j != s[i+1])
						s[i] = j;
				}
			}
		}
	}
	cout << s << '\n';
}