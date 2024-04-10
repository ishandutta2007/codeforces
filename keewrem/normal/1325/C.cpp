#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;

int N,t,a,b;
vector<pair<int,int>> adj[100021];
bool vis[100200];
int label[100021];
int node;

int main(){
    cin >> N;
    for(int i = 0; i < N-1; i++){
        cin >> a >> b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    int q =0;
    for(int i = 0; i < N; i++)label[i]=-1;
    for(int i = 0; i<=N; i++){
        if(adj[i].size()>2){
            label[adj[i][0].se]=0;
            label[adj[i][1].se]=1;
            label[adj[i][2].se]=2;
            q = 3; break;
        }
    }
    for(int i = 0; i < N-1; i++)if(label[i]==-1)label[i]=q++;
    for(int i = 0; i < N-1; i++)cout << label[i]<<"\n";
    return 0;
}