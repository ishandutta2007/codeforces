#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
vector<int> G[maxn + 1];
int a[maxn + 1];
int dis[2][maxn + 1];
pair<int, int> p[maxn + 1];
int suf[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i += 1) cin >> a[i];
    for(int i = 0, u, v; i < m; i += 1){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> q;
    fill(dis[0] + 1, dis[0] + n + 1, maxn);
    dis[0][1] = 0;
    q.push(1);
    while(not q.empty()){
        int u = q.front();
        q.pop();
        for(int v : G[u]) if(dis[0][v] == maxn){
            dis[0][v] = dis[0][u] + 1;
            q.push(v);
        }
    }
    fill(dis[1] + 1, dis[1] + n + 1, maxn);
    dis[1][n] = 0;
    q.push(n);
    while(not q.empty()){
        int u = q.front();
        q.pop();
        for(int v : G[u]) if(dis[1][v] == maxn){
            dis[1][v] = dis[1][u] + 1;
            q.push(v);
        }
    }
    for(int i = 1; i <= k; i += 1) p[i] = {dis[0][a[i]], dis[1][a[i]]};
    sort(p + 1, p + k + 1);
    for(int i = k; i; i -= 1) suf[i] = max(suf[i + 1], p[i].second);
    int L = 1, R = maxn;
    while(L < R){
        int M = (L + R + 1) >> 1;
        int ok = 0;
        for(int i = 1; i <= k and not ok; i += 1){
            int x = lower_bound(p + i + 1, p + k + 1, make_pair(M - p[i].second, 0)) - p;
            if(x == k + 1) continue;
            if(suf[x] + p[i].first >= M) ok = 1;
        }
        if(ok) L = M;
        else R = M - 1;
    }
    cout << min(L + 1, dis[0][n]);
    return 0;
}