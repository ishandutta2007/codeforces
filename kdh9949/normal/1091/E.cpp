#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 500005, sz = 524288;
const ll inf = ll(1e18);

struct Seg{
    ll d[2 * sz];
    void i(){ fill(d + 1, d + 2 * sz, -inf); }
    void u(int x, ll v){
        x += sz;
        d[x] = max(d[x], v);
        for(x >>= 1; x; x >>= 1) d[x] = max(d[2 * x], d[2 * x + 1]);
    }
    ll g(int s, int e){
        ll r = -inf;
        for(s += sz, e += sz; s <= e; s >>= 1, e >>= 1){
            if( s & 1) r = max(r, d[s++]);
            if(~e & 1) r = max(r, d[e--]);
        }
        return r;
    }
} S, T, U;

int n, q;
ll a[N], b[N], v[N], w[N], ds;

ll f(int i, ll k){
    if(i > n) return 0LL;
    int t = int(lower_bound(a + i, a + n + 1, k, greater<int>()) - a);
    return b[n] - b[t - 1] + 1LL * k * (t - i);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", a + i);
        ds += a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
    S.i();
    T.i();
    U.i();
    for(int i = 1; i <= n; i++){
        v[i] = b[i] - f(i + 1, i) - 1LL * i * (i - 1);
        w[i] = b[i] - f(i + 1, i + 1) - 1LL * (i + 1) * i;
        S.u(i, v[i] - i);
        T.u(i, v[i]);
        U.u(i, w[i]);
    }
    a[0] = n + 1;
    for(int i = n; i >= 0; i--){
        for(int x = a[i + 1]; x < a[i]; x++){
            if((ds + x) & 1) continue;
            if(min(i, x) >= 1 && S.g(1, min(i, x)) > 0) continue;
            if(max(1, x) <= i && T.g(max(1, x), i) > x) continue;
            if(b[i] + x > 1LL * (i + 1) * i + f(i + 1, i + 1)) continue;
            if(i < n && U.g(i + 1, n) > -x) continue;
            printf("%d ", x);
            q = 1;
        }
    }
    if(!q) puts("-1");
}