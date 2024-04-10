#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

vector<pair<char, int> > v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	int c = 0;
	for (int i = 0; i < s.length(); i++) {
		c++;
		if (i + 1 == s.length() || s[i] != s[i + 1]) {
			v.push_back(make_pair(s[i], c));
			c = 0;
		}
	}
	if (v.size() % 2 == 0 || v[v.size() / 2].second < 2) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < v.size() / 2; i++)
		if (v[i].first != v[(int)v.size() - i - 1].first || v[i].second + v[(int)v.size() - i - 1].second < 3) {
			cout << 0 << '\n';
			return 0;
		}
	cout << v[v.size() / 2].second + 1 << '\n';
	return 0;
}