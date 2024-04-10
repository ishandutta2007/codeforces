#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000;
int d[maxn + 1];
vector<int> G[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1, u, v; i < n; i += 1){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        d[u] += 1;
        d[v] += 1;
    }
    vector<int> v;
    for(int i = 1; i <= n; i += 1) if(d[i] == 1) v.push_back(i);
    while(true){
        if(v.size() == 1){
            cout << "! " << v[0] << endl;
            return 0;
        }
        int x = v[v.size() - 1], y = v[v.size() - 2], z;
        cout << "? " << x << " " << y << endl;
        cin >> z;
        if(z == x or z == y){
            cout << "! " << z << endl;
            return 0;
        }
        v.pop_back();
        v.pop_back();
        for(int z : G[x]) if(--d[z] == 1) v.push_back(z);
        for(int z : G[y]) if(--d[z] == 1) v.push_back(z);
    }
    return 0;
}