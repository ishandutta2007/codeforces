#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=1e3+10;
const int MOD=1e9+7;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};


int n,m;
int f[N][N][4][3];
string s[N];
int DP(int x,int y,int dir,int mov){
    if (mov==3) return 0;
    if (x>=n||x<0||y<0||y>=m||s[x][y]=='*') return 0;
    if (s[x][y]=='T') return 1;
    int &ans=f[x][y][dir][mov];
    if (ans!=-1) return ans;
    ans=0;
    for(int i=0;i<4;i++) ans|=DP(x+dx[i],y+dy[i],i,mov+(dir!=i));
//    cout<<x<<" "<<y<<" "<<dir<<" "<<mov<<" "<<ans<<'\n';
    return ans;
}
string solve(){
    memset(f,-1,sizeof(f));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) if (s[i][j]=='S')
            for(int k=0;k<4;k++) {
                if (DP(i,j,k,0)) return "YES";
//                cout<<i<<" "<<j<<" "<<k<<'\n';
            }
//    DP(0,2,3,0);
    return "NO";
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    cout<<solve();
}