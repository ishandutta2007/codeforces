#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll dp[35005][55];
int pre[35005];
int niz[35005];

struct segment{
    ll val;
    ll lazy;
} seg[1000005];

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

void upd(int node, int l, int r, int tl, int tr){
    propagate(node, l, r);
    if(tl > r || l > tr) return;
    if(tl <= l && r <= tr){
        seg[node].lazy++;
        propagate(node, l, r);
        return;
    }
    int mid = (l+r)/2;
    upd(node*2, l, mid, tl, tr);
    upd(node*2+1, mid+1, r, tl, tr);
    seg[node].val = max(seg[node*2].val, seg[node*2+1].val);
}

int query(int node, int l, int r, int tl, int tr){
    propagate(node, l, r);
    if(tl > r || l > tr){
        return 0;
    }
    if(tl <= l && r <= tr){
        return seg[node].val;
    }
    int mid = (l+r)/2;
    return max(query(node*2, l, mid, tl, tr), query(node*2+1, mid+1, r, tl, tr));
}

void init(int node, int l, int r, int koji){
    seg[node].lazy = 0;
    if(l == r){
        seg[node].val = dp[l][koji];
        return;
    }
    int mid = (l+r)/2;
    init(node*2, l, mid, koji);
    init(node*2+1, mid+1, r, koji);
    seg[node].val = max(seg[node*2].val, seg[node*2+1].val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    for(int i=1; i<=n; i++){
        dp[i][1] = dp[i-1][1];
        if(!pre[niz[i]]){
            dp[i][1]++;
        }
        pre[niz[i]] = i;
    }
    for(int j=2; j<=k; j++){
        init(1, 1, n, j-1);
        for(int i=1; i<=n; i++){
            pre[niz[i]] = 0;
        }
        for(int i=1; i<=n; i++){
            upd(1, 1, n, pre[niz[i]], i-1);
            dp[i][j] = query(1, 1, n, 1, i-1);
            pre[niz[i]] = i;
        }
    }
    cout << dp[n][k];
    return 0;
}