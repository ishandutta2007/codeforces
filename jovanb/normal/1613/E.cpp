#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;

vector <pair <int, int>> graf[N+5];
string mat[N+5];
int deg[N+5];

int n, m;

int hsh(int i, int j){
    return i*m + j;
}

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

bool valid(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> mat[i];
    }
    int pi = 0, pj = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            graf[hsh(i, j)].clear();
            deg[hsh(i, j)] = 0;
            for(int d=0; d<4; d++){
                if(valid(i + di[d], j + dj[d]) && (mat[i + di[d]][j + dj[d]] == '.' || mat[i + di[d]][j + dj[d]] == 'L')){
                    deg[hsh(i, j)]++;
                    graf[hsh(i, j)].push_back({i + di[d], j + dj[d]});
                }
            }
            if(mat[i][j] == 'L') pi = i, pj = j;
        }
    }
    deg[hsh(pi, pj)] = -1;
    queue <pair <int, int>> q;
    q.push({pi, pj});
    while(!q.empty()){
        pair <int, int> pos = q.front();
        int v = hsh(pos.first, pos.second);
        q.pop();
        if(mat[pos.first][pos.second] == '.') mat[pos.first][pos.second] = '+';
        deg[v] = -1;
        for(auto pr : graf[v]){
            int c = hsh(pr.first, pr.second);
            deg[c]--;
            if(deg[c] >= 0 && deg[c] <= 1){
                q.push({pr.first, pr.second});
            }
        }
    }
    for(int i=0; i<n; i++) cout << mat[i] << "\n";
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