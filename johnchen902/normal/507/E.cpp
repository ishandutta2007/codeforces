#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int id;
    int to;
    bool good;
};

vector<Edge> adj[100000];

pair<int, int> dis[100000];
int prevv[100000], preve[100000];

bool good[100000];
bool used[100000];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        x--; y--;
        adj[x].push_back({ i, y, (bool) z });
        adj[y].push_back({ i, x, (bool) z });
        good[i] = z;
    }

    for(int i = 1; i < n; i++)
        dis[i] = {100001, 100001};

    using P = pair<pair<int, int>, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({dis[0], 0});
    while(!pq.empty()) {
        pair<int, int> cost = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if(cost > dis[x])
            continue;
        if(x == n - 1) {
//            printf(">> <<\n");
            break;
        }
        for(const Edge& e : adj[x]) {
            pair<int, int> cost2 = { cost.first + 1, cost.second + (e.good ? -1 : +1) };
//            fprintf(stderr, "cost2 = {%d, %d}\n", cost2.first, cost2.second);
            if(cost2 < dis[e.to]) {
                dis[e.to] = cost2;
                prevv[e.to] = x;
                preve[e.to] = e.id;
//                fprintf(stderr, "preve[%d] = %d\n", e.to, e.good ? e.id : -1);
                pq.push({dis[e.to], e.to});
            }
        }
    }

    int cnt1 = 0;
    for(int x = n - 1; x; x = prevv[x]) {
//        printf(">> %d\n", x + 1);

        used[preve[x]] = true;
        if(!good[preve[x]])
            cnt1++;
    }

    int cnt2 = 0;
    for(int i = 0; i < n; i++)
        for(const Edge& e : adj[i])
            if(!used[e.id] && e.good)
                cnt2++;

    printf("%d\n", cnt1 + cnt2 / 2);


    for(int x = n - 1; x; x = prevv[x])
        if(!good[preve[x]])
            printf("%d %d 1\n", prevv[x] + 1, x + 1);


    for(int i = 0; i < n; i++)
        for(const Edge& e : adj[i])
            if(!used[e.id] && e.good) {
                used[e.id] = true;
                printf("%d %d 0\n", i + 1, e.to + 1);
            }
}