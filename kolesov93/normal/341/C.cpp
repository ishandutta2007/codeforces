#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const int N = 2222;
const int MOD = 1000000007;
ll f[N][N];

void relax(ll& x, ll y) {
    x = (x + (y % MOD)) % MOD;
}

ll fact[N];

int fr[N], have[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (fact[i - 1] * ll(i)) % MOD;
    }
    
    for (int n = 1; n < N; ++n)
        for (int m = 0; m <= n; ++m) {
            if (m == 0) {
                f[n][m] = fact[n];
            } else {
                if (m > 1) {
                    relax(f[n][m], f[n - 1][m - 2] * ll(m - 1));
                }
                relax(f[n][m], f[n - 1][m - 1] * ll(n - m));
            }
        }
    
    memset(fr, 1, sizeof(fr));
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        if (x != -1) {
            fr[i] = false;
            have[x] = true;
        }
    }
    
    int cnt = 0, bad = 0;
    for (int i = 1; i <= n; ++i) {
        if (fr[i]) {
            ++cnt; 
            if (!have[i]) {
                bad++;
            }
        }
    }

    cout << f[cnt][bad] << endl;
    
    return 0;
}