// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool moze(string s) {
	int n = s.size();
	for (int i=0; i<n; i++) {
		if (s[i] == '(') {
			for (int j=i+1; j<n; j++) {
				if (s[j] == ')')
					return true;
			}
			return false;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	vector<vector<int>> b;
	while (moze(s)) {
		int n = s.size();
		int op = 0, j = 0, k = 0;
		for (int i=0; i<n; i++) {
			op += s[i] == '(';
			// n^3, don't care
			if (count(s.begin() + i + 1, s.end(), ')') >= op) {
				j = i;
				k = op;
			}
		}

		cerr << s << " ima " << k << " do " << j << '\n';

		vector<int> a;
		string mark(n, 0);
		for (int i=0; i<=j; i++) {
			if (s[i] == '(') {
				a.push_back(i);
				mark[i] = 1;
			}
		}

		int left = k;
		for (int i=j+1; i<n; i++) {
			if (left && s[i] == ')') {
				a.push_back(i);
				mark[i] = 1;
				left--;
			}
		}

		string p;
		for (int i=0; i<n; i++) {
			if (!mark[i]) {
				p += s[i]; 
			}
		}

		s = p;
		b.push_back(a);
	}

	cout << b.size() << '\n';
	for (auto v : b) {
		cout << v.size() << '\n';
		for (int x : v)
			cout << x+1 << ' ';
		cout << '\n';
	}
}

// I will still practice daily...