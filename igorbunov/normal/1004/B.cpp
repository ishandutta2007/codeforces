#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <exception>
#include <stdexcept>

//#define int long long

using namespace std;

int my_max(int a, int b) {
	if (a >= b) {
		return a;
	} else {
		return b;
	}
}


vector<int> used(31, 0);
vector<int> used1(31, 0);

signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
	}
	bool d = 0;
	for (int i = 0; i < n; i++) {
		cout << (int)d;
		d = !d;
	}
	return 0;
}