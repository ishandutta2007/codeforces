#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2005;
const ll M = 998244353;

int n, m, k;
ll d[N][N];

int main(){
    scanf("%d%d%d", &n, &m, &k);
    d[1][0] = m;
    for(int i = 2; i <= n; i++){
        d[i][0] = d[i-1][0];
        for(int j = 1; j <= k; j++){
            d[i][j] = (d[i-1][j] + (m-1)*d[i-1][j-1]) % M;
        }
    }
    printf("%lld\n", d[n][k]);
}