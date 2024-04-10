#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll in[100005];
ll de[100005];
ll val[100005];
bool visited[100005];
vector <int> graf[100005];

void dfs(int v){
    visited[v] = 1;
    for(auto c : graf[v]){
        if(!visited[c]){
            dfs(c);
            in[v] = max(in[v], in[c]);
            de[v] = max(de[v], de[c]);
        }
    }
    val[v] += in[v]-de[v];
    if(val[v] > 0) de[v] += val[v];
    else in[v] -= val[v];
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
    for(int i=1; i<=n; i++) cin >> val[i];
    dfs(1);
    cout << in[1]+de[1];
    return 0;
}