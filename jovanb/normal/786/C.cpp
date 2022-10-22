#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 100000;
const int MAXC = 10000000;

struct Segment{
    int L, R, val;
} seg[MAXC];

int root[MAXN+5];
int idxx;
int posl[MAXN+5];
int a[MAXN+5];

void init(int node, int l, int r){
    if(l == r) return;
    seg[node].L = ++idxx;
    seg[node].R = ++idxx;
    int mid = (l+r)/2;
    init(seg[node].L, l, mid);
    init(seg[node].R, mid+1, r);
}

void upd(int node, int pnode, int l, int r, int x, int val){
    if(l == r){
        seg[node].val = seg[pnode].val + val;
        return;
    }
    int mid = (l+r)/2;
    seg[node].L = seg[pnode].L;
    seg[node].R = seg[pnode].R;
    if(x <= mid){
        seg[node].L = ++idxx;
        upd(seg[node].L, seg[pnode].L, l, mid, x, val);
    }
    else{
        seg[node].R = ++idxx;
        upd(seg[node].R, seg[pnode].R, mid+1, r, x, val);
    }
    seg[node].val = seg[seg[node].L].val + seg[seg[node].R].val;
}

int query(int node, int l, int r, int k){
    if(l == r) return l;
    int mid = (l+r)/2;
    if(seg[seg[node].L].val >= k) return query(seg[node].L, l, mid, k);
    else return query(seg[node].R, mid+1, r, k - seg[seg[node].L].val);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    idxx = 1;
    root[n+1] = 1;
    init(1, 1, n);
    for(int i=n; i>=1; i--){
        root[i] = root[i+1];
        int old = root[i];
        root[i] = ++idxx;
        upd(root[i], old, 1, n, i, 1);
        if(posl[a[i]]){
            old = root[i];
            root[i] = ++idxx;
            upd(root[i], old, 1, n, posl[a[i]], -1);
        }
        posl[a[i]] = i;
    }
    for(int k=1; k<=n; k++){
        int cnt = 0, tr = 1;
        while(tr <= n){
            cnt++;
            if(seg[root[tr]].val <= k) break;
            tr = query(root[tr], 1, n, k+1);
        }
        cout << cnt << " ";
    }
    cout << "\n";
    return 0;
}