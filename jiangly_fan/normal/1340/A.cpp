#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
int p[maxn + 1], q[maxn + 1];
int r[maxn + 2], sz[maxn + 1];
int getr(int u){
    return r[u] == u ? u : r[u] = getr(r[u]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        r[n + 1] = n + 1;
        set<pair<int, int>, greater<pair<int, int>>> s;
        for(int i = 1; i <= n; i += 1){
            cin >> p[i];
            q[p[i]] = i;
            s.insert({sz[i] = 1, r[i] = i});
        }
        int ok = 1;
        for(int i = 1; i <= n; i += 1){
            if(sz[q[i]] != s.begin()->first){
                ok = 0;
                break;
            }
            s.erase({sz[q[i]], q[i]});
            r[q[i]] = q[i] + 1;
            int p = getr(q[i]);
            if(p > n) continue;
            s.erase({sz[p], p});
            sz[p] += sz[q[i]];
            s.insert({sz[p], p});
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}