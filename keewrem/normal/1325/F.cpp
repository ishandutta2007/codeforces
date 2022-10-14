#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
int N,M,sq,a,b;
vector<int> adj[100002],s;
bitset<100002> preso;
int depth[100002];
void dfs(int node){
    s.push_back(node);
    depth[node]=s.size();
    for(auto x: adj[node]){
        if(!depth[x]){
            dfs(x);
        }else if(depth[node]-depth[x]>=sq-1){
            printf("2\n");
            printf("%d\n", depth[node]-depth[x]+1);
            for(int i = depth[node]-1; i > depth[x]-2; i--){
                printf("%d ",s[i]);
            }
            exit(0);
        }
    }
    if(!preso[node])for(auto x: adj[node])preso[x]=1;
    s.pop_back();
}

void sol(int node){

}

int main(){
    cin >> N >> M;
    for(int i = 0; i*i < N; i++)sq=i+1;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout << "1\n";
    for(int i = 1; i <= N; i++){
        if(!preso[i]){
            printf("%d\n", i);
            sq--;
        }
        if(!sq)break;
    }
    return 0;
}