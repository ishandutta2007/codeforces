#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'a'+1)
#define div dsfdsf
const int N = 64+7;
const int M = 256+7;
pair<int,int> G[N][N];
int div[3][3];
bool vis[M];
int cl[M];
int n,m;
void substract(vector<vector<int> > &matrix,int r1,int r2,int mult){
    for(int i = 0;i<m;++i){
        matrix[r2][i] = (matrix[r2][i]-mult*matrix[r1][i]%3+3)%3;
    }
}
const int INF = 2; // it doesn't actually have to be infinity or a big number

int gauss (vector < vector<int> > a, vector<int> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (!a[sel][col])
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = div [a[i][col]][a[row][col]];
                for (int j=col; j<=m; ++j) {
                    a[i][j] = (a[i][j] - a[row][j] * c) % 3;
                    if (a[i][j] < 0)
                        a[i][j] += 3;
                }
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = div[a[where[i]][m]][a[where[i]][i]];
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum = (sum+ans[j] * a[i][j])%3;
        if (abs(sum - a[i][m]) > 0)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}
void solve(){

    cin>>n>>m;
    for(int i = 0;i<m;++i){
        vis[i] = 0;
        cl[i] = 0;
    }
    for(int i = 0;i<=n;++i)
        for(int j = 0;j<=n;++j)
            G[i][j] = mp(0,0);
    for(int i = 1;i<=m;++i){
        int a,b,col;
        cin>>a>>b>>col;
        G[a][b] = G[b][a] = mp(col,i);
        if (col!=-1)
            vis[i-1] = 1,cl[i-1] = col%3;
    }
    vector<vector<int> > matrix;

    matrix.push_back(vector<int> (m+1,0));

    for(int i = 1;i<=n;++i){
        for(int j = i+1;j<=n;++j){
            for(int k = j+1;k<=n;++k){
                if (!G[i][j].first || !G[i][k].first || !G[j][k].first)
                    continue;
                vector<int> V(m+1,0);
                if (G[i][j].first!=-1)
                    V[m]-=G[i][j].first;
                else
                    V[G[i][j].second-1] = 1;
                if (G[i][k].first!=-1)
                    V[m]-=G[i][k].first;
                else
                    V[G[i][k].second-1] = 1;
                if (G[j][k].first!=-1)
                    V[m]-=G[j][k].first;
                else
                    V[G[j][k].second-1] = 1;
                V[m] = (3+V[m]%3)%3;
                matrix.push_back(V);
            }
        }
    }
    vector<int> ans(m,0);
    bool can = gauss(matrix,ans);
    if (!can){
        cout<<"-1\n";
    }
    else
        for(int i = 0;i<m;++i) {
            int to;
            if (vis[i]) {
                to = cl[i];
            }
            else to = ans[i];
            cout << (to > 0 ? to : to + 3) << ' ';
        }
    cout<<endl;
}
int main(){
    for(int a = 0;a<3;++a){
        for(int b = 0;b<3;++b){
            for(int k = 0;k<3;++k)
                if (b*k%3==a)
                    div[a][b] = k;
        }
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
     cin>>t;

    while(t--)
        solve();
}