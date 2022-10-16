#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
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
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	string s;
	cin >> s;

	vector<int> pref(s.size());
	vector<int> suf(s.size());

	for (int i = 1; i < (int)s.size(); i++) {
		pref[i] = pref[i - 1] + (s[i] == 'v' && s[i - 1] == 'v');
	}

	for (int i = (int)s.size() - 2; i >= 0; i--) {
		suf[i] = suf[i + 1] + (s[i] == 'v' && s[i + 1] == 'v');
	}

	int ans = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'o') {
			ans += pref[i] * suf[i];
		}
	}

	cout << ans;
}