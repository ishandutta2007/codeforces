#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 2;
constexpr int maxm = 300000 + 2;
constexpr int maxq = 500000 + 2;
int a[maxm], b[maxm], d[maxm];
int type[maxq], id[maxq];
int pi[maxn], p[maxn];

vector<int> add[maxq];
pair<int*, int> cp[maxq][2];
pair<int, int> spp[maxq];

int gp(int u){
    return p[u] < 0 ? u : gp(p[u]);
}
set<pair<int, int>, greater<pair<int, int>>> mer[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i += 1) cin >> pi[i];
    for(int i = 1; i <= m; i += 1){
        cin >> a[i] >> b[i];
        d[i] = q + 1;
    }
    for(int i = 1; i <= q; i += 1){
        cin >> type[i] >> id[i];
        if(type[i] == 2) d[id[i]] = i;
    }
    for(int i = 1; i <= n; i += 1){
        p[i] = -1;
        mer[i].insert({pi[i], i});
    }
    for(int i = 1; i <= m; i += 1) add[d[i]].push_back(i);
    for(int i = q + 1; i >= 1; i -= 1){
        for(int j : add[i]){
            int pa = gp(a[j]), pb = gp(b[j]);
            if(pa == pb){
                type[i] = 0;
                continue;
            }
            if(p[pa] < p[pb]) swap(pa, pb);
            if(i <= q) cp[i][1] = {&p[pb], p[pb]};
            p[pb] += p[pa];
            if(i <= q) cp[i][0] = {&p[pa], p[pa]};
            p[pa] = pb;
            if(i <= q) spp[i] = {pa, pb};
            for(auto p : mer[pa])
                mer[pb].insert(p);
        }
    }
    for(int i = 1; i <= q; i += 1){
        if(type[i] == 1){
            int r = gp(id[i]), x = 0;
            while(not mer[r].empty()){
                auto p = *mer[r].begin();
                mer[r].erase(p);
                if(pi[p.second]){
                    x = p.second;
                    break;
                }
            }
            cout << pi[x] << "\n";
            pi[x] = 0;
        }
        else if(type[i] == 2){
            *cp[i][0].first = cp[i][0].second;
            *cp[i][1].first = cp[i][1].second;
            for(auto x : mer[spp[i].first])
                if(mer[spp[i].second].count(x)) mer[spp[i].second].erase(x);
        }
        continue;
        for(int i = 1; i <= n; i += 1) if(mer[i].size() and p[i] < 0){
            for(auto p : mer[i]) cout << p.second << " "; cout << "; ";
        }
        cout << endl;
    }
    return 0;
}