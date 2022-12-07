#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acosl(-1.);
using namespace std;

const int N = 2222;

int n, k;
vector< pair<int, int> > g[N];
ld fact[N];

inline ld calc(int n, int k) {
    return fact[n] - fact[k] - fact[n - k];
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d%d", &n, &k);

    fact[0] = 0;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] + logl(ld(i));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x; scanf("%d", &x);
            if (x != -1) {
                g[i].push_back(make_pair(j, x));
                g[j].push_back(make_pair(i, x));
            }
        }
    }

    ld ans = 0;
    ld denom = calc(n, k);
    for (int x = 0; x < n; ++x) {
        if (g[x].size() >= k) {
            ld sum = 0;
            for (int i = 0; i < g[x].size(); ++i) { 
                sum += g[x][i].second;
            }

            ld factor = expl(calc(g[x].size() - 1, k - 1) - denom);
            ans += factor * sum;
        }
    }

    cout << (unsigned long long) (ans + 1e-8) << endl;

    return 0;
}