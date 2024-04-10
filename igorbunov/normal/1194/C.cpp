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
	int q;
	cin >> q;
	for (int _ = 0; _ < q; _++) {
		string p, s, t;
		cin >> s >> t >> p;

		int l = 0;
		vector<bool> used(t.size());
		for (int i = 0; i < t.size(); i++) {
			if (l == s.size()) {
				break;
			}

			if (s[l] == t[i]) {
				l++;
				used[i] = true;
			}
		}

		if (l != s.size()) {
			cout << "NO\n";
			continue;
		}

		vector<int> arr1(26);
		vector<int> arr2(26);

		for (int i = 0; i < p.size(); i++) {
			arr1[p[i] - 'a']++;
		}

		for (int i = 0; i < t.size(); i++) {
			if (!used[i]) {
				arr2[t[i] - 'a']++;
			}
		}
		bool can = true;
		for (int i = 0; i < 26; i++) {
			if (arr1[i] < arr2[i]) {
				cout << "NO\n";
				can = false;
				break;
			}
		}

		if (can) {
			cout << "YES\n";
			continue;
		}
	}
}