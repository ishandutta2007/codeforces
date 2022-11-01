#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
char g[55][55];
char ng[55][55];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf(" %s", g[i]);
    }
    int a=100, b = -1, c = 100, d = -1;
    FO(y,0,n) FO(x,0,n) {
        if (g[y][x] == '4') {
            a = min(a,x);
            b = max(b,x);

            c = min(c,y);
            d = max(d,y);
        }
    }
    if (a > b) {
        printf("No\n");
        return 0;
    }
    FO(y,0,n) FO(x,0,n) {
        ng[y][x] = '0';
        FO(dy,0,2) FO(dx,0,2) {
            int ny = y+dy, nx = x+dx;
            if (a <= nx && nx <= b+1 &&
                    c <= ny && ny <= d+1) {
                ng[y][x]++;
            }
        }
        if (ng[y][x] != g[y][x]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}