#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct ob {
    int cst;
    int oi;
    int di;

    bool operator<(ob o) const {
        return cst < o.cst;
    }
};

int n;
int t[200005], c[200005];

int s, m, k;
int a[200005][2];
ob o[200005];

bool can(int d) {
    int m[2] = {2000000000, 2000000000};
    int md[2] = {-1,-1};
    FO(i,0,d) {
        FO(j,0,2) {
            if (a[i][j] < m[j]) {
                m[j] = a[i][j];
                md[j] = i;
            }
        }
    }
    FO(i,0,::m) {
        o[i].cst = min(s+1ll, m[t[i]] * 1ll * c[i]);
        o[i].oi = i;
        o[i].di = md[t[i]];
    }
    sort(o,o+::m);
    long long l = 0;
    FO(i,0,k) l += o[i].cst;
    if (l <= s) return true;
    return false;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &s);
    FO(i,0,n) {
        scanf("%d", a[i]);
    }
    FO(i,0,n) {
        scanf("%d", a[i]+1);
    }
    FO(i,0,m) {
        scanf("%d %d", t+i, c+i); t[i]--;
    }
    int b = -1, x = 1, y = n;
    while (x <= y) {
        int md = (x+y)/2;
        if (can(md)) {
            y = md-1;
            b = md;
        } else {
            x = md+1;
        }
    }
    printf("%d\n", b);
    if (b != -1) {
        can(b);
        FO(i,0,k) {
            printf("%d %d\n", o[i].oi+1, o[i].di+1);
        }
    }
}