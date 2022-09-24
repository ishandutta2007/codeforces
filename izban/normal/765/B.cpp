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
const int MOD = 0; // 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	string s = "";
	while (cin >> s) {
		bool ok = 1;
		char c = 'a';
		while (s != "") {
			if (s[0] != c) ok = 0;
			string t = "";
			for (int i = 0; i < (int)s.length(); i++) if (s[i] != c) t += s[i];
			s = t;
			c++;
		}
		string ans = ok ? "YES" : "NO";
		cout << ans << endl;
	}

	return 0;
}