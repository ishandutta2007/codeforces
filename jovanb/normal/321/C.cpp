#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool visited[100005];
vector <int> graf[100005];
int sz[100005];
bool bio[100005];
int res[100005];

void dfs(int v){
    sz[v] = 1;
    visited[v] = 1;
    for(auto c : graf[v]){
        if(!bio[c] && !visited[c]){
            dfs(c);
            sz[v] += sz[c];
        }
    }
    visited[v] = 0;
}

int nadji(int v, int n, int par){
    for(auto c : graf[v]){
        if(bio[c]) continue;
        if(c == par) continue;
        if(sz[c] > n/2) return nadji(c, n, v);
    }
    return v;
}

void decompose(){
    queue <pair <int, int>> q;
    q.push({1, 0});
    while(!q.empty()){
        int v = q.front().first;
        int x = q.front().second;
        q.pop();
        dfs(v);
        //cout << "alo " << v << endl;
        v = nadji(v, sz[v], 0);
        res[v] = x;
        bio[v] = 1;
        for(auto c : graf[v]){
            if(!bio[c]){
                q.push({c, x+1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    decompose();
    for(int i=1; i<=n; i++){
        char c = 'A'+res[i];
        cout << c << " ";
    }
    return 0;
}