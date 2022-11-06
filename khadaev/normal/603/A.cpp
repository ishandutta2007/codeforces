#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> lens;
	int i = 0;
	while (i < n) {
		int cnt = 0;
		while (i < n && s[i] == '0') {
			++i;
			++cnt;
		}
		if (cnt) lens.push_back(cnt);
		cnt = 0;
		while (i < n && s[i] == '1') {
			++i;
			++cnt;
		}
		if (cnt) lens.push_back(cnt);
	}
	int cnt_gr = 0;
	for (int i : lens)
		if (i > 1) cnt_gr += i - 1;
	if (cnt_gr > 1) {
		cout << lens.size() + 2 << '\n';
	} else cout << lens.size() + cnt_gr << '\n';
}