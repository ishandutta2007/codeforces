#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=90;
const int MOD=1e9+7;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
const int inf=1e6+10;


int n,k,m,wei[N][N];
int f[N][N][2][N];
void prepare(){
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) wei[i][j]=inf;
    while (m--){
        int x,y,cwei;
        cin>>x>>y>>cwei;
        wei[x][y]=min(wei[x][y],cwei);
    }
}
int DP(int L,int R,int isR,int need){
    if (R-L<need) return inf;
    if (need==0) return 0;
    int &ans=f[L][R][isR][need];
    if (ans!=-1) return ans;
    ans=inf;
    if (isR){
        for(int i=L;i<R;i++){
            ans=min(ans,DP(L,i,1,need-1)+wei[R][i]);
            ans=min(ans,DP(i,R-1,0,need-1)+wei[R][i]);
        }
    }else {
        for(int i=L+1;i<=R;i++){
            ans=min(ans,DP(L+1,i,1,need-1)+wei[L][i]);
            ans=min(ans,DP(i,R,0,need-1)+wei[L][i]);
        }
    }
    return ans;
}
int solve(){
    int ans=inf;
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++) {
        ans=min(ans,DP(i,n,0,k-1));
        ans=min(ans,DP(1,i,1,k-1));
    }
    if (ans==inf) return -1;
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}