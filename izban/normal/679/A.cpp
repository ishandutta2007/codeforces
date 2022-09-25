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

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

bool check(int x) {
	cout << x << endl;
	string s;
	cin >> s;
	return s == "yes";
}

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0;
	return 1;
}

bool solve() {
	if (check(2 * 2)) return 1;
	if (check(3 * 3)) return 1;
	if (check(5 * 5)) return 1;
	if (check(7 * 7)) return 1;
	int cnt = 0;
	for (int i = 2; i < 50; i++) {
		if (prime(i)) {
			cnt += check(i);
			if (cnt > 1) return 1;
		}
	}
	return 0;
}

int main() {
	if (solve()) cout << "composite" << endl;
	else cout << "prime" << endl;

	return 0;
}