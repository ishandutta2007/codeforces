#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

int m, d, n;
char a[2005], b[2005];
int pw[2005];
int c[2005][2005][2][2];

bool ev(int i) {
    return i%2 == 1;
}

int f(int i, int r, bool lb, bool ga) {
    if (i == n) return r == 0;
    else {
        int &res = c[i][r][lb][ga];
        if (res != -1) return res;
        res = 0;
        if (ev(i)) {
            // must d
            if ((lb || d <= b[i]-'0') &&
                    (ga || d >= a[i]-'0')) {
                res = f(i+1, (r+pw[i]*d)%m, lb|| d<b[i]-'0',
                        ga || d>a[i]-'0');
            }
        } else {
            FO(j,0,10) if (d != j) {
                if ((lb || j <= b[i]-'0') &&
                        (ga || j >= a[i]-'0')) {
                    res += f(i+1, (r+pw[i]*j)%m, lb|| j<b[i]-'0',
                            ga || j>a[i]-'0');
                    if (res >= MOD) res -= MOD;
                }
            }
        }
        return res;
    }
}

int main() {
    scanf("%d%d", &m, &d);
    scanf(" %s %s", a, b);
    memset(c,-1,sizeof c);
    n = strlen(a);
    pw[n-1] = 1;
    for (int i = n-2; i >= 0; i--) pw[i] = pw[i+1]*10%m;
    printf("%d\n", f(0, 0, false, false));
}