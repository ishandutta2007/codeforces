#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int seg[600005][23];
int lazy[600005][23];
int niz[100005][23];

int n;

void init(int node, int l, int r, int bit){
    if(l == r){
        seg[node][bit] = niz[l][bit];
        return;
    }
    int mid = (l+r)/2;
    init(node*2, l, mid, bit);
    init(node*2+1, mid+1, r, bit);
    seg[node][bit] = seg[node*2][bit] + seg[node*2+1][bit];
}

void propagate(int node, int l, int r, int bit){
    lazy[node][bit] %= 2;
    if(lazy[node][bit]){
        seg[node][bit] = r-l+1-seg[node][bit];
        lazy[node][bit] = 0;
        if(l != r){
            lazy[node*2][bit]++;
            lazy[node*2+1][bit]++;
        }
    }
}

void upd(int node, int l, int r, int tl, int tr, int bit){
    propagate(node, l, r, bit);
    if(tl > r || l > tr) return;
    if(tl <= l && r <= tr){
        seg[node][bit] = r-l+1-seg[node][bit];
        if(l != r){
            lazy[node*2][bit]++;
            lazy[node*2+1][bit]++;
        }
        return;
    }
    int mid = (l+r)/2;
    upd(node*2, l, mid, tl, tr, bit);
    upd(node*2+1, mid+1, r, tl, tr, bit);
    seg[node][bit] = seg[node*2][bit] + seg[node*2+1][bit];
}

int query(int node, int l, int r, int tl, int tr, int bit){
    propagate(node, l, r, bit);
    if(tl > r || l > tr) return 0;
    if(tl <= l && r <= tr){
        return seg[node][bit];
    }
    int mid = (l+r)/2;
    return query(node*2, l, mid, tl, tr, bit) + query(node*2+1, mid+1, r, tl, tr, bit);
}

ll resi(int l, int r){
    ll res = 0;
    for(int i=0; i<20; i++){
        ll x = query(1, 1, n, l, r, i);
        x *= (1 << i);
        //cout << x << " ";
        res += x;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        int cnt = 0;
        while(x){
            if(x & 1) niz[i][cnt] = 1;
            x >>= 1;
            cnt++;
        }
    }
    for(int i=0; i<20; i++) init(1, 1, n, i);
    int m;
    cin >> m;
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r;
            cin >> l >> r;
            cout << resi(l, r) << "\n";
        }
        else{
            int l, r, x;
            cin >> l >> r >> x;
            int cnt = 0;
            while(x){
                if(x & 1) upd(1, 1, n, l, r, cnt);
                x >>= 1;
                cnt++;
            }
        }
    }
    return 0;
}