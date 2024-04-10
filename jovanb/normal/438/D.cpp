#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct segment{
    ll val, mx;
} seg[500005];

int niz[100005];

void upd(int node, int l, int r, int x, int val){
    if(l == r){
        seg[node].val = val;
        seg[node].mx = l;
        niz[l] = val;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid){
        upd(node*2, l, mid, x, val);
    }
    else upd(node*2+1, mid+1, r, x, val);
    seg[node].val = seg[node*2].val + seg[node*2+1].val;
    seg[node].mx = seg[node*2].mx;
    if(niz[seg[node].mx] < niz[seg[node*2+1].mx]) seg[node].mx = seg[node*2+1].mx;
}

ll getsum(int node, int l, int r, int tl, int tr){
    if(tl > r || l > tr) return 0;
    if(tl <= l && r <= tr){
        return seg[node].val;
    }
    int mid = (l+r)/2;
    return getsum(node*2, l, mid, tl, tr) + getsum(node*2+1, mid+1, r, tl, tr);
}

int getmax(int node, int l, int r, int tl, int tr){
    if(tl > r || l > tr) return 0;
    if(tl <= l && r <= tr){
        return seg[node].mx;
    }
    int mid = (l+r)/2;
    int a = getmax(node*2, l, mid, tl, tr);
    int b = getmax(node*2+1, mid+1, r, tl, tr);
    if(niz[a] > niz[b]) return a;
    else return b;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;
    niz[0] = -500;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        upd(1, 1, n, i, niz[i]);
    }
    while(m--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;
            cout << getsum(1, 1, n, l, r) << "\n";
        }
        else if(type == 2){
            int l, r, x;
            cin >> l >> r >> x;
            int k = 0;
            while(niz[k = getmax(1, 1, n, l, r)] >= x){
                niz[k] %= x;
                upd(1, 1, n, k, niz[k]);
            }
        }
        else{
            int k, x;
            cin >> k >> x;
            niz[k] = x;
            upd(1, 1, n, k, niz[k]);
        }
    }
    return 0;
}