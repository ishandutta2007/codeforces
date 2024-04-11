#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 111111;

int v[N], c[N];
ll f[N];
bool u[N];
int n;

ll solve(ll A, ll B) {
    memset(f, 0, sizeof(f));
    memset(u, 0, sizeof(u));

    bool u1 = false, u2 = false;
    ll m1 = 0, m2 = 0;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll nval = ll(v[i]) * B;

        if (u[ c[i] ]) {
            nval = max(nval, f[ c[i] ] + ll(v[i]) * A);    
        }

        if (u1 && m1 != c[i]) {
            nval = max(nval, f[ m1 ] + ll(v[i]) * B);
        }
        if (u2 && m2 != c[i]) {
            nval = max(nval, f[ m2 ] + ll(v[i]) * B);
        }

        if (!u[ c[i] ] || f[ c[i] ] < nval) {
            f[ c[i] ] = nval;
            u[ c[i] ] = true;
        }

        ans = max(ans, nval);

        if (u1 && u2) {
            if (m2 != c[i] && f[ c[i] ] > f[ m1 ]) {
                m1 = c[i];
            }
        } else {
            if (!u2) {
                u2 = true;
                m2 = c[i];
            } else {
                if (m2 != c[i]) {
                    u1 = true;
                    m1 = c[i];
                }
            }
        }

       if (!u2 || f[m1] > f[m2]) {
            swap(u1, u2);
            swap(m1, m2);
       }
    }

    return ans;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int q;
    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", c + i);
    }

    while (q--) {
        ll A, B;
        cin >> A >> B;
        cout << solve(A, B) << endl;
    }

    return 0;
}