#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxm = 10000;
int d[maxm];
int dis[maxm * 1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i += 1) cin >> d[i];
    sort(d, d + m);
    int g, r;
    cin >> g >> r;
    int maxt = m * (g + r);
    fill(dis, dis + m * (g + 1), m);
    deque<int> q;
    q.push_back(0);
    dis[0] = 0;
    int ans = INT_MAX;
    while(not q.empty()){
        int from = q.front();
        q.pop_front();
        int i = from / (g + 1), t = from % (g + 1);
        if(i == m - 1){
            ans = min(ans, (g + r) * dis[from] + t);
            continue;
        }
        if(t == g){
            int to = i * (g + 1);
            if(dis[to] > dis[from] + 1){
                dis[to] = dis[from] + 1;
                q.push_back(to);
            }
            continue;
        }
        if(i > 0){
            int w = d[i] - d[i - 1];
            if(g >= t + w){
                int to = (i - 1) * (g + 1) + t + w;
                if(dis[to] > dis[from]){
                    dis[to] = dis[from];
                    q.push_front(to);
                }
            }
        }
        int w = d[i + 1] - d[i];
        if(g >= t + w){
            int to = (i + 1) * (g + 1) + t + w;
            if(dis[to] > dis[from]){
                dis[to] = dis[from];
                q.push_front(to);
            }
        }
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}