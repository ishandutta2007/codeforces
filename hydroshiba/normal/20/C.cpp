#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 6;
const long long inf = LLONG_MAX / 2;

typedef pair<int, long long> ii;

int n, m;
vector<vector<ii>> graph;
bool pass[maxn];
long long dist[maxn];
int trace[maxn];

void dijkstra(){
    priority_queue<ii> heap;
    for(int i = 1; i <= n; ++i) dist[i] = inf;

    dist[1] = 0;
    heap.push(ii(0, 1));
    
    while(!heap.empty()){
        ii current = heap.top();
        heap.pop();

        int node = current.second;

        if(pass[node] == 1) continue;
        pass[node] = 1;

        for(int i = 0; i < graph[node].size(); ++i){
            int u = graph[node][i].first;
            int d = graph[node][i].second;
            
            if(dist[u] > dist[node] + d){
                dist[u] = dist[node] + d;
                heap.push({-dist[u], u});
                trace[u] = node;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    graph.resize(n + 1);

    while(m > 0){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(ii(v, c));
        graph[v].push_back(ii(u, c));
        m--;
    }

    dijkstra();
    stack<int> s;
    int saven=n;
    while(n != 0){
        s.push(n);
        n = trace[n];
    }
    if (s.top()==saven) cout<<-1;
    else while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
}