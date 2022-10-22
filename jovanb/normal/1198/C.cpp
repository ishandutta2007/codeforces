#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;

bool moze[3000005];
pair <int, int> deg[3000005];
vector <pair <int, int>> graf[3000005];
pair <int, int> edges[3000005];
queue <int> q;

void indset(){
    int sz = 0;
    for(int i=1; i<=3*n; i++){
        moze[i] = 1;
    }
    for(int i=1; i<=3*n; i++){
        if(moze[deg[i].second]){
            sz++;
            q.push(deg[i].second);
            if(sz == n) return;
            moze[deg[i].second] = 0;
            for(auto c : graf[deg[i].second]) moze[c.first] = 0;
        }
    }
}

void matching(){
    int sz = 0;
    for(int i=1; i<=3*n; i++){
        moze[i] = 1;
    }
    for(int i=3*n; i>=1; i--){
        if(moze[deg[i].second]){
            for(auto c : graf[deg[i].second]){
                if(moze[c.first]){
                    sz++;
                    q.push(c.second);
                    if(sz == n) return;
                    moze[deg[i].second] = 0;
                    moze[c.first] = 0;
                    break;
                }
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i=1; i<=3*n; i++){
        graf[i].clear();
        deg[i].first = 0;
        deg[i].second = i;
    }
    for(int i=1; i<=m; i++){
        cin >> edges[i].first >> edges[i].second;
        graf[edges[i].first].push_back({edges[i].second, i});
        graf[edges[i].second].push_back({edges[i].first, i});
        deg[edges[i].first].first++;
        deg[edges[i].second].first++;
    }
    sort(deg+1, deg+1+3*n);
    indset();
    if(q.size() == n){
        cout << "IndSet\n";
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
        return;
    }
    while(!q.empty()) q.pop();
    matching();
    if(q.size() == n){
        cout << "Matching\n";
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
        return;
    }
    while(!q.empty()) q.pop();
    cout << "Impossible\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}