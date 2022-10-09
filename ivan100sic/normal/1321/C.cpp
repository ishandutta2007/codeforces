// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	int n;
	string s;
	cin >> n >> s;
	for (char x='z'; x>='a'; x--) {
		while (1) {
			int i = -1;
			for (int j=0; j<(int)s.size(); j++) {
				if (s[j] == x && ((j > 0 && s[j-1] == x-1) || (j+1 < (int)s.size() && s[j+1] == x-1))) {
					i = j;
					break;
				}
			}
			if (i == -1) {
				break;
			} else {
				s.erase(s.begin() + i);
			}
		}
	}

	cout << n - s.size() << '\n';
}

// I will still practice daily...