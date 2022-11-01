#include <bits/stdc++.h>

#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

typedef long long ll;

int ign[4] = {3, 5, 14, 15};
bool bd[16];

int m;
int s[3005];
int f[3005][3005];
int r[3005][3005];

int main() {
    fo(i,0,4) bd[ign[i]] = true;

    scanf("%d", &m);
    fo(i,0,m) scanf("%d", &s[i]);
    fo(i,0,m) fo(j,0,i) {
        if (s[i] == s[j]) {
            if (j) f[i][j] = 1 + f[i-1][j-1];
            else f[i][j] = 1;
        }
    }
    fo(i,0,m+1) fo(j,i,m+1) {
        if (i == j) r[i][j] = 1;
        else if (j-i <= 3) r[i][j] = 1<<(j-i-1);
        else {
            ll mr = 0;
            fo(k,j-3,j) mr += r[i][k];
            int v = 0;
            fo(k,j-4,j) v = (v<<1)|s[k];
            if (!bd[v]) mr += r[i][j-4];
            r[i][j] = mr % MOD;
        }
    }
    ll res = 0;
    fo(i,0,m) {
        int mnl = 1;
        fo(j,0,i) mnl = max(mnl, f[i][j]+1);
        fo(l,mnl,i+2) res += r[i-l+1][i+1];
        printf("%lld\n", res % MOD);
    }
}