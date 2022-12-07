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

const int N = 200111;

int n;
ll a[N];
int where[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = a[i - 1] + x;
    }

    for (int i = n; i >= k; --i) {
        a[i] -= a[i - k];
    }

    int A = 1, B = k + 1;
    ll res = a[k] + a[k + k];
    where[k] = k;
    for (int i = k + 1; i <= n; ++i) {
        if (i >= k + k) {
            ll cand = a[i] + a[i - k];
            ll ca = where[i - k] - k + 1, cb = i - k + 1;
            if (cand > res || (cand == res && ca < A) || (cand == res && ca == A && cb < B)) {
                res = cand;
                A = ca;
                B = cb;
            }
        }
        if (a[i] > a[i - 1]) {
            where[i] = i;
         } else {
            where[i] = where[i - 1];
            a[i] = a[i - 1];
         }
    }

    cout << A << " " << B << endl;

    return 0;
}