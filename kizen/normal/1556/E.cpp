#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

struct maSeg{
    int n;
    vector<int> tree;
    maSeg(int N):n(N){
        tree.resize(n * 4, -(int)1e18);
    }
    void add(int x, int l, int r, int val){
        tree[x] = val;
    }
    void push(int x, int l, int r, int pl, int pr, int val){
        if(pr < l || pl > r || pl > pr) return;
        if(l >= pl && r <= pr){
            add(x, l, r, val);
            return;
        }
        int mid = (l + r) >> 1;
        push(x * 2, l, mid, pl, pr, val), push(x * 2 + 1, mid + 1, r, pl, pr, val);
        tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
    }
    int get(int x, int l, int r, int fl, int fr){
        if(fr < l || fl > r || fl > fr) return -(int)1e18;
        if(l >= fl && r <= fr) return tree[x];
        int mid = (l + r) >> 1;
        return max(get(x * 2, l, mid, fl, fr), get(x * 2 + 1, mid + 1, r, fl, fr));
    }
};

struct miSeg{
    int n;
    vector<int> tree;
    miSeg(int N):n(N){
        tree.resize(n * 4, (int)1e18);
    }
    void add(int x, int l, int r, int val){
        tree[x] = val;
    }
    void push(int x, int l, int r, int pl, int pr, int val){
        if(pr < l || pl > r || pl > pr) return;
        if(l >= pl && r <= pr){
            add(x, l, r, val);
            return;
        }
        int mid = (l + r) >> 1;
        push(x * 2, l, mid, pl, pr, val), push(x * 2 + 1, mid + 1, r, pl, pr, val);
        tree[x] = min(tree[x * 2], tree[x * 2 + 1]);
    }
    int get(int x, int l, int r, int fl, int fr){
        if(fr < l || fl > r || fl > fr) return (int)1e18;
        if(l >= fl && r <= fr) return tree[x];
        int mid = (l + r) >> 1;
        return min(get(x * 2, l, mid, fl, fr), get(x * 2 + 1, mid + 1, r, fl, fr));
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    maSeg mas(n + 4);
    miSeg mis(n + 4);
    for(int j = 1; j <= n; ++j){
        int x; cin >> x;
        a[j] = x - a[j];
        pre[j] = pre[j - 1] + a[j];
        mas.push(1, 0, n, j, j, pre[j]);
        mis.push(1, 0, n, j, j, pre[j]);
    }
    mas.push(1, 0, n, 0, 0, 0);
    mis.push(1, 0, n, 0, 0, 0);
    for(int i = 1; i <= q; ++i){
        int l, r; cin >> l >> r;
        int ith = mas.get(1, 0, n, l - 1, l - 1);
        int lowh = mis.get(1, 0, n, l, r);
        if(lowh < ith){
            cout << "-1\n";
            continue;
        }
        if(mas.get(1, 0, n, r, r) != ith){
            cout << "-1\n";
            continue;
        }
        int high = mas.get(1, 0, n, l, r);
        cout << high - ith << '\n';
    }
    return 0;
}