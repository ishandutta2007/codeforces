#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000;
int n, m;
char s[maxn][maxn + 1];
int vis[maxn][maxn];
int cntr[maxn], cntc[maxn];
int dntr[maxn], dntc[maxn];
void DFS(int x, int y){
    if(x < 0 or x >= n or y < 0 or y >= m or s[x][y] == '.' or vis[x][y]) return;
    vis[x][y] = 1;
    DFS(x - 1, y);
    DFS(x + 1, y);
    DFS(x, y - 1);
    DFS(x, y + 1);
}
void no(){
    cout << -1;
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i += 1) cin >> s[i];
    for(int i = 0; i < n; i += 1){
        int L = 0, R = m - 1;
        while(L < m and s[i][L] == '.') L += 1;
        while(R >= 0 and s[i][R] == '.') R -= 1;
        for(int j = L; j <= R; j += 1) if(s[i][j] == '.') no();
        for(int j = 0; j < m; j += 1) cntr[i] += s[i][j] == '#';
    }
    for(int i = 0; i < m; i += 1){
        int L = 0, R = n - 1;
        while(L < n and s[L][i] == '.') L += 1;
        while(R >= 0 and s[R][i] == '.') R -= 1;
        for(int j = L; j <= R; j += 1) if(s[j][i] == '.') no();
        for(int j = 0; j < n; j += 1) cntc[i] += s[j][i] == '#';
    }
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < m; j += 1)
            if(not cntr[i] and not cntc[j]){
                dntr[i] += 1;
                dntc[j] += 1;
            }
    for(int i = 0; i < n; i += 1) if(not (cntr[i] + dntr[i])) no();
    for(int i = 0; i < m; i += 1) if(not (cntc[i] + dntc[i])) no();
    int ans = 0;
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < m; j += 1)
            if(s[i][j] == '#' and not vis[i][j]){
                ans += 1;
                DFS(i, j);
            }
    cout << ans;
    return 0;
}