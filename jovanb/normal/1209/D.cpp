#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int sz;

bool visited[100005];
vector <int> graf[100005];

void dfs(int v){
    sz++;
    visited[v] = 1;
    for(auto c : graf[v]){
        if(!visited[c]) dfs(c);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=k; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int res = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            sz = 0;
            dfs(i);
            res += sz-1;
        }
    }
    cout << k-res;
    return 0;
}