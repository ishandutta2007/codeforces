#include <bits/stdc++.h>
using namespace std;

int mat[1005][1005];
bool visited[1005][1005];
int dis[1005][1005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    string str;
    int poci=1, pocj=1;
    int si, sj;
    for(int i=1; i<=n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            dis[i][j+1] = 1000000;
            if(str[j] == 'S') {si=i; sj=j+1; mat[i][j+1] = 0;}
            else if(str[j] == 'T') mat[i][j+1] = -1;
            else if(str[j] == 'E'){poci = i; pocj = j+1;}
            else mat[i][j+1] = str[j]-'0';
        }
    }
    dis[poci][pocj] = 0;
    int sum=0;
    visited[poci][pocj] = 1;
    queue <pair <int, int>> q;
    q.push({poci, pocj});
    while(!q.empty()){
        int i1 = q.front().first;
        int j1 = q.front().second;
        q.pop();
        if(dis[i1][j1] > dis[si][sj]) break;
        sum += mat[i1][j1];
        if(i1 < n && mat[i1+1][j1] != -1 && !visited[i1+1][j1]){q.push({i1+1, j1}); dis[i1+1][j1] = dis[i1][j1]+1; visited[i1+1][j1] = 1;}
        if(j1 < m && mat[i1][j1+1] != -1 && !visited[i1][j1+1]){q.push({i1, j1+1}); dis[i1][j1+1] = dis[i1][j1]+1; visited[i1][j1+1] = 1;}
        if(i1 > 1 && mat[i1-1][j1] != -1 && !visited[i1-1][j1]){q.push({i1-1, j1}); dis[i1-1][j1] = dis[i1][j1]+1; visited[i1-1][j1] = 1;}
        if(j1 > 1 && mat[i1][j1-1] != -1 && !visited[i1][j1-1]){q.push({i1, j1-1}); dis[i1][j1-1] = dis[i1][j1]+1; visited[i1][j1-1] = 1;}
    }
    cout << sum;
    return 0;
}