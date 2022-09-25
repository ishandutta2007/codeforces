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

	int n;
	while (cin >> n) {
		vector<int> a(10, 0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a[x]++;
		}
		if (a[5] >= 9 && a[0] >= 1) {
			for (int i = 0; i <= a[5] - 9; i += 9) cout << "555555555";
			for (int i = 0; i < a[0]; i++) cout << "0";
			cout << endl;
		} else if (a[0] >= 1) cout << "0" << endl;
		else cout << -1 << endl;
	}

	return 0;
}