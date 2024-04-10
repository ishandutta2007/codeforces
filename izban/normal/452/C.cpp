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

const int maxn = 1010;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

long double c[maxn][maxn];
long double f[maxn];

double fastsolve(int n, int m) {
    if (n == 1 && m == 1) return 1.0;
    return (1.0 + (n - 1) * (m - 1) / (n * m - 1.0)) / n;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    c[0][0] = 1;
    for (int i = 0; i < maxn - 1; i++) {
        for (int j = 0; j <= i; j++) {
            c[i + 1][j] += c[i][j];
            c[i + 1][j + 1] += c[i][j];
        }
    }
    f[0] = 1;
    for (int i = 1; i <maxn; i++) f[i] = f[i - 1] * i;
    
    int n, m;
    while (cin >> n >> m) {
        printf("%.10lf\n", fastsolve(n, m));
    }
    
    return 0;
}