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

int n, m;
int x[maxn];


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) cin >> x[i];
        double res = 0.0;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            res = max(res, (double)(x[u] + x[v]) / w);
        }
        printf("%.13lf\n", res);
    }
    
    return 0;
}