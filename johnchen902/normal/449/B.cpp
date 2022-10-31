#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

constexpr int max_n = 100000;
constexpr long long infinity = (max_n - 1) * 1000000000LL + 1;

int n, m, k;
vector<pair<int, int>> adj[max_n]; // {to, cost}

long long dis[max_n];
bool is_rail[max_n];

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);
        u--;
        v--;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }
    fill(dis + 1, dis + n, infinity);
    for(int i = 0; i < k; i++) {
        int s, y;
        scanf("%d %d", &s, &y);
        s--;
        dis[s] = min(dis[s], (long long) y);
        is_rail[s] = true;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < n; i++)
        pq.push({dis[i], i});
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if(dis[p.second] < p.first)
            continue;
        for(const auto& pp : adj[p.second]) {
            if(dis[pp.first] > dis[p.second] + pp.second) {
                dis[pp.first] = dis[p.second] + pp.second;
                pq.push({dis[pp.first], pp.first});
                is_rail[pp.first] = false;
            } else if(dis[pp.first] == dis[p.second] + pp.second) {
                is_rail[pp.first] = false;
            }
        }
    }
    printf("%d\n", k - count(is_rail, is_rail + n, true));
}