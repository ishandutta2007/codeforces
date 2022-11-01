#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef vector<int> Node;
typedef vector<Node> Graph;
Graph G;
Graph R;
Graph UG;
int size;
int pa[100010];
int pb[100010];
int pc[100010];
bool used[100010];
void insert(int a, int b, int c){
    // printf("insert %d %d %d\n", a + 1, b + 1, c + 1);
    pa[size] = a + 1;
    pb[size] = b + 1;
    pc[size] = c + 1;
    size++;
}
pair<int, int> dfs(int u, int p){
    if(used[u]) return make_pair(-1, -1);
    // printf("dfs(%d -> %d)\n", p + 1, u + 1);
    vector<int> cand;
    vector<int> rev;
    used[u] = true;
    for(int i = 0; i < G[u].size(); i++) if(!UG[u][i]) {
        int child = G[u][i];
        int ri = R[u][i];
        if(child != p) {
            pair<int, int> ret = dfs(child, u);
            // printf("%d -> %d : ret %d\n", u + 1, child + 1, ret.first + 1);
            if(ret.first == -1){
                cand.push_back(child);
                rev.push_back(ri);
            }else{
                UG[child][ri] = 1;
                UG[ret.first][ret.second] = 1;
                insert(u, child, ret.first);
            }
        }
    }
    for(int i = 0; i + 1 < cand.size(); i += 2){
        UG[ cand[i] ][ rev[i] ] = 1;
        UG[ cand[i + 1] ][ rev[i + 1] ] = 1;
        insert(cand[i], u, cand[i + 1]);
    }
    if(cand.size() % 2 == 0){
        return make_pair(-1, -1);
    }else{
        return make_pair(cand.back(), rev.back());
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    G.resize(n);
    R.resize(n);
    UG.resize(n);
    REP(i, m){
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        R[a].push_back(G[b].size() - 1);
        R[b].push_back(G[a].size() - 1);
        UG[a].push_back(0);
        UG[b].push_back(0);
    }
    size = 0;
    pair<int, int> ret = dfs(0, -1);
    if(ret.first == -1){
        //assert(size * 2 == m);
        for(int i = 0; i < size; i++){
            printf("%d %d %d\n", pa[i], pb[i], pc[i]);
        }
    }else{
        cout << "No solution" << endl;
    }
    return 0;
}