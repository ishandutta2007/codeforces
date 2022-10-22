#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> res;
bool visited[100005];
vector <int> graf[100005];
int d[100005];
int parent[100005];

void dfs(int v){
    if(d[v] != v && d[v] != d[parent[v]]){
        cout << -1;
        exit(0);
    }
    for(auto c : graf[v]){
        dfs(c);
    }
    if(d[v] == v) res.push_back(v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        parent[b] = a;
    }
    for(int i=1; i<=n; i++) cin >> d[i];
    for(int i=1; i<=n; i++){
        if(!parent[i]){
            dfs(i);
        }
    }
    cout << res.size() << "\n";
    for(auto c : res){
        cout << c << "\n";
    }
    return 0;
}