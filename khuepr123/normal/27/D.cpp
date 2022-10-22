/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int m;
 
ii edge[maxN];
 
vector<int> vc[maxN];
 
void connect(int i, int j){
    vc[i].pb(j);
    vc[j].pb(i);
}
 
vector<int> dumb;
int cnt = 0;
bool used[maxN];
int component[maxN];
 
map<int, int> mp;
 
void dfs(int node){
    used[node] = 1;
    dumb.pb(node);
    for(int child : vc[node]){
        if(!used[child]) dfs(child);
    }
}
 
int choosen[maxN];
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> n; m = n;
    for1(i, 1, m){
        cin >> x >> y;
        edge[i] = {x, y};
    }
    for1(i, 1, m){
        for1(j, i + 1, m){
            vector<ii> dumbb;
            dumbb.pb(ii(edge[i].fi, 1));
            dumbb.pb(ii(edge[i].se, 1));
            dumbb.pb(ii(edge[j].fi, 0));
            dumbb.pb(ii(edge[j].se, 0));
            sort(dumbb.begin(), dumbb.end());
            bool killed = 1;
            for1(i, 0, 2){
                if(dumbb[i].se == dumbb[i + 1].se) killed = 0;
                if(dumbb[i].fi == dumbb[i + 1].fi) killed = 0;
                
            }
            if(killed){
                connect(i * 2 - 1, j * 2);
                connect(j * 2 - 1, i * 2);
            }
        }
    }
    memset(used, 0, sizeof(used));
    for1(i, 1, 2 * n){
        if(!used[i]){
            dumb.clear();
            dfs(i);
            ++cnt;
            for(int child : dumb){
                component[child] = cnt;
            }
        }
    }
    for1(i, 1, n){
        if(component[i * 2 - 1] == component[i * 2]){
            cout << "Impossible\n"; return 0;
        }
    }
    memset(choosen, 0, sizeof(choosen));
    for1(i, 1, n){
        int &c1 = choosen[i * 2 - 1];
        int &c2 = choosen[i * 2];
        if(c1 || c2){
            if(c1) c2 = 3 - c1;
            else c1 = 3 - c2;
        }
        else{
            c1 = 1;
            c2 = 2;
            cnt = component[i * 2];
            for1(j, 1, n * 2) if(component[j] == cnt) choosen[j] = 2;
        }
    }
    for1(i, 1, n){
        if(choosen[i * 2] == 1) cout << "i";
        else cout << "o";
    }
}