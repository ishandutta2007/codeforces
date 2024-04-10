#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

char s[55][55];
int u[1<<20];
double dp[1<<20];
int n,l;
ll shash[55];

ll tmp[1<<20];

void calcu() {
    FO(i,0,n) {
        FO(j,0,n) if (j != i) {
            int common = 0;
            FO(k,0,l) if (s[i][k] == s[j][k]) common |= 1<<k;
            tmp[common] |= 1ll<<i;
        }
    }
    for (int k = (1ll<<l)-1; k >= 0; k--) FO(j,0,l) {
        tmp[k] |= tmp[k|(1ll<<j)];
    }
    FO(i,0,1<<l) FO(j,0,n) if (~tmp[i]&(1ll<<j)) u[i]++;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf(" %s", s[i]);
    }
    l = strlen(s[0]);
    calcu();
    for (int i = (1<<l)-1; i >= 0; i--) {
        if (u[i] == n) dp[i] = 0.;
        else {
            FO(j,0,l) if (~i&(1<<j)) {
                int ni = i|(1<<j);
                dp[i] += ((u[ni]-u[i]) + (n-u[ni]) * (1+dp[ni]));
            }
            dp[i] /= l-__builtin_popcount(i);
            dp[i] /= n-u[i];
        }
    }
    printf("%.14lf\n", dp[0]);
}