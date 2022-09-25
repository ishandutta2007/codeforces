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
const double PHI = (sqrt(5.0) - 1) / 2.0;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vector<int> v;
		for (int i = 0; i < n; i++) {
			v.push_back(1);
			while (v.size() >= 2 && v[(int)v.size() - 1] == v[(int)v.size() - 2]) {
				int x = v.back();
				v.pop_back();
				v.pop_back();
				v.push_back(x + 1);
			}
		}
		for (int i = 0; i < (int)v.size(); i++) printf("%d%c", v[i], " \n"[i + 1 == (int)v.size()]);
	}

	return 0;
}