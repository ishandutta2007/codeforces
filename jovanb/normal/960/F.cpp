#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct nod{
    int val;
    int levi;
    int desni;
};

int cnt;
vector <nod> seg;

int query(int node, int l, int r, int tl, int tr){
    if(tl > tr) return 0;
    if(l > tr || r < tl) return 0;
    if(tl <= l && r <= tr) {
        //cout << seg[node].val << " " << l << " " << r << endl;
        return seg[node].val;
    }
    int mx = 0;
    int mid = (l+r)/2;
    if(seg[node].levi > -1) mx = max(mx, query(seg[node].levi, l, mid, tl, tr));
    if(seg[node].desni > -1) mx = max(mx, query(seg[node].desni, mid+1, r, tl, tr));
    //if(tl == 0 && tr == 4) cout << mx << " " << l << " " << r << endl;
    return mx;
}

void upd(int node, int l, int r, int t, int val){
    if(l == r){
        seg[node].val = max(seg[node].val, val);
        return;
    }
    int mid = (l+r)/2;
    if(t <= mid){
        if(seg[node].levi == -1) seg[node].levi = ++cnt;
        seg.push_back({0, -1, -1});
        upd(seg[node].levi, l, mid, t, val);
        int mx = 0;
        if(seg[node].levi > -1) mx = max(mx, seg[seg[node].levi].val);
        if(seg[node].desni > -1) mx = max(mx, seg[seg[node].desni].val);
        seg[node].val = mx;
    }
    else{
        if(seg[node].desni == -1) seg[node].desni = ++cnt;
        seg.push_back({0, -1, -1});
        upd(seg[node].desni, mid+1, r, t, val);
        int mx = 0;
        if(seg[node].levi > -1) mx = max(mx, seg[seg[node].levi].val);
        if(seg[node].desni > -1) mx = max(mx, seg[seg[node].desni].val);
        seg[node].val = mx;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    cnt = n-1;
    for(int i=0; i<n; i++){
        seg.push_back({0, -1, -1});
    }
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        int res = query(a-1, 0, 100000, 0, w-1);
        upd(b-1, 0, 100000, w, res+1);
    }
    int mx = 0;
    for(int i=0; i<n; i++){
        mx = max(mx, query(i, 0, 100000, 0, 100000));
        //cout << query(i, 0, 100000, 0, 100000) << endl;
    }
    cout << mx;
    return 0;
}