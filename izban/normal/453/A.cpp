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

double pr[maxn];

double pw(double x, int k) {
    if (k == 1) return x;
    double ans = pw(x, k / 2);
    ans = ans * ans;
    if (k % 2 == 1) ans = ans * x;
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0);
    
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        pr[n + 1] = 0;
        double ans = 0;
        for (int i = n; i >= 1; i--) {
            pr[i] = 1 - pw((double)(i - 1) / n, m);
            ans += i * (pr[i] - pr[i + 1]);
            //cerr << i << " " << pr[i] << " " << ans << endl;
        }
        printf("%.10lf\n", ans);
    }
    
    return 0;
}