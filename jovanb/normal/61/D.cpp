#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int par[100005];
vector <pair <int, int>> graf[100005];
ll depth[100005];
ll sum;
map <pair <int, int>, int> cost;
bool visited[100005];

void dfs(int v, ll d){
    visited[v] = 1;
    depth[v] = d;
    for(auto pr : graf[v]){
        int c = pr.first;
        int x = pr.second;
        if(!visited[c]){
            par[c] = v;
            sum += 2*x;
            dfs(c, d+x);
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
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
        cost[{a, b}] = c;
        cost[{b, a}] = c;
    }
    dfs(1, 0);
    ll mx=0, res=1;
    for(int i=1; i<=n; i++){
        if(depth[i] > mx){res = i; mx = depth[i];}
    }
    while(1){
        int pr = par[res];
        if(pr == 0) break;
        sum -= cost[{res, pr}];
        res = pr;
    }
    cout << sum;
    return 0;
}