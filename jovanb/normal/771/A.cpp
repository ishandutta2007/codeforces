#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <int> graf[200005];
bool visited[200005];

ll ukup=0;
ll brn=0;

void dfs(int v){
    if(visited[v]) return;
    visited[v] = 1;
    brn++;
    ukup += graf[v].size();
    for(auto c : graf[v]) dfs(c);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            ukup = 0;
            brn = 0;
            dfs(i);
            if(ukup != (brn)*(brn-1)){cout << "NO"; return 0;}
        }
    }
    cout << "YES";
    return 0;
}