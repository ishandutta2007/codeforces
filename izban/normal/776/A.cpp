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

	string a, b;
	while (cin >> a >> b) {
		int n;
		cin >> n;
		cout << a << " " << b << endl;
		for (int i = 0; i < n; i++) {
			string s1;
			string s2;
			cin >> s1 >> s2;
			if (a == s1) a = s2;
			else b = s2;
			cout << a << " " << b << endl;
		}
	}

	return 0;
}