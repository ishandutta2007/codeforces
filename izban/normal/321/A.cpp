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

int a, b;
string s;

string solve() {
	int sx = 0, sy = 0;
	for (int i = 0; i < s.length(); i++) {
		sx += s[i] == 'R';
		sy += s[i] == 'U';
		sx -= s[i] == 'L';
		sy -= s[i] == 'D';
	}
	
	int cx = 0, cy = 0;
	for (int i = 0; i < s.length(); i++) {
		if (sx == 0 && sy == 0) {
			if (cx == a && cy == b) return "Yes";
		} else if (sx == 0) {
			if (cx == a && (b - cy) % sy == 0 && (b - cy) / sy >= 0) return "Yes";
		} else if (sy == 0) {
			if (cy == b && (a - cx) % sx == 0 && (a - cx) / sx >= 0) return "Yes";
		} else {
			if ((a - cx) % sx == 0 && (b - cy) % sy == 0 && (a - cx) / sx == (b - cy) / sy && (a - cx) / sx >= 0) return "Yes";
		}

		cx += s[i] == 'R';
		cy += s[i] == 'U';
		cx -= s[i] == 'L';
		cy -= s[i] == 'D';
	}
	return "No";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> a >> b >> s) cout << solve() << endl;

	return 0;
}