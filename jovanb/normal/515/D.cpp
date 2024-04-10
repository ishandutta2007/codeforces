#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

char mat[2005][2005];
char res[2005][2005];

int n, m;

int hes(int i, int j){
    return m*(i-1) + j;
}

pair <int, int> rhes(int x){
    return {1 + (x-1)/m, (x-1)%m+1};
}

vector <int> graf[4000005];
int deg[4000005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=m; j++) mat[i][j] = s[j-1];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            res[i][j] = '*';
            if(mat[i][j] == '.'){
                if(mat[i-1][j] == '.') graf[hes(i, j)].push_back(hes(i-1, j));
                if(mat[i][j-1] == '.') graf[hes(i, j)].push_back(hes(i, j-1));
                if(mat[i+1][j] == '.') graf[hes(i, j)].push_back(hes(i+1, j));
                if(mat[i][j+1] == '.') graf[hes(i, j)].push_back(hes(i, j+1));
            }
        }
    }
    queue <int> q;
    for(int i=1; i<=n*m; i++){
        deg[i] = graf[i].size();
        if(deg[i] == 1) q.push(i);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        pair <int, int> g = rhes(v);
        if(res[g.first][g.second] != '*') continue;
        int koji = -1;
        for(auto c : graf[v]){
            if(deg[c] > 0) koji = c;
        }
        if(koji == -1){
            cout << "Not unique\n";
            return 0;
        }
        deg[koji] = 0;
        for(auto c : graf[koji]){
            deg[c]--;
            if(deg[c] == 1) q.push(c);
        }
        pair <int, int> d = rhes(koji);
        if(d.first == g.first-1){
            res[g.first][g.second] = 'v';
            res[d.first][d.second] = '^';
        }
        else if(d.first == g.first+1){
            res[g.first][g.second] = '^';
            res[d.first][d.second] = 'v';
        }
        else if(d.second == g.second-1){
            res[g.first][g.second] = '>';
            res[d.first][d.second] = '<';
        }
        else{
            res[g.first][g.second] = '<';
            res[d.first][d.second] = '>';
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(res[i][j] == '*' && mat[i][j] != '*'){
                cout << "Not unique\n";
                return 0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << res[i][j];
        }
        cout << "\n";
    }
    return 0;
}