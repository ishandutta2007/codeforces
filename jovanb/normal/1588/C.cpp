#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;
const ll INF = 10000000000000000LL;

struct Segment{
    ll mn[4*N+5], cnt[4*N+5], lazy[4*N+5];
    void propagate(int node, int l, int r){
        mn[node] += lazy[node];
        if(l == r){
            lazy[node] = 0;
            return;
        }
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
        lazy[node] = 0;
    }
    pair <ll, int> mrg(pair <ll, int> n1, pair <ll, int> n2){
        ll m = min(n1.first, n2.first);
        int cn = n1.second*(n1.first == m) + n2.second*(n2.first == m);
        return {m, cn};
    }
    void init(int node, int l, int r, ll *arr){
        lazy[node] = 0;
        if(l == r){
            mn[node] = arr[l];
            cnt[node] = 1;
            return;
        }
        int mid = (l+r)/2;
        init(node*2, l, mid, arr);
        init(node*2+1, mid+1, r, arr);
        tie(mn[node], cnt[node]) = mrg({mn[node*2], cnt[node*2]}, {mn[node*2+1], cnt[node*2+1]});
    }
    int dokle(int node, int l, int r){
        propagate(node, l, r);
        if(l == r){
            if(mn[node] >= 0) return l;
            return l - 1;
        }
        int mid = (l+r)/2;
        propagate(node*2, l, mid);
        propagate(node*2+1, mid+1, r);
        if(mn[node*2] >= 0) return dokle(node*2+1, mid+1, r);
        return dokle(node*2, l, mid);
    }
    pair <ll, int> query(int node, int l, int r, int tl, int tr){
        propagate(node, l, r);
        if(tl > r || l > tr) return {INF, 0};
        if(tl <= l && r <= tr) return {mn[node], cnt[node]};
        int mid = (l+r)/2;
        return mrg(query(node*2, l, mid, tl, tr), query(node*2+1, mid+1, r, tl, tr));
    }
    void upd(int node, int l, int r, int tl, int tr, ll val){
        propagate(node, l, r);
        if(tl > r || l > tr) return;
        if(tl <= l && r <= tr){
            lazy[node] += val;
            propagate(node, l, r);
            return;
        }
        int mid = (l+r)/2;
        upd(node*2, l, mid, tl, tr, val);
        upd(node*2+1, mid+1, r, tl, tr, val);
        tie(mn[node], cnt[node]) = mrg({mn[node*2], cnt[node*2]}, {mn[node*2+1], cnt[node*2+1]});
    }
} seg[2];

ll a[N+5], b[N+5];
ll c[N+5], d[N+5];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    b[0] = 0;
    for(int i=1; i<=n; i++){
        b[i] = a[i] - b[i-1];
        if(i%2) c[i] = b[i], d[i] = INF;
        else c[i] = INF, d[i] = b[i];
    }
    seg[1].init(1, 1, n, c);
    seg[0].init(1, 1, n, d);
    ll res = 0;
    for(int i=1; i<=n; i++){
        int x = min(seg[0].dokle(1, 1, n), seg[1].dokle(1, 1, n));
        pair <ll, int> k = seg[0].query(1, 1, n, i, x);
        if(k.first == 0) res += k.second;
        k = seg[1].query(1, 1, n, i, x);
        if(k.first == 0) res += k.second;
        seg[i%2].upd(1, 1, n, i, n, -a[i]);
        seg[1 ^ (i%2)].upd(1, 1, n, i, n, a[i]);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}