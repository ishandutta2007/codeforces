#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool seen[101][101];
int comp[101][101];
vector<int> graph[101][101];
queue<int> vert;
int n,m;

void make_comp(void){
    int c , i , v;
    vector<int>::iterator it;
    int cmp = 0;
    for(c=1;c<=m;c++){
    
        for(i=1;i<=n;i++){
            if (!seen[c][i]){
                
                cmp++;
                vert.push(i);

                while (!vert.empty()){
                    v = vert.front();
                    vert.pop();

                    if (!seen[c][v]){
                        
                        seen[c][v] = 1;
                        comp[c][v] = cmp;

                        it = graph[c][v].begin();
                        while (it != graph[c][v].end()){
                            if (!seen[c][*it]){
                                vert.push(*it);

                            }
                            it++;
                        }
                    }
                }

            }
        }
    }
}

int main(void){
    cin >> n >> m;
    int i;
    int a,b,c;
    for(i=1;i<=m;i++){
        cin >> a >> b >> c;
        graph[c][a].push_back(b);
        graph[c][b].push_back(a);
    }
    make_comp();

    int u,v,sol[1001],q;
    cin >> q;
    for(i=1;i<=q;i++){
        cin >> u >> v;
        sol[i] = 0;
        for(c=1;c<=m;c++){
            if (comp[c][u] == comp[c][v]) sol[i]++;
        }
        
    }
    for(i=1;i<=q;i++) cout << sol[i] << "\n";
}