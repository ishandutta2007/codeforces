#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;
const int M = 1000000;
const int INF = 1000000000;

struct Segment{
    int mx, lazy;
} seg[4*M+5];

void propagate(int node, int l, int r){
    seg[node].mx = min(seg[node].mx, seg[node].lazy);
    if(l == r){
        seg[node].lazy = INF;
        return;
    }
    seg[node*2].lazy = min(seg[node*2].lazy, seg[node].lazy);
    seg[node*2+1].lazy = min(seg[node*2+1].lazy, seg[node].lazy);
    seg[node].lazy = INF;
}

void init(int node, int l, int r){
    seg[node].lazy = INF;
    seg[node].mx = INF;
    if(l == r) return;
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
}

void upd(int node, int l, int r, int tl, int tr, int val){
    propagate(node, l, r);
    if(tl > r || l > tr) return;
    if(tl <= l && r <= tr){
        seg[node].lazy = val;
        propagate(node, l, r);
        return;
    }
    int mid = (l+r)/2;
    upd(node*2, l, mid, tl, tr, val);
    upd(node*2+1, mid+1, r, tl, tr, val);
    seg[node].mx = max(seg[node*2].mx, seg[node*2+1].mx);
}

vector <pair <int, int>> vec[M+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    m--;
    for(int i=1; i<=n; i++){
        int l, r, w;
        cin >> l >> r >> w;
        vec[w].push_back({l, r-1});
    }
    init(1, 1, m);
    int res = M;
    for(int i=M; i>=1; i--){
        for(auto c : vec[i]){
            upd(1, 1, m, c.first, c.second, i);
        }
        res = min(res, seg[1].mx - i);
    }
    cout << res << "\n";
    return 0;
}