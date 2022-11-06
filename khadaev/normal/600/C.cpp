#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
	string s;
	cin >> s;
	int count[26];
	for (int i = 0; i < 26; ++i) count[i] = 0;
	for (char c : s) count[c - 'a']++;
	vector<int> odds;
	for (int i = 0; i < 26; ++i)
		if (count[i] % 2) odds.push_back(i);
	for (int i = 0; i < odds.size() / 2; ++i) {
		count[odds[i]]++;
		count[odds[odds.size() - 1 - i]]--;
	}
	string ans;
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < count[i] / 2; ++j) ans += ('a' + i);
	if (odds.size() % 2) {
		for (int i = 0; i < 26; ++i)
			if (count[i] % 2) {
				ans += ('a' + i);
				break;
			}
	}
	for (int i = 25; i >= 0; --i)
		for (int j = 0; j < count[i] / 2; ++j) ans += ('a' + i);

	cout << ans << '\n';
}