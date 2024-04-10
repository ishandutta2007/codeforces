#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;

vector <int> graf[N+5];

int p[N+5];
bool visited[N+5];

void dfs(int v){
    visited[v] = 1;
    for(auto c : graf[v]) if(!visited[c]) dfs(c);
}

int check(int n, int k){
    for(int i=1; i<=n; i++) graf[i].clear();
    for(int i=1; i<=n; i++) visited[i] = 0;
    for(int i=1; i<=n; i++){
        int g = p[i] - k;
        if(g <= 0) g += n;
        graf[i].push_back(g);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int ima[N+5];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=n; i++){
        ima[i] = 0;
    }
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        p[x] = i;
        int dist = p[x] - x;
        if(dist < 0) dist += n;
        ima[dist]++;
    }
    vector <pair <int, int>> vec;
    for(int i=0; i<n; i++){
        vec.push_back({ima[i], i});
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    vector <int> res;
    for(int j=0; j<min(20, int(vec.size())); j++){
        int c = vec[j].second;
        if(n - check(n, c) <= m) res.push_back(c);
    }
    sort(res.begin(), res.end());
    cout << res.size() << " ";
    for(auto c : res) cout << c << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
3 1
3 2 1
*/