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

const int maxn = 1 << 9;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n;
int a[maxn], b[maxn];

bool f(int x) {
    for (int i = 0; i < x; i++) {
        b[i] = a[i];
    }
    for (int i = x; i < n; i++) {
        int mx = 0;
        for (int j = 1; j < x; j++) {
            if (b[j] > b[mx]) {
                mx = j;
            }
        }
        if (b[mx] == 0) return 0;
        b[mx] = min(b[mx] - 1, a[i]);
    }
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        reverse(a, a + n);
        
        int l = 1, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (f(m)) r = m;
            else l = m;
        }
        if (f(l)) cout << l << endl;
        else cout << r << endl;
    }

	return 0;
}