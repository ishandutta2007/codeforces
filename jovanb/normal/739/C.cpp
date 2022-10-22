#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 300000;

struct segment{
    ll lval, rval;
    int mx, mxl, mxr;
    int cnl, cnr;
    ll lazy;
} seg[4*MAXN+5];

ll a[MAXN+5];

void mrg(int node, int l, int r){
    int mid = (l+r)/2;
    seg[node].lval = seg[node*2].lval;
    seg[node].rval = seg[node*2+1].rval;
    seg[node].mx = max(seg[node*2].mx, seg[node*2+1].mx);
    if(seg[node*2].rval > seg[node*2+1].lval) seg[node].mx = max(seg[node].mx, seg[node*2].mxr + seg[node*2+1].cnl);
    if(seg[node*2].rval < seg[node*2+1].lval) seg[node].mx = max(seg[node].mx, seg[node*2+1].mxl + seg[node*2].cnr);
    seg[node].mxl = seg[node*2].mxl;
    if(seg[node*2].mxl == mid-l+1 && seg[node*2].rval > seg[node*2+1].lval) seg[node].mxl = seg[node*2].mxl + seg[node*2+1].cnl;
    if(seg[node*2].cnr == mid-l+1 && seg[node*2].rval < seg[node*2+1].lval) seg[node].mxl = max(seg[node].mxl, seg[node*2].cnr + seg[node*2+1].mxl);
    seg[node].mxr = seg[node*2+1].mxr;
    if(seg[node*2+1].mxr == r-mid && seg[node*2].rval < seg[node*2+1].lval) seg[node].mxr = seg[node*2+1].mxr + seg[node*2].cnr;
    if(seg[node*2+1].cnl == r-mid && seg[node*2].rval > seg[node*2+1].lval) seg[node].mxr = max(seg[node].mxr, seg[node*2+1].cnl + seg[node*2].mxr);
    seg[node].cnl = seg[node*2].cnl;
    if(seg[node*2].cnl == mid-l+1 && seg[node*2].rval > seg[node*2+1].lval) seg[node].cnl = seg[node*2].cnl + seg[node*2+1].cnl;
    seg[node].cnr = seg[node*2+1].cnr;
    if(seg[node*2+1].cnr == r-mid && seg[node*2].rval < seg[node*2+1].lval) seg[node].cnr = seg[node*2+1].cnr + seg[node*2].cnr;
}

void init(int node, int l, int r){
    if(l == r){
        seg[node].lval = seg[node].rval = a[l];
        seg[node].cnl = seg[node].cnr = seg[node].mx = seg[node].mxl = seg[node].mxr = 1;
        return;
    }
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
    mrg(node, l, r);
}

void propagate(int node, int l, int r){
    seg[node].lval += seg[node].lazy;
    seg[node].rval += seg[node].lazy;
    if(l == r){
        seg[node].lazy = 0;
        return;
    }
    seg[node*2].lazy += seg[node].lazy;
    seg[node*2+1].lazy += seg[node].lazy;
    seg[node].lazy = 0;
}

void upd(int node, int l, int r, int tl, int tr, int val){
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
    mrg(node, l, r);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    init(1, 1, n);
    int q;
    cin >> q;
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        upd(1, 1, n, l, r, x);
        cout << seg[1].mx << "\n";
    }
    return 0;
}