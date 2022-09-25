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

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[2 * maxn];

void solve() {
    for (int i = 0; i < n; i++) a[i] = i + 1;
    
    for (int k = 2; k <= n; k++) {
        int cur = k - 2, x = 0;
        while (1) {
            int y = a[cur];
            a[cur] = x;
            x = y;
            if (cur == n + k - 2) break;
            cur += k;
            if (cur > n + k - 2) cur = n + k - 2;
        }
    }
    for (int i = 0; i < n; i++) cout << a[n - 1 + i] << " \n"[i + 1 == n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) solve();

	return 0;
}