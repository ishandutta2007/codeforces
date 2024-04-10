#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s;
int p[400005];

bool good(string s) {
	int x = s.find('.');
	if (x == -1)
		return false;
	if (count(s.begin(), s.end(), '.') > 1)
		return false;
	int y = (int)s.size() - x - 1;
	return x >= 1 && x <= 8 && y >= 1 && y <= 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	int n = s.size();
	p[0] = 0;
	for (int i=1; i<=n; i++) {
		p[i] = -1;
		for (int l=3; l<=12; l++) {
			if (i-l < 0)
				continue;
			if (good(s.substr(i-l, l)) && p[i-l] != -1) {
				p[i] = i-l;
				break;
			}
		}
	}
	if (p[n] == -1) {
		cout << "NO\n";
		return 0;
	}
	vector<string> sol;
	for (int i=n; i; i=p[i]) {
		sol.push_back(s.substr(p[i], i-p[i]));
	}
	cout << "YES\n";
	for (int i=(int)sol.size()-1; i>=0; i--)
		cout << sol[i] << '\n';
}