#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 5000000 + 1;
pair<int, int> p[maxn];
int c[maxn], u[maxn], v[maxn], fk[maxn];
pair<int, int> gp(int u){
    if(p[u].first < 0) return {u, 0};
    auto r = gp(p[u].first);
    return {r.first, r.second ^ p[u].second};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i += 1){
        cin >> c[i];
        p[i] = {-1, 0};
    }
    map<pair<int, int>, vector<int>> mp;
    for(int i = 1; i <= m; i += 1){
        cin >> u[i] >> v[i];
        if(c[u[i]] == c[v[i]]){
            auto pu = gp(u[i]);
            auto pv = gp(v[i]);
            if(pu.first == pv.first){
                if(pu.second == pv.second) fk[c[u[i]]] = 1;
            }
            else{
                if(p[pu.first].first < p[pv.first].first) swap(pu, pv);
                p[pv.first].first += p[pu.first].first;
                p[pu.first].first = pv.first;
                p[pu.first].second = pu.second ^ pv.second ^ 1;
            }
        }
        else{
            int cu = c[u[i]], cv = c[v[i]];
            if(cu > cv) swap(cu, cv);
            mp[{cu, cv}].push_back(i);
        }
    }
    LL ans = 0;
    for(int i = 1; i <= k; i += 1) if(not fk[i]) ans += 1;
    ans = ans * (ans - 1) / 2;
    for(auto& pv : mp){
        auto& ck = pv.first;
        if(fk[ck.first] or fk[ck.second]) continue;
        auto& e = pv.second;
        vector<pair<pair<int, int>*, pair<int, int>>> vpp;
        int ok = 1;
        for(int i : e) if(ok) {
            auto pu = gp(u[i]);
            auto pv = gp(v[i]);
            if(pu.first == pv.first){
                if(pu.second == pv.second) ok = 0;
            }
            else{
                if(p[pu.first].first < p[pv.first].first) swap(pu, pv);
                vpp.push_back({&p[pu.first], p[pu.first]});
                vpp.push_back({&p[pv.first], p[pv.first]});
                p[pv.first].first += p[pu.first].first;
                p[pu.first].first = pv.first;
                p[pu.first].second = pu.second ^ pv.second ^ 1;
            }
        } 
        if(not ok) ans -= 1;
        reverse(vpp.begin(), vpp.end());
        for(auto& p : vpp) *p.first = p.second;
    }
    cout << ans;
    return 0;
}