#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 600000;

vector <pair <int, int>> graf[N+5];
pair <int, int> edge[N+5];
vector <int> vec[N+5];
vector <int> nodes[N+5];

int sol[N+5][2];
char s1[N+5][2];
char s2[N+5][2];

bool added[N+5];
bool visited[N+5];

int m = 0;

void dodaj(int t){
    if(edge[t].first == nodes[m].back()) nodes[m].push_back(edge[t].second);
    else nodes[m].push_back(edge[t].first);
    vec[m].push_back(t);
}

void dfs(int v, int p){
    visited[v] = 1;
    added[p] = 1;
    for(auto pr : graf[v]){
        int c = pr.first, t = pr.second;
        if(added[t]) continue;
        if(visited[c]){
            dodaj(t);
            dodaj(t);
            added[t] = 1;
            continue;
        }
        dodaj(t);
        dfs(c, t);
        dodaj(t);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int u, v;
        cin >> u >> v;
        graf[u].push_back({v, i});
        if(u != v) graf[v].push_back({u, i});
        edge[i] = {u, v};
    }
    int dos = 0;
    for(int i=1; i<=2*n; i++){
        if(visited[i]) continue;
        m++;
        nodes[m].push_back(i);
        dfs(i, 0);
        if(vec[m].size() == 2){
            cout << "-1\n";
            return 0;
        }
        nodes[m].pop_back();
        int sz = vec[m].size();
        if(!sz) continue;
        int j = dos, r = dos + sz/2, th = 0;
        for(int i=0; i<sz; i++){
            if(!th) j++;
            else j--;
            if(j > r){
                th = 1;
                j = r;
            }
            sol[j][th] = nodes[m][i];
        }
        if(sz%4 == 0){
            for(int i=0; i<sz/2; i+=2){
                s1[dos + 1 + i][0] = 'L', s1[dos + 1 + i+1][0] = 'R';
                s1[dos + 1 + i][1] = 'L', s1[dos + 1 + i+1][1] = 'R';
            }
            s2[dos + 1][0] = 'U', s2[dos + 1][1] = 'D';
            for(int i=1; i+1<sz/2; i+=2){
                s2[dos + 1 + i][0] = 'L', s2[dos + 1 + i+1][0] = 'R';
                s2[dos + 1 + i][1] = 'L', s2[dos + 1 + i+1][1] = 'R';
            }
            s2[dos + sz/2][0] = 'U', s2[dos + sz/2][1] = 'D';
        }
        else{
            for(int i=0; i+1<sz/2; i+=2){
                s1[dos + 1 + i][0] = 'L', s1[dos + 1 + i+1][0] = 'R';
                s1[dos + 1 + i][1] = 'L', s1[dos + 1 + i+1][1] = 'R';
            }
            s1[dos + sz/2][0] = 'U', s1[dos + sz/2][1] = 'D';
            s2[dos + 1][0] = 'U', s2[dos + 1][1] = 'D';
            for(int i=1; i+1<sz/2; i+=2){
                s2[dos + 1 + i][0] = 'L', s2[dos + 1 + i+1][0] = 'R';
                s2[dos + 1 + i][1] = 'L', s2[dos + 1 + i+1][1] = 'R';
            }
        }
        dos += vec[m].size()/2;
    }
    cout << "2 " << n << "\n";
    for(int j=0; j<=1; j++){
        for(int i=1; i<=n; i++){
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
    for(int j=0; j<=1; j++){
        for(int i=1; i<=n; i++){
            cout << s1[i][j];
        }
        cout << "\n";
    }
    for(int j=0; j<=1; j++){
        for(int i=1; i<=n; i++){
            cout << s2[i][j];
        }
        cout << "\n";
    }
    return 0;
}