#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn = 2e6+5;
namespace playf{
    int bit[maxn];
    void add(int i, int x){
        while(i < maxn) bit[i] += x, i += lowbit(i);
    }
    int qry(int i){
        int res = 0; while(i) res += bit[i], i -= lowbit(i);
        return res;
    }
    int cc[maxn], num;
    ll sol(int a[], int n){
        num = 0;
        fors(i,1,n+1) {
            cc[++num] = a[i];
        }
        sort(cc+1, cc+1+num); num = unique(cc+1,cc+1+num)-cc-1;
        ll ans = 0;
        for(int i = 1; i <= n; ++i){
            int p = lower_bound(cc+1,cc+1+num, a[i])-cc;
            ans += qry(num)-qry(p); add(p, 1);
        }
        fors(i,1,n+1) {
            int p = lower_bound(cc+1,cc+1+num, a[i])-cc;
            add(p, -1);
        }
        assert(bit[maxn-1] == 0);
        return ans;
    }
}
int n, m, a[maxn], b[maxn];
void init(){
    scanf("%d%d", &n, &m);
    fors(i,1,n+1) scanf("%d", &a[i]);
    fors(i,1,m+1) scanf("%d", &b[i]);
}
int mi[maxn<<2], lz[maxn<<2];
void up(int rt){
    mi[rt] = min(mi[rt<<1], mi[rt<<1|1]);
    return;
}
void down(int rt){
    mi[rt<<1] += lz[rt]; lz[rt<<1] += lz[rt];
    mi[rt<<1|1] += lz[rt]; lz[rt<<1|1] += lz[rt];
    lz[rt] = 0; return;
}
void build(int rt, int l, int r){
    mi[rt] = lz[rt] = 0;
    if(l == r){
        mi[rt] = l; return;
    }
    build(lson); build(rson); up(rt);
    return;
}
void update(int rt, int l, int r, int L, int R, int x){
    if(L <= l && r <= R){
        mi[rt] += x; lz[rt] += x;
        return;
    }
    down(rt);
    if(L<=mid) update(lson, L, R, x);
    if(R>mid) update(rson, L, R, x);
    up(rt);
}
void sol(){
    sort(b+1, b+1+m);
    ll ans = playf::sol(a, n);
    vector<int> id;
    fors(i,1,n+1) id.pb(i);
    sort(all(id), [&](int x, int y){ return a[x]<a[y]; });
    build(1, 0, n);
    int p1 = 0, p2 = 0;
    for(int i = 1; i <= m; ++i){
        while(p1 < n && a[id[p1]] < b[i]){
            update(1, 0, n, 0, id[p1]-1, 1);
            p1++;
        }
        while(p2 < n && a[id[p2]] <= b[i] ){
            update(1, 0, n, id[p2], n, -1);
            p2++;
        }
        ans += mi[1];
    }
    printf("%lld\n", ans);
}
int main(){
    int T; cin>>T;
    while(T--){
        init(); sol();
    }
    return 0;
}