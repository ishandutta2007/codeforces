#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 1;
int a[maxn], L[maxn], R[maxn], ans[maxn];
vector<int> qu[maxn];
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
int added[maxn << 2], sum[maxn << 2], res[maxn];
int ma[maxn << 2];
void build(int v, int tl, int tr){
    if(tl == tr){
        ma[v] = res[tm];
        sum[v] = res[tm] > - maxn;
    }
    else{
        build(ls, tl, tm);
        build(rs, tm + 1, tr);
        ma[v] = max(ma[ls], ma[rs]);
        sum[v] = sum[ls] + sum[rs];
    }
}
int gsum(int v, int tl, int tr, int R){
    if(tr <= R) return sum[v];
    int res = gsum(ls, tl, tm, R);
    if(R > tm) res += gsum(rs, tm + 1, tr, R);
    return res;
}
void add(int v, int d){
    added[v] += d;
    ma[v] += d;
}
void push_down(int v){
    add(ls, added[v]);
    add(rs, added[v]);
    added[v] = 0;
}
int gma(int v, int tl, int tr){
    if(ma[v] <= 0) return maxn;
    if(tl == tr) return tm;
    push_down(v);
    if(ma[ls] > 0) return gma(ls, tl, tm);
    return gma(rs, tm + 1, tr);
}
int fma(int v, int tl, int tr, int p){
    if(tl == tr) return ma[v];
    push_down(v);
    if(p <= tm) return fma(ls, tl, tm, p);
    return fma(rs, tm + 1, tr, p);
}
void add(int v, int tl, int tr, int L){
    if(tl >= L) add(v, 1);
    else{
        push_down(v);
        if(L <= tm) add(ls, tl, tm, L);
        add(rs, tm + 1, tr, L);
        ma[v] = max(ma[ls], ma[rs]);
    }
}
void sub(int v, int tl, int tr, int p){
    if(tl == tr){
        sum[v] = 0;
        ma[v] = -maxn * 10;
    }
    else{
        push_down(v);
        if(p <= tm) sub(ls, tl, tm, p);
        if(p > tm) sub(rs, tm + 1, tr, p);
        sum[v] = sum[ls] + sum[rs];
        ma[v] = max(ma[ls], ma[rs]);
    }
}
void rm(int u, int n){
    auto p = fma(1, 1, n, u);
    if(p <= -maxn) return;
    //cout << u << "sub\n";
    sub(1, 1, n, u);
    if(u == n) return;
    add(1, 1, n, u + 1);
    p = gma(1, 1, n);
    if(p == maxn) return;
    rm(p, n);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        if(i >= a[i]) a[i] = i - a[i];
        else a[i] = n + 1;
    }
    for(int i = 0, x, y; i < q; i += 1){
        cin >> x >> y;
        L[i] = x + 1;
        R[i] = n - y;
        qu[L[i]].push_back(i);
    }
    for(int i = 1, p = 0; i <= n; i += 1){
        res[i] = a[i] - p;
        if(res[i] <= 0) p += 1;
        else res[i] = - maxn * 10;
    }
    build(1, 1, n);
    for(int i : qu[1]) ans[i] = gsum(1, 1, n, R[i]);
    for(int i = 2; i <= n; i += 1){
        rm(i - 1, n);
        //for(int i = 1; i <= n; i += 1) cout << fma(1, 1, n, i) << " ";
        //cout << "\n";
        for(int j : qu[i]) ans[j] = gsum(1, 1, n, R[j]);
    }
    for(int i = 0; i < q; i += 1) cout << ans[i] << "\n";
    return 0;
}