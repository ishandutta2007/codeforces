#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int br=0;
bool visited[100005];
vector <int> graf[100005];

int dfs(int v){
    visited[v] = 1;
    int zbir = 0;
    for(auto c : graf[v]){
        if(!visited[c]){
            int kao = dfs(c);
            if(kao%2 == 0) br++;
            else zbir += kao;
        }
    }
    zbir++;
    return zbir;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int a, b;
    if(n%2 != 0){cout << "-1"; return 0;}
    for(int i=1; i<n; i++){
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int nesto = dfs(1);
    cout << br;
    return 0;
}