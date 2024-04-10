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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
int a[maxn], t[maxn];
ll add[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 1; i <= m; i++) {
			add[i] = add[i - 1];
			int x;
			cin >> x;
			if (x == 1) {
				int y, z;
				cin >> y >> z; y--;
				a[y] = z;
				t[y] = i;
			}
			if (x == 2) {
				int y;
				cin >> y;
				add[i] += y;
			}
			if (x == 3) {
				int y;
				cin >> y; y--;
				cout << (ll)a[y] + add[i] - add[t[y]] << endl;
			}
		}
		cout << endl;
	}

	return 0;
}