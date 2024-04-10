#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int lst[100005];
int prv[100005];

bool moze[100005];
int seg[400005];

void upd(int node, int l, int r, int x, int val){
    if(l == r){
        seg[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid) upd(node*2, l, mid, x, val);
    else upd(node*2+1, mid+1, r, x, val);
    seg[node] = min(seg[node*2], seg[node*2+1]);
}

int query(int node, int l, int r, int tl, int tr){
    if(l > tr || tl > r) return 1000000000;
    if(tl <= l && r <= tr) return seg[node];
    int mid = (l+r)/2;
    return min(query(node*2, l, mid, tl, tr), query(node*2+1, mid+1, r, tl, tr));
}

int a[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        prv[i] = lst[a[i]];
        lst[a[i]] = i;
        upd(1, 1, n, a[i], i);
    }
    for(int i=1; i<=n; i++){
        if(a[i] != 1) moze[1] = 1;
    }
    for(int i=2; i<=n+1; i++){
        int l = query(1, 1, n, 1, i-1);
        if(l > lst[i]) moze[i] = 1;
    }
    for(int i=n; i>=1; i--){
        if(a[i] != 1){
            int l = query(1, 1, n, 1, a[i]-1);
            if(l > prv[i]) moze[a[i]] = 1;
        }
        upd(1, 1, n, a[i], prv[i]);
    }
    for(int i=1; i<=n+2; i++){
        if(!moze[i]){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}