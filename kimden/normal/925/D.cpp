#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 100000000;

vector<int> dsu;

int getp(int v){
    if(dsu[v] < 0){
        return v;
    }
    return dsu[v] = getp(dsu[v]);
}

void unite(int u, int v){
    u = getp(u);
    v = getp(v);
    if(u != v){
        if(dsu[u] > dsu[v]){
            swap(u, v);
        }
        dsu[u] += dsu[v];
        dsu[v] = u;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> prv(n, -1);
    vector<vector<int>> g(n);
    vector<int> nei(n, 0);
    vector<int> dist(n, INF);
    vector<pii> e;
    int x, y;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        --x;
        --y;
        e.push_back({x, y});
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int nsz = g[0].size();
    for(auto u: g[0]){
        nei[u] = 1;
    }
    nei[0] = 100500;
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u: g[v]){
            if(dist[u] == INF){
                dist[u] = 1 + dist[v];
                prv[u] = v;
                q.push(u);
            }
        }
    }
    int ans = dist[n - 1];
    vector<int> res;
    if(ans != INF){
        int cur = n - 1;
        while(cur >= 0){
            res.push_back(cur);
            cur = prv[cur];
        }
        reverse(all(res));
    }
    int aa = -1, bb = -1;
    if(ans <= 4){
        cout << ans << endl;
        for(int i = 0; i < res.size(); ++i){
            if(i){
                cout << " ";
            }
            cout << res[i] + 1;
        }
        cout << endl;
        return 0;
    }
    for(auto& p: e){
        if(nei[p.first] + nei[p.second] == 1){
            aa = p.first;
            bb = p.second;
            if(nei[bb] == 1){
                swap(aa, bb);
            }
            break;
        }
    }
    if(!(aa == -1 && bb == -1)){
        ans = 4;
        res = {0, aa, bb, 0, n - 1};
        cout << ans << endl;
        for(int i = 0; i < res.size(); ++i){
            if(i){
                cout << " ";
            }
            cout << res[i] + 1;
        }
        cout << endl;
        return 0;
    }
    if(ans <= 5){
        cout << ans << endl;
        for(int i = 0; i < res.size(); ++i){
            if(i){
                cout << " ";
            }
            cout << res[i] + 1;
        }
        cout << endl;
        return 0;
    }
    vector<vector<int>> gg(n);
    dsu.resize(n, -1);
    for(auto p: e){
        if(nei[p.first] == 1 && nei[p.second] == 1){
            int x = p.first;
            int y = p.second;
            gg[x].push_back(y);
            gg[y].push_back(x);
            unite(x, y);
        }
    }
    int ver = -1;
    for(int i = 0; i < n; ++i){
        if(nei[i] == 1){
            if(gg[i].size() == -dsu[getp(i)] - 1){

            }else{
                ver = i;
                break;
            }
        }
    }
    if(ver == -1){
        cout << -1 << endl;
        return 0;
    }
    vector<int> pp(n, -1);
    vector<int> dd(n, INF);
    dd[ver] = 0;
    queue<int> qq;
    qq.push(ver);
    while(!qq.empty()){
        int v = qq.front();
        qq.pop();
        if(dd[v] == 2){
            int aa = ver;
            int bb = pp[v];
            int cc = v;

            ans = 5;
            res = {0, aa, bb, cc, aa, n - 1};
            cout << ans << endl;
            for(int i = 0; i < res.size(); ++i){
                if(i){
                    cout << " ";
                }
                cout << res[i] + 1;
            }
            cout << endl;
            return 0;
        }
        for(auto u: gg[v]){
            if(dd[u] == INF){
                dd[u] = 1 + dd[v];
                pp[u] = v;
                qq.push(u);
            }
        }
    }
    cout << -1 << endl;

    return 0;
}