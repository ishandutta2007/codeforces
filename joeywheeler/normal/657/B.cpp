#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll a[400005];
int n; ll k;
ll b[400005];

bool eval() {
    FO(i,0,400005) b[i] = 0;
    FO(i,0,400002) {
        b[i] += a[i];
        if (b[i] >= 0) {
            b[i+1] += b[i]/2;
            b[i] %= 2;
        } else {
            b[i+1] += (b[i]-1)/2;
            if (b[i]%2) b[i] = 1;
            else b[i] = 0;
        }
    }
    if (b[400001]) return false;
    return true;
}

int main() {
    scanf("%d%lld", &n, &k);
    FO(i,0,n+1) scanf("%lld", &a[i]);
    if (!eval()) {
        FO(i,0,n+1) a[i] *= -1;
        assert(eval());
    }
    int ld = -1, fd = -1;
    FO(i,0,400005) {
        if (b[i]) {
            ld = i;
            if (fd == -1) fd = i;
        }
    }
    int res = 0;
    FO(i,0,n+1) {
        if (fd < i) break;
        if (ld > i+50) continue;
        ll vl = 0;
        FO(j,i,i+51) {
            vl += b[j] << (j-i);
        }
        if (abs(a[i]-vl) <= k && (i < n || a[i]-vl != 0)) {
            res++;
        }
    }
    printf("%d\n", res);
}