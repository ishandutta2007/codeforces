#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(n) scanf("%d", &(n))
#define pii pair<int, int>
#define F first
#define S second
const int N = 1e5 + 10, logN = 20;
const int M = 350;
int d[N], h[N], floorlog[N << 1];
ll D[N], F1[N], F2[N], lft[N], rgt[N], total = 0;
map<pii, ll> st;
vector<pii> queries, q; 
pair<int, int> rmq1[logN][N], rmq2[logN][N];
int max(int i, int j, ll f[]){
    return f[i] > f[j] ? i : j;
}
pii merge(pii & x, pii & y, ll f[]){
    if(f[x.F] > f[y.F]){
        return {x.F, max(x.S, y.F, f)};
    }
    if(x.F == y.F){
        return {y.F, max(x.S, y.S, f)};
    }
    return {y.F, max(x.F, y.S, f)};
}
void make_rmq(ll f[], pii rmq[][N], int n){
    for(int i = n; i >= 1; i--){
        rmq[0][i] = {i, 0};
        for(int j = 1; i + (1 << j) - 1 <= n; j++){
            rmq[j][i] = merge(rmq[j - 1][i], rmq[j  - 1][i + (1 << (j - 1))], f);
        }
    }
}
pii get(int i, int j, pii rmq[][N], ll f[]){
    int k = floorlog[j - i + 1];
    return merge(rmq[k][i], rmq[k][j - (1 << k) + 1], f);
}   
ll query(int l, int r){
    pii P = get(l, r, rmq1, F1);
    pii Q = get(l, r, rmq2, F2);
    ll mx = 0;
    if(P.F != Q.F) mx = max(mx, F1[P.F] + F2[Q.F]);
    if(P.S != Q.F) mx = max(mx, F1[P.S] + F2[Q.F]);
    if(P.F != Q.S) mx = max(mx, F1[P.F] + F2[Q.S]);
    if(P.S != Q.S) mx = max(mx, F1[P.S] + F2[Q.S]);
    return mx;
}
int main(){
    for(int i = 0; (1 << i) < N; i++)
        for(int j = (1 << i); j < (1 << (i + 1)); j++)
            floorlog[j] = i;
   int n, m;
   sd(n); sd(m);
   for(int i = 1; i  <= n; i++){
        D[i] = D[i - 1] + d[i - 1];
        sd(d[i]);
        total += d[i];
    }
    for(int i = 1; i  <= n; i++){
        sd(h[i]);
        F1[i] = D[i] + 2 * h[i];
        F2[i] = -D[i] + 2 * h[i];
        rgt[i] = max(rgt[i  - 1], D[i] + 2 * h[i]);
    }
    for(int i = n; i >=  1; i--){
        lft[i] = max(lft[i + 1], total - D[i] + 2 * h[i]);
    }
    F1[0] = -1e18;
    F2[0] = -1e18;
    make_rmq(F1, rmq1, n);
    make_rmq(F2, rmq2, n);
    for(int i = 1; i <= m; i++){
        int a, b;
        sd(a); sd(b);
        q.push_back({a, b});
        if(a > b){
            int l = b + 1, r = a - 1;
            printf("%lld\n", query(l, r));
        }
        else{
            ll ans = 0;
            if(b != n && a != 1) ans = max(ans, lft[b + 1] + rgt[a - 1]);
            if(b != n) ans = max(ans, query(b + 1, n));
            if(a != 1) ans = max(ans, query(1, a - 1));
            printf("%lld\n", ans);
        }
    }
}