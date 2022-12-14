#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;
 
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
 
const int NS = (int)1e6 + 4;
vector<int> Div[NS];
int era[NS], wh[NS];
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    era[1] = 1;
    for(int i = 2; i < NS; ++i){
        if(era[i]) continue;
        for(int j = i; j < NS; j += i){
            era[j] = i;
        }
    }
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<vector<int>> pp(n);
    for(int i = 0; i < n; ++i){
        int now = a[i];
        while(now > 1){
            if(!(int)pp[i].size() || pp[i].back() != era[now]){
                pp[i].push_back(era[now]);
            }
            now /= era[now];
        }
        for(auto&j:pp[i]){
            Div[j].push_back(i);
        }
    }
    Dsu no(n);
    for(int i = 2; i < NS; ++i){
        for(int j = 1; j < (int)Div[i].size(); ++j){
            no.unite(Div[i][0], Div[i][j]);
        }
    }
    vector<int> even(n);
    for(int i = 0; i < n; ++i){
        if(a[i] % 2 == 0){
            even[no.get(i)] = 1;
        }
    }
    memset(wh, -1, sizeof(wh));
    for(int i = 0; i < n; ++i){
        int up = no.get(i);
        if(even[up]) continue;
        for(auto&j:pp[i]){
            wh[j] = up;
        }
    }
    vector<vector<int>> can(n);
    for(int i = 0; i < n; ++i){
        int val = a[i] + 1;
        vector<int> np;
        while(val > 1){
            if(!(int)np.size() || np.back() != era[val]){
                np.push_back(era[val]);
            }
            val /= era[val];
        }
        if(!even[no.get(i)]){
            for(int j = 0; j < (int)np.size(); ++j){
                if(wh[np[j]] != -1 && wh[np[j]] != no.get(i)){
                    can[no.get(i)].push_back(wh[np[j]]);
                }
            }
        }
        for(int j = 0; j < (int)np.size(); ++j){
            for(int k = j + 1; k < (int)np.size(); ++k){
                if(wh[np[j]] != -1 && wh[np[k]] != -1 && wh[np[j]] != wh[np[k]]){
                    can[wh[np[j]]].push_back(wh[np[k]]);
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        sort(can[i].begin(), can[i].end());
    }
    while(q--){
        int x, y; cin >> x >> y; --x, --y;
        x = no.get(x), y = no.get(y);
        if(x == y || (even[x] && even[y])) cout << "0\n";
        else if(even[x] || even[y]) cout << "1\n";
        else{
            int pos = lower_bound(can[x].begin(), can[x].end(), y) - can[x].begin();
            if(pos < (int)can[x].size() && can[x][pos] == y){
                cout << "1\n";
            }
            else{
                swap(x, y);
                pos = lower_bound(can[x].begin(), can[x].end(), y) - can[x].begin();
                if(pos < (int)can[x].size() && can[x][pos] == y){
                    cout << "1\n";
                }
                else{
                    cout << "2\n";
                }
            }
        }
    }
    return 0;
}