#include  <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
int outdegree[N], outdeg[N];
vector<int> revcon[N];
set<int> out[N];
bool done[N];
int label[N];
    int main(){
    cin.tie(0);
    int t, n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        revcon[v].push_back(u);
        outdegree[u]++;
    }
    for(int i = 1; i <= n; i++) out[outdegree[i]].insert(-i);
    for(int i = n; i >= 1; i--){
        int u = -(*out[0].begin());
        label[u] = i;
        out[0].erase(out[0].begin());
        for(int v : revcon[u]){
            if(!done[v]){
                outdegree[v]--;
                out[outdegree[v] + 1].erase(-v);
                out[outdegree[v]].insert(-v);
            }
        }
        done[u] = 1;
    }
    for(int i = 1; i <= n; i++) cout << label[i] << " ";
}