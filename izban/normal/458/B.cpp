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

#define ll unsigned long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 200200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, a[maxn], m, b[maxn];

ll fastsolve() {
    ll ans = 2e19;
    for (int o = 0; o < 2; o++) {
        ll suma = 0, sumb = 0;
        for (int i = 0; i < n; i++) suma += a[i];
        for (int i = 0; i < m; i++) sumb += b[i];
        for (int i = 0; i < m; i++) {
            sumb -= b[m - i - 1];
            ll res = sumb + (i + 1) * suma;
            ans = min(ans, res);
        }
        swap(n, m);
        for (int i = 0; i < max(n, m); i++) swap(a[i], b[i]);
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(b, b + m);
        //n = m = 1e5;
        //for (int i = 0; i < n; i++) a[i] = b[i] = 1e9;
        
        cout << fastsolve() << endl;
    }
    
    return 0;
}