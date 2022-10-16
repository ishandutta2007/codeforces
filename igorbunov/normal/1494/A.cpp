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

#define mod NE_mod
#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

void solve() {
	string s;
	cin >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < s.size(); i++) {
		a += s[i] == 'A';
		b += s[i] == 'B';
		c += s[i] == 'C';
	}

	map<char, int> kek;

	for (int i1 = 0; i1 < 2; i1++) {
		kek['A'] = i1 * 2 - 1;
		for (int i2 = 0; i2 < 2; i2++) {
			kek['B'] = i2 * 2 - 1;
			for (int i3 = 0; i3 < 2; i3++) {
				kek['C'] = i3 * 2 - 1;

				int bal = 0;
				bool good = true;
				for (int i = 0; i < s.size(); i++) {
					bal += kek[s[i]];
					if (bal < 0) {
						good = false;
					}
				}

				if (bal == 0 && good) {
					cout << "Yes\n";
					return;
				}
			}
		}
	}
	cout << "No\n";
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