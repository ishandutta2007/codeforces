#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cassert>
#include <unordered_map>

using namespace std;
const int N = 210000, Inf = 2e9;

struct P {
    int x, y;

    void read() {
        scanf("%d%d", &x, &y);
    }

    long long getH() {
        int d = __gcd(x, y);
        return 1ll * (x / d) * Inf + y / d;
    }
};

long long getmi(P u, P v) {
    return (P) {u.x + v.x, u.y + v.y}.getH();
}

unordered_map<long long, int> H1, H2;
int t[N], id[N];
P p[N];
int n;

int operator<(const P &a, const P &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

set<P> S[N];
int w[N], tot1, tot2;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        p[i].read();
        if (t[i] < 3) {
            long long d = 1ll * p[i].x * p[i].x + 1ll * p[i].y * p[i].y;
            if (H1[d] == 0) {
                H1[d] = ++tot1;
            }
            id[i] = H1[d];
        } else if (t[i] == 3) {
            long long d = p[i].getH();
            if (H2[d] == 0) {
                H2[d] = ++tot1;
            }
            id[i] = H2[d];
        }
    }
    int si = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {
            ++si;
            int loc = id[i];
            for (P p2: S[loc]) {
                w[H2[getmi(p[i], p2)]] += 2;
            }
            w[H2[p[i].getH()]]++;
            S[loc].insert(p[i]);
        } else if (t[i] == 2) {
            int loc = id[i];
            --si;
            S[loc].erase(p[i]);
            for (P p2: S[loc]) {
                w[H2[getmi(p[i], p2)]] -= 2;
            }
            w[H2[p[i].getH()]]--;
        } else {
            printf("%d\n", si - w[id[i]]);
        }
    }
}