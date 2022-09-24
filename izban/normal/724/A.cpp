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

const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const string a[7] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };

int f(string s) {
	for (int i = 0; i < 7; i++) if (a[i] == s) return i;
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	string a, b;
	while (cin >> a >> b) {
		int id1 = f(a);
		int id2 = f(b);

		bool ok = 0;
		for (int m = 0; m < 11; m++) {
			int nid2 = (id1 + days[m]) % 7;
			if (nid2 == id2) {
				ok = 1;
			}
		}
		string res;
		if (ok) res = "YES";
		else res = "NO";
		cout << res << endl;
	}

	return 0;
}