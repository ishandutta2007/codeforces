#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=5e5+10;
const ll mod=1e9+7;
bitset<500>go[60][2][500],t[500],r[500];
void mult(bitset<500>c[500],bitset<500>a[500],bitset<500>b[500]){
    memcpy(r,b,sizeof(r));
    for(int i=0;i<500;i++)for(int j=i+1;j<500;j++){
        bool b=r[i][j];
        r[i][j]=r[j][i];
        r[j][i]=b;
    }
    for(int i=0;i<500;i++)for(int j=0;j<500;j++)t[i][j]=((a[i]&r[j]).count()!=0);
    memcpy(c,t,sizeof(t));
}
ll dp[500][60][2];
ll solve(int x,int d,int c){
    if(d<0)return 0;
    if(dp[x][d][c]!=-1)return dp[x][d][c];
    ll ans=0;
    for(int i=0;i<500;i++)if(go[d][c][x][i])ans=max(ans,(1LL<<d)+solve(i,d-1,c^1));
    if(!ans)ans=solve(x,d-1,c);
    return dp[x][d][c]=ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c),a--,b--;
        go[0][c][a][b]=1;
    }
    for(int i=1;i<60;i++){
        mult(go[i][0],go[i-1][0],go[i-1][1]);
        mult(go[i][1],go[i-1][1],go[i-1][0]);
    }
    memset(dp,-1,sizeof(dp));
    ll ans=solve(0,59,0);
    if(ans>1e18)printf("-1");
    else printf("%lld",ans);
}