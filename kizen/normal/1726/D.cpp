#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

const int NS = (int)2e5 + 4;

int n;
vector<pair<int, int>> way[NS];
int dep[NS], pval[NS];

struct Dsu{
    int n;
    vector<int> pr, rk;
    Dsu(int N):n(N){
        pr.resize(n), rk.resize(n);
        for(int i = 0; i < n; ++i) pr[i] = i, rk[i] = 1;
    }
    inline int get(int x){
        return x == pr[x] ? x : pr[x] = get(pr[x]);
    }
    inline bool unite(int x, int y){
        x = get(x), y = get(y);
        if(x != y){
            if(rk[x] < rk[y]) swap(x, y);
            pr[y] = x, rk[x] += rk[y];
            return true;
        }
        return false;
    }
};

void dfs(int x, int pr){
    for(auto&nxt:way[x]) if(nxt.first != pr){
        dep[nxt.first] = dep[x] + 1;
        pval[nxt.first] = nxt.second;

        dfs(nxt.first, x);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;

        for(int i = 1; i <= n; ++i){
            way[i].clear();
        }

        Dsu gr(n + 4);

        vector<vector<int>> add;
        vector<int> achk(m);
        vector<int> ans(m);
        vector<int> numchk(n + 4);

        for(int i = 0; i < m; ++i){
            int x, y; cin >> x >> y;

            if(gr.unite(x, y)){
                way[x].push_back({y, i});
                way[y].push_back({x, i});
            }
            else{
                add.push_back({x, y, i});
                achk[i] = 1;
            }
        }

        dfs(1, -1);

        for(int i = 0; i < min(2ll, (int)add.size()); ++i){
            ans[add[i][2]] = 1;

            numchk[add[i][0]] = numchk[add[i][1]] = 1;
        }

        if((int)add.size() == 3){
            if(numchk[add[2][0]] && numchk[add[2][1]]){
                if(dep[add[2][0]] > dep[add[2][1]]) ans[pval[add[2][0]]] = 1;
                else ans[pval[add[2][1]]] = 1;
            }
            else{
                ans[add[2][2]] = 1;
            }
        }

        for(int i = 0; i < m; ++i){
            cout << ans[i];
        }
        cout << '\n';
    }
    
    return 0;
}