#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T = 1;
ll N,M;
bool vis[300011], t[300011];
vi adj[300011];
void dfs(int n){
    vis[n] = 1;
    t[n] = 1;
    for(auto x: adj[n]){
        if(t[x])t[n] = 0;
    }
    for(int x: adj[n]){

        if(vis[x])continue;
        dfs(x);
    }
}


void solve(){
    cin >> N >> M;
    for(int i = 0; i <= N; i++){vis[i] = 0; adj[i].clear(); t[i] = 0;}
    int a,b;
    while(M--){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    vi te;
    for(int i = 1; i <= N; i++) {
        if(t[i])te.pb(i);
        if(vis[i] == 0){
            cout << "NO\n";
            return;
        }
    }
    cout<< "YES\n" << te.size()<<"\n";
    for(auto x: te)cout << x <<" ";
    cout << "\n";
    return;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}