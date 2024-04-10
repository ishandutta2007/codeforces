#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[1000005];
int n;
int z[1000005];
int dx[1000005];
char ans[1000005];

void zfun() {
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
    z[0] = n;
}

int main() {
    int k; scanf("%d %d", &n, &k);
    scanf(" %s", s);
    zfun();

    for (int l = 1; l*k <= n; l++) {
        bool fail = false;
        FO(i,0,k) {
            int p = i*l;
            if (z[p] < l) {
                fail = true;
                break;
            }
        }
        if (!fail) {
            int pf = min(z[l*k],l);
            dx[max(l*k-1,0)]++;
            dx[min(l*k+pf,n)]--;
        }
    }
    FO(i,1,n) {
        dx[i] += dx[i-1];
    }
    FO(i,0,n) if (dx[i]) ans[i] = '1';
    else ans[i] = '0';
    printf("%s\n", ans);
}