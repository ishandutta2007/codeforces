#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

map <int, bool> ima1;
map <int, bool> ima2;
vector <int> graf[100005];
bool visited[100005];
int sz[100005];
int niz1[100005];
int niz2[100005];


bool resio=0;

int k1, k2;

/*void dfs1(int v){
    visited[v] = 1;
    if(resio) return;
    for(auto c : graf[v]){
        if(!visited[c]) dfs1(c);
        if(resio) return;
        sz[v] += sz[c];
    }
    if(sz[v] >= k2){
        cout << "A " << v << endl;
        int ans;
        cin >> ans;
        if(ima2[ans]){cout << "C " << v << endl; resio = 1; return;}
        else sz[v] = 0;
    }
}

void resi1(){
    dfs1(1);
    if(resio) return;
    cout << "C -1" << endl;
}*/

void dfs(int v){
    visited[v] = 1;
    if(resio) return;
    if(ima1[v]){
        resio = 1;
        cout << "A " << v << endl;
        int x;
        cin >> x;
        if(ima2[x]) cout << "C " << v << endl;
        else cout << "C -1" << endl;
        return;
    }
    for(auto c : graf[v]){
        if(!visited[c]) dfs(c);
        if(resio) return;
    }
}

void solve(){
    resio=0;
    ima1.clear();
    ima2.clear();
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        graf[i].clear();
        sz[i] = 1;
        visited[i] = 0;
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    cin >> k1;
    for(int i=1; i<=k1; i++){
        cin >> niz1[i];
        ima1[niz1[i]] = 1;
    }
    cin >> k2;
    for(int i=1; i<=k2; i++){
        cin >> niz2[i];
        ima2[niz2[i]] = 1;
    }
    /*if(k2*5 >= n){
        resi1();
        return;
    }*/
    cout << "B " << niz2[1] << endl;
    int p;
    cin >> p;
    dfs(p);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}