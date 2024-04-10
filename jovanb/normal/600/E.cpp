#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int col[100005];
int mx[100005];
int sz[100005];
int koji[100005];
ll res[100005];
map <int, int> br[100005];
vector <int> graf[100005];

void dfs(int v, int parent){
    sz[v] = 1;
    int tren = 0;
    for(auto c : graf[v]){
        if(c == parent) continue;
        dfs(c, v);
        sz[v] += sz[c];
        if(sz[c] > sz[tren]) tren = c;
    }
    koji[v] = koji[tren];
    mx[v] = mx[tren];
    res[v] = res[tren];
    int h = koji[v];
    for(auto c : graf[v]){
        if(c == parent) continue;
        if(c == tren) continue;
        for(auto pr : br[koji[c]]){
            int a = pr.first;
            int b = pr.second;
            br[h][a] += b;
            int x = br[h][a];
            if(x > mx[v]){
                mx[v] = x;
                res[v] = 0;
            }
            if(x == mx[v]){
                res[v] += a;
            }
        }
    }
    if(!koji[v]) h = koji[v] = v;
    int a = col[v];
    br[h][a]++;
    int x = br[h][a];
    if(x > mx[v]){
        mx[v] = x;
        res[v] = 0;
    }
    if(x == mx[v]){
        res[v] += a;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> col[i];
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1; i<=n; i++){
        cout << res[i] << " ";
    }
    return 0;
}