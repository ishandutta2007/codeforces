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

	ll n;
	while (cin >> n) {
		while (n % 3 == 0) {
			n /= 3;
		}
		cout << n / 3 + 1 << endl;
	}

	return 0;
}