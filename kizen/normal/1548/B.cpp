#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

struct Seg{
    int n;
    vector<int> tree, lazy;
    Seg(int N):n(N){
        tree.resize(n * 4), lazy.resize(n * 4);
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
        tree[x] = __gcd(tree[x * 2], tree[x * 2 + 1]);
    }
    int get(int x, int l, int r, int fl, int fr){
        if(fr < l || fl > r || fl > fr) return 0;
        if(l >= fl && r <= fr) return tree[x];
        int mid = (l + r) >> 1;
        return __gcd(get(x * 2, l, mid, fl, fr), get(x * 2 + 1, mid + 1, r, fl, fr));
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        Seg tree(n + 4);
        for(int i = 1; i < n; ++i){
            tree.push(1, 1, n - 1, i, i, abs(a[i] - a[i - 1]));
        }
        int ans = 1;
        int r = 1;
        for(int i = 1; i < n; ++i){
            r = max(r, i);
            while(r + 1 < n && tree.get(1, 1, n - 1, i, r + 1) > 1) ++r;
            if(tree.get(1, 1, n - 1, i, r) > 1) ans = max(ans, r - i + 2);
        }
        cout << ans << '\n';
    }
    return 0;
}