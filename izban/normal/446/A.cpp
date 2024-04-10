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
int a[maxn];

int fastsolve() {
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        int r = l;
        while (r < n && a[r + 1] > a[r]) r++;
        if (l > 1 && a[l - 1] >= a[l]) ans = max(ans, r - l + 2);
        if (r == n) {
            ans = max(ans, r - l + 1);
            break;
        }
        int o = r;
        if (a[r + 1] - a[r - 1] >= 2) {
            int old = a[r];
            a[r] = a[r + 1] - 1;
            while (r < n && a[r + 1] > a[r]) r++;
            ans = max(ans, r - l + 1);
            a[o] = old;
            r = o;
        }
        {
            int old = a[r + 1];
            a[r + 1] = a[r] + 1;
            while (r < n && a[r + 1] > a[r]) r++;
            ans = max(ans, r - l + 1);
            a[o + 1] = old;
            r = o;
        }
        l = max(l, r - 1);
    }
    return ans;
}

int slowsolve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = i;
        while (l > 1 && a[l - 1] < a[l]) l--;
        while (r < n && a[r + 1] > a[r]) r++;
        ans = max(ans, r - l + 1);
        
        int pa = a[i];
        if (i > 1) {
            a[i] = a[i - 1] + 1;
            l = r = i;
            while (l > 1 && a[l - 1] < a[l]) l--;
            while (r < n && a[r + 1] > a[r]) r++;
            ans = max(ans, r - l + 1);
        }
        {
            a[i] = a[i + 1] - 1;
            l = r = i;
            while (l > 1 && a[l - 1] < a[l]) l--;
            while (r < n && a[r + 1] > a[r]) r++;
            ans = max(ans, r - l + 1);
        }
        a[i] = pa;
    }
    return ans;
}

void gen() {
    n = rand() % 100 + 1;
    for (int i = 1; i <= n; i++) a[i] = rand() % (2 * n) + 1;
}

void stress(bool f) {
    if (!f) return;
    for (int it = 0;; it++) {
        cerr << it << endl;
        gen();
        int ans1 = fastsolve();
        int ans2 = slowsolve();
        if (ans1 != ans2) {
            slowsolve();
            cout << ans1 << " instead of " << ans2 << endl;
            cout << n << endl;
            for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
            break;
        }
    }
    exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    stress(0);
    
    while (cin >> n) {
        a[0] = -1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cout << fastsolve() << endl;
    }
    
    return 0;
}