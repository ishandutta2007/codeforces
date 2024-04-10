#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll l[50005], r[50005], z;
string s;

set<pair<ll, int>> zatvorene;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	for (int i=0; i<n; i++) {
		if (s[i] == '?') {
			cin >> l[i] >> r[i];
		} else if (s[i] == '(') {
			l[i] = 0;
			r[i] = 1e11;
		} else if (s[i] == ')') {
			l[i] = 1e11;
			r[i] = 0;
		}
	}

	for (int i=0; i<n; i++) {
		if (i % 2 == 0) {
			// stavi prvo kao zatvorenu pa biraj najjeftiniju koju ces da otvoris
			s[i] = ')';
			zatvorene.insert({l[i] - r[i], i});
			auto it = zatvorene.begin();
			int j = it->second;
			zatvorene.erase(it);
			s[j] = '(';
		} else {
			// stavi zatvorenu
			s[i] = ')';
			zatvorene.insert({l[i] - r[i], i});
		}
	}

	for (int i=0; i<n; i++)
		z += s[i] == '(' ? l[i] : r[i];

	if (z >= 9.9e10) {
		cout << "-1\n";
		return 0;
	}

	cout << z << '\n' << s << '\n';
}