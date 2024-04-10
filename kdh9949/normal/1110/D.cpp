#include <bits/stdc++.h>
using namespace std;

const int N = 1000005, INF = int(1e9);

int n, m, c[N], d[2][9][9], rr, r;

void u(int x, int y, int z, int v){
    d[x][y][z] = max(d[x][y][z], v);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        c[x]++;
        if(c[x] > 8){
            rr++;
            c[x] -= 3;
        }
    }
    for(int i = 0; i < 9; i++) for(int j = 0; j < 9; j++)
        d[0][i][j] = d[1][i][j] = -INF;
    d[0][c[1]][c[2]] = 0;
    for(int i = 2, p = 0; i <= m; i++, p ^= 1){
        for(int j = 0; j < 9; j++) for(int k = 0; k < 9; k++) d[!p][j][k] = -INF;
        int cd, t;
        for(int j = c[i - 1]; j >= 0; j--){
            for(int k = c[i]; k >= 0; k--){
                cd = d[p][j][k];
                if(j) u(p, j - 1, k, cd);
                if(k) u(p, j, k - 1, cd);
                if(j >= 3) u(p, j - 3, k, cd + 1);
                if(k >= 3) u(p, j, k - 3, cd + 1);
                if(j && k){
                    t = min({j, k, c[i + 1]});
                    u(!p, k - t, c[i + 1] - t, cd + t);
                }
                u(!p, k, c[i + 1], cd);
            }
        }
    }
    for(int i = 0; i < 9; i++) for(int j = 0; j < 9; j++)
        r = max(r, d[m & 1][i][j]);
    printf("%d\n", r + rr);
}