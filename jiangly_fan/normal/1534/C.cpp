#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for(cin >> T; T; T -= 1){
        int n;
        cin >> n;
        vector<vector<int>> v(n + 1);
        vector<int> p(n + 1);
        function<int(int)> gp = [&](int u){
            return p[u] ? p[u] = gp(p[u]) : u;
        };
        for(int i = 1, p; i <= n; i += 1){
            cin >> p;
            v[i].push_back(p);
        }
        for(int i = 1, p; i <= n; i += 1){
            cin >> p;
            v[i].push_back(p);
        }
        int c = n;
        for(int i = 1; i <= n; i += 1){
            int x = gp(v[i][0]), y = gp(v[i][1]);
            if(x != y){
                c -= 1;
                p[x] = y;
            }
        }
        int ans = 1;
        for(int i = 0; i < c; i += 1) ans = (ans + ans) % mod;
        cout << ans << "\n";
    }
    return 0;
}