#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int nxt[1005*55][10];
int n;

char s[1005];
int ln;
int loc[1005][1005];
int dep[1005*55];

char x[55];
int d;
bool alloweq;

#define MOD 1000000007
int cache[55][1005*55][2][2];

int go(int di, int nd, int md, int ce) {
    md |= dep[nd] >= d/2;
    if (di == d) return md && (alloweq || ce == 0);
    if (cache[di][nd][md][ce] != -1) return cache[di][nd][md][ce];
    int uv = 9;
    if (ce) uv = x[di]-'0';
    long long res = 0;
    FO(v,0,uv+1) res += go(di+1, nxt[nd][v], md, ce && v==uv);
    return cache[di][nd][md][ce] = res % MOD;
}

int main() {
    scanf(" %s", s);
    ln = strlen(s);
    FO(i,0,ln) {
        int c = 0;
        FO(j,i,ln) {
            int v = s[j]-'0';
            if (!nxt[c][v]) {
                nxt[c][v] = ++n;
            }
            c = nxt[c][v];
            loc[i][j] = c;
            dep[c] = j-i+1;
            if (dep[c] > 50) break;
        }
    }
    FO(dij,0,ln+1) FO(i,0,ln) {
        int j = i+dij;
        if (j < ln) {
            FO(v,0,10) {
                if (!nxt[loc[i][j]][v]) {
                    nxt[loc[i][j]][v] = nxt[loc[i+1][j]][v];
                }
            }
        }
    }
    scanf(" %s", x);
    d = strlen(x);
    memset(cache,-1,sizeof cache);
    alloweq = false;
    int tmp = go(0,0,0,1);
    scanf(" %s", x);
    memset(cache,-1,sizeof cache);
    alloweq = true;
    int tmp2 = go(0,0,0,1);

    printf("%d\n", (tmp2-tmp+MOD)%MOD);
}