#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

int k;

int sl[10005];
char s[10005];
int n;

int tre[10005][2];
int trc[10005][2];
bool as[2];

int ne[10005], nc[10005];

int go() {
    n = int(strlen(s));

    sl[0] = 0;
    FO(i,1,n+1) {
        int v = s[i-1] - 'a', j;
        for (j = sl[i-1]; j && s[j] != 'a'+v; j = sl[j]);
        if (j+1 != i && s[j] == 'a'+v) sl[i] = j+1;
        else sl[i] = 0;
    }

    FO(i,0,n) {
        int v = s[i] - 'a';
        if (i == n-1) {
            tre[i][v] = sl[n];
            trc[i][v] = 1;
        } else {
            tre[i][v] = i+1;
            trc[i][v] = 0;
        }

        v = !v;
        trc[i][v] = 0;
        if (i == 0) {
            tre[i][v] = 0;
        } else {
            tre[i][v] = tre[sl[i]][v];
        }
    }
    FO(i,0,2) as[i] = false;

    if (k <= 1) return trc[0][k];

    FO(i,2,k+1) {
        as[i&1] = true;
        FO(j,0,n) {
            ne[j] = tre[tre[j][~i&1]][i&1];
            if (j && ne[j] != ne[j-1]) as[i&1] = false;
        }
        FO(j,0,n) {
            nc[j] = trc[j][~i&1] + trc[tre[j][~i&1]][i&1];
            if (nc[j] >= MOD) nc[j] -= MOD;
        }
        FO(j,0,n) tre[j][i&1] = ne[j];
        FO(j,0,n) trc[j][i&1] = nc[j];
    }

    return trc[0][k&1];
}

int main() {
    int m;
    scanf("%d%d", &k, &m); k--;
    FO(Z,0,m) {
        scanf(" %s", s);
        printf("%d\n", go());
    }
}