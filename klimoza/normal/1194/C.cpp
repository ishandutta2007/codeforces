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

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
double eps = 1e-6;
ll mod = 1e9+ 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		string s, t, p;
		cin >> s >> t >> p;
		int n = size(t);
		bool ans = true;
		vector<bool> nice(n);
		int cur = 0;
		for (int i = 0; i < size(s); i++) {
			bool fl = false;
			for (int j = cur; j < size(t); j++) {
				if (!nice[j] && s[i] == t[j]) {
					fl = true;
					nice[j] = true;
					cur = j + 1;
					break;
				}
			}
			if (!fl) {
				ans = false;
				break;
			}
		}
		if (!ans) {
			cout << "NO\n";
			continue;
		}
		map<char, int> cnt;
		for (char c : p) cnt[c]++;
		for (int i = 0; i < size(t); i++) {
			if (nice[i]) continue;
			if (cnt[t[i]] == 0) {
				ans = false;
				break;
			}
			cnt[t[i]]--;
		}
		if (!ans) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}