#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
using namespace std;

//309810XU
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

void solve() {
	string s;
	cin >> s;
	vector<bool> ban(s.size());
	int ans = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1] && !ban[i - 1]) {
			ban[i] = true;
			ans++;
		}
		if (i > 1) {
			if (s[i] == s[i - 2] && !ban[i - 2]) {
				ban[i] = true;
				ans++;
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}