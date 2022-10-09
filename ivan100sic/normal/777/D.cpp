#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n;
string s[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> s[i];
	}

	for (int i=n-1; i>=1; i--) {
		if (s[i] <= s[i+1]) {
			continue;
		}

		int p = 0;
		while (s[i][p] <= s[i+1][p]) {
			p++;
		}

		s[i] = s[i].substr(0, p);
	}

	for (int i=1; i<=n; i++) {
		cout << s[i] << '\n';
	}
}