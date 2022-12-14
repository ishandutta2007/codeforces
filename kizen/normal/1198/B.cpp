#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

struct Seg{
    int n;
    vector<int> tree, lazy;
    Seg(int N):n(N){
        tree.resize(n * 4), lazy.resize(n * 4);
    }
    void add(int x, int l, int r, int val){
        ma(lazy[x], val);
        ma(tree[x], val);
    }
    void update(int x, int l, int r){
        if(lazy[x] == 0) return;
        int mid = (l + r) >> 1;
        add(x * 2, l, mid, lazy[x]), add(x * 2 + 1, mid + 1, r, lazy[x]);
        lazy[x] = 0;
    }
    void push(int x, int l, int r, int pl, int pr, int val){
        if(pr < l || pl > r || pl > pr) return;
        if(l >= pl && r <= pr){
            add(x, l, r, val);
            return;
        }
        update(x, l, r);
        int mid = (l + r) >> 1;
        push(x * 2, l, mid, pl, pr, val), push(x * 2 + 1, mid + 1, r, pl, pr, val);
    }
    void push2(int x, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            tree[x] = val;
            return;
        }
        update(x, l, r);
        int m = l + r >> 1;
        push2(x * 2, l, m, pos, val), push2(x * 2 + 1, m + 1, r, pos, val);
    }
    int get(int x, int l, int r, int fl, int fr){
        if(fr < l || fl > r || fl > fr) return 0;
        if(l >= fl && r <= fr) return tree[x];
        update(x, l, r);
        int mid = (l + r) >> 1;
        return get(x * 2, l, mid, fl, fr) + get(x * 2 + 1, mid + 1, r, fl, fr);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    Seg tr(n + 4);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        tr.push2(1, 0, n - 1, i, a[i]);
    }
    int q; cin >> q;
    while(q--){
        int id; cin >> id;
        if(id == 1){
            int x, y; cin >> x >> y; --x;
            tr.push2(1, 0, n - 1, x, y);
        }
        else{
            int x; cin >> x;
            tr.push(1, 0, n - 1, 0, n - 1, x);
        }
    }
    for(int i = 0; i < n; ++i){
        cout << tr.get(1, 0, n - 1, i, i) << ' ';
    }
    return 0;
}