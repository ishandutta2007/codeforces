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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> s) {
		int n = s.length();
		ll ans = 1;
		int k = 0, b = 0;
		bool f[255];
		memset(f, 0, sizeof(f));

		for (int i = 0; i < n; i++) {
			if (i) {
				if (s[i] == '?') k++;
				if (s[i] >= 'A' && s[i] <= 'J') {
					if (f[s[i]]) continue;
					ans *= 10 - b;
					b++;
					f[s[i]] = 1;
				}
			} else {
				if (s[i] == '?') ans *= 9;
				if (s[i] >= 'A' && s[i] <= 'J') {
					f[s[i]] = 1;
					ans *= 9;
					b++;
				}
			}
		}
		cout << ans;
		for (int i = 0; i < k; i++) cout << 0;
		cout << endl;
	}

	return 0;
}