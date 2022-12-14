#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

struct Seg{
    int n;
    vector<int> tree, lazy;
    Seg(int N):n(N){
        tree.resize(n * 4, 1), lazy.resize(n * 4);
    }
    void add(int x, int l, int r, int val){
        lazy[x] += val;
        tree[x] += val;
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
        tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
    }
    int get(int x, int l, int r, int fl, int fr){
        if(fr < l || fl > r || fl > fr) return -(int)1e9;
        if(l >= fl && r <= fr) return tree[x];
        update(x, l, r);
        int mid = (l + r) >> 1;
        return max(get(x * 2, l, mid, fl, fr), get(x * 2 + 1, mid + 1, r, fl, fr));
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i = 0; i < n; ++i){
        cin >> a[i][1] >> a[i][2] >> a[i][0];
    }
    sort(a.begin(), a.end());
    int ans = (int)1e9;
    Seg tree(m + 4);
    int p = 0;
    for(int i = 0; i < n; ++i){
        tree.push(1, 1, m - 1, a[i][1], a[i][2] - 1, -1);
        while(tree.get(1, 1, m - 1, 1, m - 1) < 1){
            tree.push(1, 1, m - 1, a[p][1], a[p][2] - 1, 1);
            if(tree.get(1, 1, m - 1, 1, m - 1) < 1){
                ++p;
            }
            else{
                tree.push(1, 1, m - 1, a[p][1], a[p][2] - 1, -1);
                break;
            }
        }
        if(tree.get(1, 1, m - 1, 1, m - 1) < 1){
            umi(ans, a[i][0] - a[p][0]);
        }
    }
    cout << ans;
    return 0;
}