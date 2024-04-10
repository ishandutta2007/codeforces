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

void norm(string &s, int l, int r) {
	if ((r - l + 1) % 2 == 1) {
		return;
	}
	int m = (l + r) >> 1;
	norm(s, l, m);
	norm(s, m + 1, r);
	bool less = true;
	for (int i = 0; i < (r - l + 1) / 2; i++) {
		if (s[l + i] != s[m + 1 + i]) {
			less = s[l + i] < s[m + 1 + i];
			break;
		}
	}
	if (!less) {
		for (int i = 0; i < (r - l + 1) / 2; i++) {
			swap(s[l + i], s[m + 1 + i]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	string a, b;
	while (cin >> a >> b) {
		int n = a.length();
		norm(a, 0, n - 1);
		norm(b, 0, n - 1);
		if (a != b) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
	return 0;
}