#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n; n *= 2;

        string s; cin >> s;

        vector<int> stk;

        Dsu gr(n + 4);

        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                stk.push_back(i);
            }
            else{
                gr.unite(stk.back(), i);

                if(i + 1 < n && s[i + 1] == '('){
                    gr.unite(stk.back(), i + 1);
                }

                stk.pop_back();
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans += (gr.get(i) == i);
        }

        cout << ans << '\n';
    }
    
    return 0;
}