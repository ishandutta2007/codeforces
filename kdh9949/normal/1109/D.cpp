#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1000005;
const ll M = ll(1e9) + 7;

int n, m;
ll fa[N], fi[N], nn[N], mm[N], r;

ll pw(ll x, ll y){
    if(y == 1) return x;
    return pw(x * x % M, y / 2) * (y % 2 ? x : 1) % M;
}

ll p(ll x, ll y){
    return fa[x] * fi[x - y] % M;
}

ll c(ll x, ll y){
    if(y < 0 || y > x) return 0LL;
    return fa[x] * fi[y] % M * fi[x - y] % M;
}

int main(){
    scanf("%d%d", &n, &m);
    fa[0] = fi[0] = nn[0] = mm[0] = 1;
    for(int i = 1; i < N; i++){
        fa[i] = fa[i - 1] * i % M;
        nn[i] = nn[i - 1] * n % M;
        mm[i] = mm[i - 1] * m % M;
    }
    fi[N - 1] = pw(fa[N - 1], M - 2);
    for(int i = N - 2; i >= 1; i--){
        fi[i] = fi[i + 1] * (i + 1) % M;
    }
    for(int k = 1; k <= n - 1; k++){
        r += p(n - 2, k - 1) * c(m - 1, m - k) % M
             * mm[n - 1 - k] % M * (k == n - 1 ? 1 : (k + 1) * nn[n - 2 - k] % M) % M;
    }
    printf("%lld\n", r % M);
}