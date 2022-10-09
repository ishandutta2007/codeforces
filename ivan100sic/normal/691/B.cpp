#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<char, char> par = {
	{'A', 'A'},
	{'b', 'd'},
	{'d', 'b'},
	{'H', 'H'},
	{'I', 'I'},
	{'M', 'M'},
	{'O', 'O'},
	{'o', 'o'},
	{'p', 'q'},
	{'q', 'p'},
	{'T', 'T'},
	{'U', 'U'},
	{'V', 'V'},
	{'v', 'v'},
	{'W', 'W'},
	{'w', 'w'},
	{'X', 'X'},
	{'x', 'x'},
	{'Y', 'Y'},
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	for (int i=0; i<n; i++) {
		if (par[s[i]] != s[n-1-i]) {
			cout << "NIE\n";
			return 0;
		}
	}
	cout << "TAK\n";
}