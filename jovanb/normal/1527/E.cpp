#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll lst[35000];
ll pre[35000];

ll dpp[35000];
ll dp[35000];

struct segment{
    ll val, lazy;
} seg[400005];

const ll INF = 1000000000000000LL;

void init(int node, int l, int r){
    seg[node].val = seg[node].lazy = 0;
    if(l == r) return;
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
}

void propagate(int node, int l, int r){
    seg[node].val += seg[node].lazy;
    if(l == r){
        seg[node].lazy = 0;
        return;
    }
    seg[node*2].lazy += seg[node].lazy;
    seg[node*2+1].lazy += seg[node].lazy;
    seg[node].lazy = 0;
}

void upd(int node, int l, int r, int tl, int tr, ll val){
    propagate(node, l, r);
    if(tl > r || l > tr) return;
    if(tl <= l && r <= tr){
        seg[node].lazy += val;
        propagate(node, l, r);
        return;
    }
    int mid = (l+r)/2;
    upd(node*2, l, mid, tl, tr, val);
    upd(node*2+1, mid+1, r, tl, tr, val);
    seg[node].val = min(seg[node*2].val, seg[node*2+1].val);
}

ll query(int node, int l, int r, int tl, int tr){
    if(tl > r || l > tr) return INF;
    propagate(node, l, r);
    if(tl <= l && r <= tr) return seg[node].val;
    int mid = (l+r)/2;
    return min(query(node*2, l, mid, tl, tr), query(node*2+1, mid+1, r, tl, tr));
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        pre[i] = lst[x];
        lst[x] = i;
        dpp[i] = dpp[i-1];
        if(pre[i]) dpp[i] += i - pre[i];
    }
    for(int j=2; j<=k; j++){
        init(1, 0, n);
        upd(1, 0, n, 0, 0, INF);
        for(int i=1; i<=n; i++){
            if(pre[i] > 0){
                upd(1, 0, n, 0, pre[i]-1, i - pre[i]);
            }
            dp[i] = query(1, 0, n, 0, i-1);
            upd(1, 0, n, i, i, dpp[i]);
        }
        for(int i=1; i<=n; i++) dpp[i] = dp[i];
    }
    cout << dpp[n] << "\n";
    return 0;
}