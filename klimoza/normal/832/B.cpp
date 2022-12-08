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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	string l;
	cin >> l;
	vector<bool> good(26, false);
	for (char c : l) good[c - 'a'] = true;
	string pattern;
	cin >> pattern;
	int m = pattern.size();
	int q; cin >> q;
		int ind = -1;
		for (int i = 0; i < m; i++) {
			if (pattern[i] == '*') {
				ind = i;
				break;
			}
		}
	while (q--) {
		string st;
		cin >> st;
		int n = st.size();
		bool fl = true;
		for (int i = 0; i < min(n, m); i++) {
			if (pattern[i] == '*') {
				ind = i;
				break;
			}
			if (pattern[i] == '?' && !good[st[i] - 'a']) {
				cout << "NO\n"; fl = false; break;
			}
			if (pattern[i] != '?' && pattern[i] != st[i]) {
				cout << "NO\n"; fl = false; break;
			}
		}
		if (!fl) continue;
		if (ind == -1 && n != m) {
			cout << "NO\n";
			continue;
		}
		if (m - 1 > n) {
			cout << "NO\n";
			continue;
		}
		int t = m - ind;
		for (int i = 0; i < min(n, m); i++) {
			if (pattern[m - 1 - i] == '*') {
				break;
			}
			if (pattern[m - 1 - i] == '?' && !good[st[n - 1 - i] - 'a']) {
				cout << "NO\n"; fl = false; break;
			}
			if (pattern[m - 1 - i] != '?' && pattern[m - 1 - i] != st[n - 1 - i]) {
				cout << "NO\n"; fl = false; break;
			}
		}
		//cout << n - m << " " << ind << endl;;
		if (!fl) continue;
		if (ind != -1) {
			for (int i = ind; i <= ind + n - m; i++) {
				if (good[st[i] - 'a']) {
					cout << "NO\n"; fl = false; break;
				}
			}
		}
		if (!fl) continue;
		cout << "YES\n";
	}
	//system("pause");
	return 0;
}