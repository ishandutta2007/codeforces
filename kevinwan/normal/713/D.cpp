#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=998244353;
const int mn=1e3+10;
short sp[mn][mn][10][10];
short a[mn][mn];
short qu(int a,int b,int c,int d){
    if(c<a||d<b)return -1;
    int e=31-__builtin_clz(c-a+1),f=31-__builtin_clz(d-b+1);
    return max(max(sp[a][b][e][f],sp[a][d-(1<<f)+1][e][f]),max(sp[c-(1<<e)+1][b][e][f],sp[c-(1<<e)+1][d-(1<<f)+1][e][f]));
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        int x;
        cin>>x;
        if(x){
            if(!i||!j)a[i][j]=1;
            else a[i][j]=min(min(a[i-1][j-1],a[i-1][j]),a[i][j-1])+1;
        }
        sp[i][j][0][0]=a[i][j];
    }
    for(int i=0;i<n;i++)for(int j=1;j<10;j++)for(int k=0;k+(1<<j)<=m;k++)sp[i][k][0][j]=max(sp[i][k][0][j-1],sp[i][k+(1<<j-1)][0][j-1]);
    for(int i=1;i<10;i++)for(int j=0;j+(1<<i)<=n;j++)for(int k=0;k<10;k++)for(int l=0;l+(1<<k)<=m;l++)sp[j][l][i][k]=max(sp[j][l][i-1][k],sp[j+(1<<i-1)][l][i-1][k]);
    int q;
    cin>>q;
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d,a--,b--,c--,d--;
        int cur=0;
        for(int i=1<<9;i;i>>=1){
            if(qu(a+cur+i-1,b+cur+i-1,c,d)>=cur+i)cur+=i;
        }
        printf("%d\n",cur);
    }
}