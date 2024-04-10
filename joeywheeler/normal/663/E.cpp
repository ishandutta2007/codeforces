#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[20][100005];
int n, m;
int dp[1<<19][20];
int ndp[1<<19][20];

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,n) scanf("%s", s[i]);
    FO(i,0,m) {
        int x = 0;
        FO(j,0,n) if (s[j][i] == '1') x |= 1<<j;
        if (x & (1<<(n-1))) x = x^((1<<n)-1);
        dp[x][0]++;
    }
    auto cur = dp, prv = ndp;
    FO(i,1,n) {
        swap(cur,prv);
        // calculate cur from prv
        FO(x,0,1<<(n-1)) {
            FO(d,0,i+1) {
                // diff of d bits in the suf of len i, pref of len (n-1)-i is same
                cur[x][d] = prv[x][d];
                if (d) cur[x][d] += prv[x^(1<<(i-1))][d-1];
            }
        }
    }
    int res = 1e9;
    FO(x,0,1<<(n-1)) {
        int a = 0;
        FO(i,0,n) a += cur[x][i] * min(i,n-i);
        res = min(res,a);
    }
    printf("%d\n", res);
}