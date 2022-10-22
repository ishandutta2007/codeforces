#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int p[200005];

ll res = 1e18;

struct segment{
    ll mn;
    ll lazy;
} seg[1000005];

void propagate(int node, int l, int r){
    seg[node].mn += seg[node].lazy;
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
    seg[node].mn = min(seg[node*2].mn, seg[node*2+1].mn);
}

int cost[200005];

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    for(int i=1; i<=n; i++){
        cin >> cost[i];
        upd(1, 1, n+1, p[i]+1, n+1, cost[i]);
    }
    for(int i=1; i<n; i++){
        upd(1, 1, n+1, p[i]+1, n+1, -cost[i]);
        upd(1, 1, n+1, 1, p[i], cost[i]);
        res = min(res, seg[1].mn);
        //cout << seg[1].mn << "\n";
    }
    cout << res;
    return 0;
}