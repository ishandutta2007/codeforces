#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

struct Fenwick{
    int n;
    vector<int> tree;
    Fenwick(int N):n(N + 1){
        tree.resize(n);
    }
    void push(int x, int y){
        for(int i = x; i < n; i += (i & -i)) tree[i] += y;
    }
    int get(int x){
        int rv = 0;
        x = min(x, n - 1);
        for(int i = x; i > 0; i -= (i & -i)){
            rv += tree[i];
        }
        return rv;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    const int NS = (int)3e5 + 4;
    Fenwick cnt(NS), sum(NS), lowsum(NS);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int lc = cnt.get(a[i] - 1);
        ans += lc * a[i] - lowsum.get(a[i]);
        ans += (cnt.get(NS) - cnt.get(a[i])) * a[i];
        ans += sum.get(NS);
        for(int j = 1; j * a[i] < NS; ++j){
            ans -= (cnt.get(a[i] * (j + 1) - 1) - cnt.get(a[i] * j - 1)) * a[i] * j;
            lowsum.push(a[i] * j, a[i]);
        }
        cnt.push(a[i], 1);
        sum.push(a[i], a[i]);
        cout << ans << ' ';
    }
    return 0;
}