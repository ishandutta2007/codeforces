#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define X first
#define Y second

const int N = 1005, t[4][4] = {{0, 1, 1, 1}, {0, 0, 2, 0}, {0, 2, 0, 0}, {1, 1, 1, 0}};
const ll M = 998244353;

int n, k;
ll d[N][2 * N][4];

int main(){
    scanf("%d%d", &n, &k);
    d[1][1][0] = d[1][1][3] = d[1][2][1] = d[1][2][2] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= 2 * i; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    d[i][j][k] = (d[i][j][k] + d[i - 1][j - t[l][k]][l]) % M;
                }
            }
        }
    }
    printf("%lld\n", (d[n][k][0] + d[n][k][1] + d[n][k][2] + d[n][k][3]) % M);
    return 0;
}