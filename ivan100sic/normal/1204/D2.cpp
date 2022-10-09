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
	int n = s.size();
	vector<pair<int, int>> v;
	for (int i=0; i<n; i++) {
		if (s[i] == '0' && v.size() && v.back().first == '1')
			v.pop_back();
		else
			v.push_back({s[i], i});
	}
	for (auto [x, y] : v)
		s[y] = '0';
	cout << s << '\n';
}