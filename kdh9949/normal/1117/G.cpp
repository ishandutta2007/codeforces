#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1000005, SZ = 1048576;

struct Qry{ int i, s, e, x; };

int n, q, a[N], s[N], e[N], qs[N], qe[N], cnt;
Qry v[6 * N];
ll ans[N];

struct MSeg{
    int d[2 * SZ];
    void i(){
        for(int i = 1; i <= n; i++) d[i + SZ] = i;
        for(int i = SZ - 1; i; i--){
            if(a[d[2 * i]] > a[d[2 * i + 1]]) d[i] = d[2 * i];
            else d[i] = d[2 * i + 1];
        }
    }
    int g(int s, int e){
        int r = 0;
        for(s += SZ, e += SZ; s <= e; s >>= 1, e >>= 1){
            if( s & 1){
                if(a[r] < a[d[s]]) r = d[s];
                s++;
            }
            if(~e & 1){
                if(a[r] < a[d[e]]) r = d[e];
                e--;
            }
        }
        return r;
    }
} M;

struct BIT{
    ll d[N];
    void u(int x, ll v){ for(; x < N; x += x & -x) d[x] += v; }
    void u(int s, int e, ll v){ u(s, v); u(e + 1, -v); }
    ll g(int x){ ll r = 0; for(; x; x -= x & -x) r += d[x]; return r; }
} A, B, C;

void f(){
    int x = M.g(1, n);
    queue<int> q;
    s[x] = 1;
    e[x] = n;
    q.push(x);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        if(s[c] < c){
            int lm = M.g(s[c], c - 1);
            s[lm] = s[c];
            e[lm] = c - 1;
            q.push(lm);
        }
        if(c < e[c]){
            int rm = M.g(c + 1, e[c]);
            s[rm] = c + 1;
            e[rm] = e[c];
            q.push(rm);
        }
    }
}

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    M.i();
    f();
    for(int i = 1; i <= n; i++){
        A.u(e[i] + 1, n, e[i]);
        v[cnt++] = {4 * i + 4, e[i] + 1, n, -e[i]};
        B.u(i, e[i], 1);
        v[cnt++] = {4 * i + 5, i, e[i], -1};
        A.u(i, n, -s[i]);
        v[cnt++] = {4 * s[i], i, n, s[i]};
        v[cnt++] = {4 * s[i] + 2, i, n, -1};
        v[cnt++] = {4 * i + 6, i, n, 1};
    }
    for(int i = 1; i <= q; i++) scanf("%d", qs + i);
    for(int i = 1; i <= q; i++) scanf("%d", qe + i);
    for(int i = 1; i <= q; i++) v[cnt++] = {4 * qs[i] + 3, qs[i], qe[i], i};
    sort(v, v + cnt, [](Qry p, Qry q){ return p.i < q.i; });
    for(int i = 1, k = 0; i <= n; i++){
        for(; v[k].i / 4 == i; k++){
            Qry j = v[k];
            if(j.i % 4 == 0) A.u(j.s, j.e, j.x);
            else if(j.i % 4 == 1) B.u(j.s, j.e, j.x);
            else if(j.i % 4 == 2) C.u(j.s, j.e, j.x);
            else{
                ans[j.x] += A.g(j.e);
                ans[j.x] += B.g(j.e) * j.e;
                ans[j.x] += C.g(j.e) * j.s;
                ans[j.x] += (j.e - j.s + 1);
            }
        }
    }
    for(int i = 1; i <= q; i++) printf("%lld ", ans[i]);
    puts("");
}