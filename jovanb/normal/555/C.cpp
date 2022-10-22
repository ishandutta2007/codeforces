#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct segment{
    int val;
    int l, r;
    int lazy;
};

vector <segment> seg;

int cnt = 1;

void propagate(int node, int l, int r){
    seg[node].val = max(seg[node].val, seg[node].lazy);
    if(l == r){
        return;
    }
    int levi = seg[node].l;
    int desni = seg[node].r;
    if(levi) seg[levi].lazy = max(seg[levi].lazy, seg[node].lazy);
    if(desni) seg[desni].lazy = max(seg[desni].lazy, seg[node].lazy);
}

int query(int node, int l, int r, int x){
    propagate(node, l, r);
    if(l == r) return seg[node].val;
    int mid = ((ll)l+r)/2;
    if(x <= mid){
        if(!seg[node].l) return seg[node].lazy;
        return query(seg[node].l, l, mid, x);
    }
    else{
        if(!seg[node].r) return seg[node].lazy;
        return query(seg[node].r, mid+1, r, x);
    }
}

void upd(int node, int l, int r, int tl, int tr, int val){
    if(tl > r || l > tr) return;
    propagate(node, l, r);
    if(tl <= l && r <= tr){
        seg[node].lazy = max(seg[node].lazy, val);
        propagate(node, l, r);
        return;
    }
    int mid = ((ll)l+r)/2;
    if(mid >= tl){
        if(!seg[node].l){
            seg[node].l = ++cnt;
            seg.push_back({0, 0, 0, seg[node].lazy});
        }
        upd(seg[node].l, l, mid, tl, tr, val);
    }
    if(mid+1 <= tr){
        if(!seg[node].r){
            seg[node].r = ++cnt;
            seg.push_back({0, 0, 0, seg[node].lazy});
        }
        upd(seg[node].r, mid+1, r, tl, tr, val);
    }
    seg[node].val = max(seg[seg[node].l].val, seg[seg[node].r].val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, q;
    cin >> n >> q;
    seg.push_back({0, 0, 0, 0});
    seg.push_back({0, 0, 0, 0});
    while(q--){
        int j, i;
        cin >> j >> i;
        char c;
        cin >> c;
        if(c == 'U'){
            int k = query(1, 1, 2*n, n+j);
            cout << i-k << "\n";
            upd(1, 1, 2*n, k+1, i, j);
            upd(1, 1, 2*n, n+j, n+j, i);
        }
        else{
            int k = query(1, 1, 2*n, i);
            cout << j-k << "\n";
            upd(1, 1, 2*n, n+k+1, n+j, i);
            upd(1, 1, 2*n, i, i, j);
        }
    }
    return 0;
}