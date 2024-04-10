#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e2+7;
int A[2][N],vis[2][N];
int n;
void dfs(int i,int j){
    if (i<0 || i>1 || j<1 || j>n || vis[i][j] || A[i][j])
        return;
    vis[i][j] = 1;
    if (i==1 && j==n)
        return;
    for(int dx = -1;dx<2;++dx)
        for(int dy = -1;dy<2;++dy)
            dfs(i+dx,j+dy);
}
void solve(){

    cin>>n;
    for(int c = 0;c<2;++c)
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[c][i] = ch-'0';
        vis[c][i] = 0;
    }
    dfs(0,1);
    if (vis[1][n])
        cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}