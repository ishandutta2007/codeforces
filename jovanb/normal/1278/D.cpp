#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 500000;

bool visited[N+5];
vector <int> graf[N+5];

void dfs(int v){
    visited[v] = 1;
    for(auto c : graf[v]) if(!visited[c]) dfs(c);
}

pair <int, int> a[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+1+n);
    set <pair <int, int>> q;
    int edges = 0;
    for(int i=1; i<=n; i++){
        while(!q.empty() && q.begin()->first < a[i].first) q.erase(q.begin());
        for(auto c : q){
            if(c.first > a[i].second) break;
            graf[i].push_back(c.second);
            graf[c.second].push_back(i);
            edges++;
            if(edges > n - 1){
                cout << "NO\n";
                return 0;
            }
        }
        q.insert({a[i].second, i});
    }
    dfs(1);
    for(int i=1; i<=n; i++) if(!visited[i]){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}