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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 312;
	vector<int> r(n), x(n);
	
	r[0] = 1000000;
	x[0] = 0;
	for (int i = 1; i < n - 1; i++) {
		x[i] = 100000 + 600 * i;
		r[i] = n - i + 1;
	}
	r[n - 1] = 1000000;
	x[n - 1] = 1000000;

	cout << n << endl;
	for (int i = 0; i < n; i++) cout << x[i] << " " << r[i] << endl;

	return 0;
}