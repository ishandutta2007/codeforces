#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

typedef long long ll;
typedef long double ld;

struct drvo{
    int res;
    int l;
    int r;
    int tren;
    int ot;
    int zt;
} seg[4000005];

string s;

void init(int node, int l, int r){
    if(l == r){
        if(s[l-1] == '(') seg[node].l = 1;
        else seg[node].r = 1;
        return;
    }
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
    int p = node*2;
    int d = node*2+1;
    int mn = min(seg[p].l, seg[d].r);
    seg[node].res = seg[p].res+seg[d].res+2*mn;
    seg[node].l = seg[p].l+seg[d].l-mn;
    seg[node].r = seg[p].r+seg[d].r-mn;
}

void query(int node, int l, int r, int tl, int tr){
    seg[node].tren = 0;
    seg[node].ot = 0;
    seg[node].zt = 0;
    if(l > tr || r < tl) return;
    if(l == r){
        if(seg[node].l) seg[node].ot = 1;
        else seg[node].zt = 1;
        return;
    }
    if(tl <= l && r <= tr){
        seg[node].tren = seg[node].res;
        seg[node].ot = seg[node].l;
        seg[node].zt = seg[node].r;
        return;
    }
    int p = node*2;
    int d = node*2+1;
    int mid = (l+r)/2;
    query(p, l, mid, tl, tr);
    query(d, mid+1, r, tl, tr);
    int mn = min(seg[p].ot, seg[d].zt);
    seg[node].tren = seg[p].tren+seg[d].tren+2*mn;
    seg[node].ot = seg[p].ot+seg[d].ot-mn;
    seg[node].zt = seg[p].zt+seg[d].zt-mn;
    return;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    cin >> s;
    int n = s.size();
    init(1, 1, n);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        query(1, 1, n, l, r);
        cout << seg[1].tren << "\n";
    }
    return 0;
}