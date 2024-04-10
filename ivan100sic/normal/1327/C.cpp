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

	int n, m;
	cin >> n >> m;
	// he he ostalo mi ni ne treba
	string s;
	s += string(n-1, 'U');
	s += string(m-1, 'L');
	for (int j=0; j<m; j++) {
		s += string(n-1, 'D');
		if (j < m-1) {
			s += string(n-1, 'U');
			s += 'R';
		}
	}
	cout << s.size() << '\n' << s << '\n';
}

// I will still practice daily...