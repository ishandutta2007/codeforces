#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = -1;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
	string s;
	while (cin >> s) {
		int n = s.length();
		int last = -1, balance = 0, minBalance = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '#') last = i;
			balance += s[i] == '(';
			balance -= s[i] != '(';
			minBalance = min(minBalance, balance);
		}
		if (minBalance < 0) {
			cout << -1 << endl;
			continue;
		}
		int ans = balance;
		minBalance = 0, balance = 0;
		for (int i = 0; i < n; i++) {
			balance += s[i] == '(';
			balance -= s[i] != '(';
			if (i == last) balance -= ans;
			minBalance = min(minBalance, balance);
		}
		if (minBalance < 0) {
			cout << -1 << endl;
		} else {
			for (int i = 0; i < n; i++) {
				if (s[i] == '#') {
					if (i == last) {
						cout << ans + 1 << endl;
					} else {
						cout << 1 << endl;
					}
				}
			}
		}
	}

    return 0;
}