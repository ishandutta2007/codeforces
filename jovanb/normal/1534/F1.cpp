#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MAXN = 1000000;
 
string s[MAXN+5];
bool uzet[MAXN+5];
int a[MAXN+5];
int ind[MAXN+5];
vector <int> graf[MAXN+5];
vector <int> ord;
vector <int> rgraf[MAXN+5];
bool visited[MAXN+5];
int comp[MAXN+5];
int ncomp;
 
void dfs(int v){
    visited[v] = 1;
    for(auto c : graf[v]) if(!visited[c]) dfs(c);
    ord.push_back(v);
}
 
void dfs2(int v){
    comp[v] = ncomp;
    for(auto c : rgraf[v]) if(!comp[c]) dfs2(c);
}
 
const int INF = 1000000000;
 
vector <pair <int, int>> intervals[MAXN+5];
vector <int> sta[MAXN+5];
 
void vezi(int x, int y){
    graf[x].push_back(y);
    rgraf[y].push_back(x);
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;
 
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }
    for(int i=1; i<=m; i++) cin >> a[i];
    vector <pair <int, int>> vec;
    int NC = 0;
    for(int j=1; j<=m; j++){
        for(int i=1; i<=n; i++){
            if(s[i][j-1] == '#'){
                if(i == 1 || s[i-1][j-1] == '.') intervals[j].push_back({i, i});
                else intervals[j].back().second = i;
            }
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=0; j<intervals[i].size(); j++){
            sta[i].push_back(++NC);
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=0; j<int(intervals[i].size())-1; j++){
            vezi(sta[i][j], sta[i][j+1]);
        }
    }
    for(int i=1; i<m; i++){
        int k = 0;
        for(int j=0; j<intervals[i].size(); j++){
            while(k < intervals[i+1].size() && intervals[i+1][k].second < intervals[i][j].first) k++;
            if(k < intervals[i+1].size()) vezi(sta[i][j], sta[i+1][k]);
        }
    }
    for(int i=m; i>1; i--){
        int k = 0;
        for(int j=0; j<intervals[i].size(); j++){
            while(k < intervals[i-1].size() && intervals[i-1][k].second < intervals[i][j].first) k++;
            if(k != intervals[i-1].size()) vezi(sta[i][j], sta[i-1][k]);
        }
    }
    n = NC;
    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(i);
    }
    int cnt = 0;
    reverse(ord.begin(), ord.end());
    for(int i=1; i<=n; i++) visited[i] = 0;
    for(auto v : ord){
        if(!comp[v]){
            ncomp++;
            dfs2(v);
        }
    }
    for(int i=1; i<=n; i++){
        for(auto c : graf[i]){
            if(comp[i] != comp[c]){
                ind[comp[c]]++;
            }
        }
    }
    for(int i=1; i<=ncomp; i++){
        if(!ind[i]) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}