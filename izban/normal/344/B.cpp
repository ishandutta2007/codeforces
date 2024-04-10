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

int a, b, c;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> a >> b >> c) {
		bool f = 0;
		for (int ansa = 0; ansa <= a; ansa++) {
			int ansb = b - ansa;
			int ansc = a - ansa;
			if (ansa + ansc == a && ansa + ansb == b && ansb + ansc == c && 0 <= ansa && ansa <= min(a, b) && 0 <= ansb && ansb <= min(b, c) && 0 <= ansc && ansc <= min(a, c)) {
				printf("%d %d %d\n", ansa, ansb, ansc);
				f = 1;
				break;
			}
		}
		if (!f) cout << "Impossible\n";
	}

	return 0;
}