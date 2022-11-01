#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int u[505][505];
int d[505];
int n, m;
char s[505];

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,m) {
        int x, y;
        scanf("%d%d", &x, &y); x--; y--;
        u[x][y] = u[y][x] = 1;
        d[x]++; d[y]++;
    }
    int f = -1;
    FO(i,0,n) if (d[i] != n-1) {
        f = i;
    }
    if (f == -1) {
        //cpl
        FO(i,0,n) s[i] = 'a';
    } else {
        int t = -1;
        FO(i,0,n) if (i != f && !u[i][f]) {
            t = i;
        }
        s[f] = 'a';
        s[t] = 'c';
        FO(i,0,n) if (i != f && i != t) {
            if (!u[f][i]) {
                s[i] = 'c';
            } else if (!u[t][i]) {
                s[i] = 'a';
            } else {
                s[i] = 'b';
            }
        }
    }
    FO(i,0,n) FO(j,0,n) if (i != j && u[i][j] != (abs(s[i]-s[j]) <= 1)) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n%s\n", s);
}