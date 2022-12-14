#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<set<int>> st(n + 1);
    int ans = 0;
    for(int i = 1; i <= n; ++i) st[i].insert(0);
    ans = n;
    auto add = [&](int x, int y)->void{
        if(*(--st[x].end()) < x && x < y) --ans;
        st[x].insert(y);
    };
    auto era = [&](int x, int y)->void{
        int f = (*(--st[x].end()) < x);
        st[x].erase(y);
        if(*(--st[x].end()) < x && !f) ++ans;
    };
    for(int i = 1; i <= m; ++i){
        int x, y; cin >> x >> y;
        add(x, y), add(y, x);
    }
    int q; cin >> q;
    while(q--){
        int x, y, z; cin >> x;
        if(x == 1){
            cin >> y >> z;
            add(y, z), add(z, y);
        }
        else if(x == 2){
            cin >> y >> z;
            era(y, z), era(z, y);
        }
        else{
            cout << ans << '\n';
        }
    }
    return 0;
}