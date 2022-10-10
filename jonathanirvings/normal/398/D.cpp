#include<bits/stdc++.h>
using namespace std;

int n, m, q, k;
bool online[50005];
vector <int> edge[50005];
int teman[50005];
int query;

int main(){
    scanf("%d %d %d", &n, &m, &q);
    scanf("%d", &k);
    int x;
    while (k--){
        scanf("%d", &x);
        online[x] = 1;
    }

    int u, v;
    while (m--){
        scanf("%d %d", &u, &v);
        if (edge[u].size() > edge[v].size()) swap(u, v);
        edge[u].push_back(v);
        teman[v] += online[u];
    }

    while (q--){
        scanf(" %c", &query);
        if (query == 'O'){
            scanf("%d", &u);
            for (int i=0; i<edge[u].size(); i++) teman[edge[u][i]]++;
            online[u] = 1;
        }
        if (query == 'F'){
            scanf("%d", &u);
            for (int i=0; i<edge[u].size(); i++) teman[edge[u][i]]--;
            online[u] = 0;
        }
        if (query == 'A'){
            scanf("%d %d", &u, &v);
            if (edge[u].size() > edge[v].size()) swap(u, v);
            teman[v] += online[u];
            edge[u].push_back(v);
        }
        if (query == 'D'){
            scanf("%d %d", &u, &v);
            bool ketemu = 0;
            for (int i=0; i<edge[u].size(); i++){
                if (edge[u][i] == v){
                    teman[v] -= online[u];
                    edge[u][i] = edge[u].back();
                    edge[u].pop_back();
                    ketemu = 1;
                    break;
                }
            }

            if (!ketemu){
                for (int i=0; i<edge[v].size(); i++){
                    if (edge[v][i] == u){
                        teman[u] -= online[v];
                        edge[v][i] = edge[v].back();
                        edge[v].pop_back();
                        break;
                    }
                }
            }
        }
        if (query == 'C'){
            scanf("%d", &u);
            int ans = teman[u];
            for (int i=0; i<edge[u].size(); i++) ans += online[edge[u][i]];
            printf("%d\n", ans);
        }
    }

    return 0;
}