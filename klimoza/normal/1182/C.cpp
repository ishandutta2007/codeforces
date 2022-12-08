#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>

using namespace std;

typedef long long ll;

ll INF = 4e18;
ll INFi = 2e9;
long double eps = 1e-6;
ll mod = 1e9 + 7;

char lD(string st) {
	reverse(st.begin(), st.end());
	for (char c : st) {
		if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') return c;
	}
}

int cn(string st) {
	int f = 0;
	for (char c : st) {
		if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') f++;
	}
	return f;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
	
	int n;
	cin >> n;
	vector<pair<pair<int, char>, string>> word(n);
	vector<pair<string, string>> cool;
	for (int i = 0; i < n; i++) {
		cin >> word[i].second;
		word[i].first.second = lD(word[i].second);
		word[i].first.first = cn(word[i].second);
	}
	sort(word.begin(), word.end());
	vector<char> used(n);
	vector<pair<string, string>> jopa;
	vector<pair<pair<int, char>, string>> bad;
	for (int i = 1; i < n; i++) {
		if (word[i - 1].first == word[i].first) {
			cool.push_back({ word[i - 1].second, word[i].second });
			used[i - 1] = true;
			used[i] = true;
			i++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) bad.push_back(word[i]);
	}
	for (int j = 1; j < bad.size(); j++) {
		if (bad[j].first.first == bad[j - 1].first.first) {
			jopa.push_back({ bad[j - 1].second, bad[j].second });
			j++;
		}
	}
	vector < pair<pair<string, string>, pair<string, string>>> ans;
	while (cool.size() && jopa.size()) {
		ans.push_back({ cool[cool.size() - 1], jopa[jopa.size() - 1] });
		cool.pop_back();
		jopa.pop_back();
	}
	while (cool.size() >= 2) {
		ans.push_back({ cool[cool.size() - 1], cool[cool.size() - 2] });
		cool.pop_back(); cool.pop_back();
	}
	cout << ans.size() << endl;
	for (auto u : ans) cout << u.second.first << " " << u.first.first << endl << u.second.second << " " << u.first.second << endl;
	return 0;
}