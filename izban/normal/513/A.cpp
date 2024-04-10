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

	int n1, n2, k1, k2;
	while (cin >> n1 >> n2 >> k1 >> k2) {
		if (n1 > n2) cout << "First" << endl;
		else cout << "Second" << endl;
	}

	return 0;
}