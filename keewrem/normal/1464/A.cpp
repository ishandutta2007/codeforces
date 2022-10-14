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
int x[100010], y[100010];
int adj[100002];
bool vis[100002];
int dfs(int n){
    vis[n] = 1;
    if(adj[n] == 0)return 0;
    if(vis[adj[n]])return n;
    return dfs(adj[n]);
}
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        int a,b;
        for(int i = 0; i <= N; i++){
            x[i] = 0; y[i] =0; vis[i] = 0;
            adj[i] = 0;
        }
        for(int i = 1; i <= M; i++){
            cin >> a >> b;
            x[a] = i;
            y[b] = i;
        }
        int ans = M;
        for(int i = 1; i <= N; i++){
            if(x[i] == 0 && y[i] == 0)continue;
            if(x[i] == y[i]){ans--;continue;}
            if(x[i] && y[i]){
                adj[x[i]]=y[i];
            }
        }
        for(int i = 1; i <= M; i++){
            if(!vis[i]){
                if(adj[dfs(i)] == i)ans++;
            }
        }
        cout << ans << "\n";

    }
    return 0;
}