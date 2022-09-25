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

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = -1;
const int inf = 1e9;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	string a;
	while (cin >> n >> a) {
		int cnt2 = 0, cnt3 = 0, cnt5 = 0, cnt7 = 0;
		for (int i = 0; i < n; i++) {
			int c = a[i] - '0';
			cnt2 += c / 2;
			cnt2 += c / 4;
			cnt2 += c / 8;
			cnt3 += c / 3;
			cnt3 += c / 9;
			cnt5 += c / 5;
			cnt7 += c / 7;
		}
		while (cnt7 > 0) {
			cout << '7';
			cnt2 -= 7 / 2 + 7 / 4 + 7 / 8;
			cnt3 -= 7 / 3 + 7 / 9;
			cnt5 -= 7 / 5;
			cnt7 -= 7 / 7;
		}
		while (cnt5 > 0) {
			cout << '5';
			cnt2 -= 5 / 2 + 5 / 4 + 5 / 8;
			cnt3 -= 5 / 3 + 5 / 9;
			cnt5 -= 5 / 5;
		}
		while (cnt3 > 0) {
			cout << '3';
			cnt2 -= 3 / 2 + 3 / 4 + 3 / 8;
			cnt3 -= 3 / 3 + 3 / 9;
		}
		while (cnt2 > 0) {
			cout << '2';
			cnt2--;
		}
		cout << endl;
	}

	return 0;
}