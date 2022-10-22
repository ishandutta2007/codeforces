#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;
const int VAL = 1000000;

struct Segment{
    int maxsuf, sum;
} seg[4*VAL+5];

void mrg(int node){
    seg[node].sum = seg[node*2].sum + seg[node*2+1].sum;
    seg[node].maxsuf = max(seg[node*2+1].maxsuf, seg[node*2+1].sum + seg[node*2].maxsuf);
}

void upd(int node, int l, int r, int x, int val){
    if(l == r){
        seg[node].sum += val;
        seg[node].maxsuf = seg[node].sum;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid) upd(node*2, l, mid, x, val);
    else upd(node*2+1, mid+1, r, x, val);
    mrg(node);
}

int a[N+5];
int b[N+5];

int query(int node, int l, int r, int d){
    if(l == r){
        if(d + seg[node].maxsuf <= 0) return -1;
        return l;
    }
    int mid = (l+r)/2;
    if(d + seg[node*2+1].maxsuf > 0) return query(node*2+1, mid+1, r, d);
    return query(node*2, l, mid, d + seg[node*2+1].sum);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        upd(1, 1, VAL, a[i], 1);
    }
    for(int i=1; i<=m; i++){
        cin >> b[i];
        upd(1, 1, VAL, b[i], -1);
    }
    int qrs;
    cin >> qrs;
    while(qrs--){
        int typ, i, x;
        cin >> typ >> i >> x;
        if(typ == 1){
            upd(1, 1, VAL, a[i], -1);
            a[i] = x;
            upd(1, 1, VAL, a[i], 1);
        }
        else{
            upd(1, 1, VAL, b[i], 1);
            b[i] = x;
            upd(1, 1, VAL, b[i], -1);
        }
        cout << query(1, 1, VAL, 0) << "\n";
    }
    return 0;
}