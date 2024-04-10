#include <bits/stdc++.h>
using namespace std;

struct sg{
    int gcd;
    int mn;
    int cnt;
} seg[1000000];

int niz[100005];

const int INF = 1000000009;

void init(int node, int l, int r){
    if(l == r){
        seg[node].gcd = niz[l];
        seg[node].cnt = 1;
        seg[node].mn = niz[l];
        return;
    }
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
    seg[node].gcd = __gcd(seg[node*2].gcd, seg[node*2+1].gcd);
    seg[node].mn = min(seg[node*2].mn, seg[node*2+1].mn);
    if(seg[node].mn == seg[node*2].mn) seg[node].cnt += seg[node*2].cnt;
    if(seg[node].mn == seg[node*2+1].mn) seg[node].cnt += seg[node*2+1].cnt;
}

int gcdquery(int node, int l, int r, int tl, int tr){
    if(tl > r || l > tr) return 0;
    if(tl <= l && r <= tr){
        return seg[node].gcd;
    }
    int mid = (l+r)/2;
    return __gcd(gcdquery(node*2, l, mid, tl, tr), gcdquery(node*2+1, mid+1, r, tl, tr));
}

pair <int, int> minquery(int node, int l, int r, int tl, int tr){
    if(tl > r || l > tr) return make_pair(INF, 0);
    if(tl <= l && r <= tr){
        return make_pair(seg[node].mn, seg[node].cnt);
    }
    int mid = (l+r)/2;
    pair <int, int> a = minquery(node*2, l, mid, tl, tr);
    pair <int, int> b = minquery(node*2+1, mid+1, r, tl, tr);
    int mn = min(a.first, b.first);
    int br=0;
    if(a.first == mn) br += a.second;
    if(b.first == mn) br += b.second;
    return make_pair(mn, br);
}

int main(){

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    init(1, 1, n);
    int m;
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        int nzd = gcdquery(1, 1, n, l, r);
        pair <int, int> x = minquery(1, 1, n, l, r);
        int mn = x.first;
        int cnt = x.second;
        if(mn == nzd) cout << r-l+1-cnt << "\n";
        else cout << r-l+1 << "\n";
    }
    return 0;
}