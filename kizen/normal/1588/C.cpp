#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

struct Seg{
    int n;
    vector<int> tree;
    Seg(int N):n(N){
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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        vector<int> pre(n + 1), lgoc(n + 1);
        Seg ot(n + 4), et(n + 4);
        for(int i = 1; i <= n; ++i){
            pre[i] = a[i] - pre[i - 1];
            if(i % 2) ot.push(1, 1, n, i, i, pre[i]);
            else et.push(1, 1, n, i, i, pre[i]);
        }
        map<int, int> lst[2];
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            int lp = lst[i % 2][pre[i]], lp2 = lst[1 - i % 2][-pre[i]];
            if((lp2 || pre[i] == 0) && lp2 > lp) lp = lp2;
            if((lp || pre[i] == 0)){
                int om = ot.get(1, 1, n, lp + 1, i), em = et.get(1, 1, n, lp + 1, i);
                if(lp % 2){
                    om -= pre[lp], em += pre[lp];
                }
                else{
                    om += pre[lp], em -= pre[lp];
                }
                if(om >= 0 && em >= 0){
                    lgoc[i] = lgoc[lp] + 1;
                    ans += lgoc[i];
                }
            }
            //cout << i << ' ' << lgoc[i] << ' ' << lp << '\n';
            lst[i % 2][pre[i]] = i;
        }
        cout << ans << '\n';
    }
    return 0;
}