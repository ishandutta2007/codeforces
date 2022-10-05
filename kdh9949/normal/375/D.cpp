#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 200005, Q = 320;

struct Qry{ int s, e, x, i; } v[N];
int n, q, a[N], b[N], ps[N], pe[N], pc, c[N], ans[N];
vector<int> e[N];

struct BIT{
    int d[M];
    void u(int x, int v){ for(x += N; x < M; x += x & -x) d[x] += v; }
    int g(int x){ int r = 0; for(x += N; x; x -= x & -x) r += d[x]; return r; }
} B;

void f(int x, int y){
    ps[x] = ++pc;
    b[pc] = a[x];
    for(int i : e[x]) if(i != y) f(i, x);
    pe[x] = pc;
}

void u(int x, int v){
    B.u(c[x], -1);
    c[x] += v;
    B.u(c[x], 1);
}

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 0, x, y; i < n - 1; i++){
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    f(1, 0);
    for(int i = 0, x, y; i < q; i++){
        scanf("%d%d", &x, &y);
        v[i] = {ps[x], pe[x], y, i};
    }
    B.u(0, N);
    sort(v, v + q, [](Qry a, Qry b){
        return (a.s / Q == b.s / Q) ? (a.e < b.e) : (a.s < b.s);
    });
    int cs = 1, ce = 0;
    for(int i = 0; i < q; i++){
        int ns = v[i].s, ne = v[i].e;
        for(; cs < ns; ) u(b[cs++], -1);
        for(; cs > ns; ) u(b[--cs], 1);
        for(; ce < ne; ) u(b[++ce], 1);
        for(; ce > ne; ) u(b[ce--], -1);
        ans[v[i].i] = N - B.g(v[i].x - 1);
    }
    for(int i = 0; i < q; i++) printf("%d\n", ans[i]);
}