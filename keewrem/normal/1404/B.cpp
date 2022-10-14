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

int T;
ll N;
vi adj[100002];
bool vis[100002]; int dist[100002];
int mx, nd;
void find(int node){
    vis[node] = 1;
    for(int x: adj[node]){

        if(vis[x])continue;
        dist[x] = dist[node]+1;
        find(x);
    }
    if(dist [node] > mx){mx = dist[node]; nd = node;}

}
int a,b,st,ed;
int main(){
    cin >> T;
    while(T--){
        int al,bb;
        cin >> N >> st >> ed >> al >> bb;
        for(int i = 0; i <= N; i++){adj[i].clear(); vis[i]=0; dist[i] = 0;}
        for(int i = 1; i <N; i++){
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        mx = 0; nd = 0;
        find(st);
        ed = dist[ed];
        for(int i = 0; i <= N; i++){vis[i]=0; dist[i] = 0;}
        mx = 0;
        find(nd);
        if(min(bb,mx)>2*al && ed > al)cout << "Bob\n";
        else cout << "Alice\n";
    }
    return 0;
}