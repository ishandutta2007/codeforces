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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n;
int m;
int a[maxn], b[maxn];
int c[maxn], d[maxn];

bool rec(int cur) {
    if (cur == n) {
        bool ok = 1;
        for (int i = 0; i < cur; i++) ok &= !b[i] && d[i] == 0 || d[i] >= 2;
        if (ok) {
            ok = 0;
            ok = 1;
        }
        return ok;
    }
    
    for (int i = 0; i < cur; i++) {
        if (b[i] >= a[cur]) {
            b[i] -= a[cur];
            b[cur] = c[cur];
            d[i]++;
            if (rec(cur + 1)) {
                return 1;
            }
            d[i]--;
            b[cur] = 0;
            b[i] += a[cur];
        }
    }
    
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        reverse(a, a + n);
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 2) ok = false; else
            if (a[i] == 3) {
                for (int k = 0; k < 2; k++) {
                    if (a[n - 1] != 1) ok = false;
                    else n--;
                }
                c[i] = 0;
            } else 
            if (a[i] == 4) {
                for (int k = 0; k < 3; k++) {
                    if (a[n - 1] != 1) ok = false;
                    else n--;
                }        
                c[i] = 0;    
            } else 
            c[i] = a[i] - 1;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        if (n == 1) {
            if (c[0] == 0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        b[0] = c[0];
        d[0] = 1;
        m = 1;
        if (rec(1)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}