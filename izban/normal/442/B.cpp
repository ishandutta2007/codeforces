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
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 200200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n;
double p[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> p[i];
        sort(p, p + n);
        double ans = 0;
        double curans = 0, curprod = 1;
        for (int i = n - 1; i >= 0; i--) {
            curans = curans * (1 - p[i]) + p[i] * curprod;
            ans = max(ans, curans);
            curprod *= 1 - p[i];
        }
        printf("%.10lf\n", ans);
    }

	return 0;
}