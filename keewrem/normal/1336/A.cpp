#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int N,a,b,K;
bool vis[200010];
vi adj[200010];
int dad[200010];
int dep[200010];
int kek[200010];
bool taken[200010];
void dfs(int node){
    vis[node]= 1;
    kek [node] = 1;
    for(auto x: adj[node]){
        if(vis[x])continue;
        dep[x]=dep[node]+1;
        dfs(x);
        kek[node]+=kek[x];
    }
}
int main(){
    cin >> N >> K;
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dep[1]=1;
    dfs(1);
    ll res = 0;
    vi sas;
    for(int i = 1; i <= N; i++){
        sas.push_back(dep[i]-kek[i]);
    }
    sort(sas.begin(),sas.end());
    for(int i =0;i < K ;i++){
        res+=sas[N-1-i];
    }
    cout << res << "\n";
    return 0;
}