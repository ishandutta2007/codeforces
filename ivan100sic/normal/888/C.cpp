#include <bits/stdc++.h>
using namespace std;

unsigned int to_mask(const vector<int>& b) {
	unsigned int r = 0;
	for (int i=0; i<26; i++) {
		if (b[i]) {
			r += 1 << i;
		}
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string s;
	cin >> s;
	n = s.size();

	int l = 1, r = n, o = -1;
	while (l <= r) {
		int m = (l + r) / 2;

		vector<int> b(26, 0);

		for (int i=0; i<m; i++) {
			b[s[i]-'a']++;
		}

		auto mask = to_mask(b);

		for (int i=1; i+m <= n; i++) {
			b[s[i-1] - 'a']--;
			b[s[i-1+m] - 'a']++;
			mask &= to_mask(b);

			//cerr << hex << mask << '\n';
		}

		//cerr << m << ' ' << hex << mask << '\n';

		if (mask) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}

	cout << o;
}