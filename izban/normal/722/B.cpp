#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int f(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	int n;
	while (cin >> n) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		string s;
		getline(cin, s);
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			stringstream ss;
			ss << s;
			int cnt = 0;
			while (ss >> s) {
				for (char c : s) {
					cnt += f(c);
				}
			}
			ok &= cnt == a[i];
		}
		cout << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}