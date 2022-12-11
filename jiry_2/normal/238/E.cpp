#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int d[200][200],b[200][200],n,m,inf=1e9,k,U[200],V[200],child[200][200],dp[200][200],S,T,pd[200][200],A[50000],B[50000],way[200][200];
int onpath(int k1,int k2,int k3){
    if (d[k1][k2]+d[k2][k3]!=d[k1][k3]) return 0;
    if (way[k1][k2]*way[k2][k3]==way[k1][k3]) return 2; return 1;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&S,&T);
    memset(d,0x3f,sizeof d);
    for (;m;m--){
        int k1,k2; scanf("%d%d",&k1,&k2); b[k1][k2]=1; d[k1][k2]=1; way[k1][k2]=1;
    }
    for (int k1=1;k1<=n;k1++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (d[i][k1]+d[k1][j]<d[i][j]){
                    d[i][j]=min(d[i][j],d[i][k1]+d[k1][j]); way[i][j]=way[i][k1]*way[k1][j];
                } else if (d[i][k1]+d[k1][j]==d[i][j])way[i][j]+=way[i][k1]*way[k1][j];
    for (int i=1;i<=n;i++) {way[i][i]=1; d[i][i]=0;}
    scanf("%d",&k);
    for (int i=1;i<=k;i++) scanf("%d%d",&U[i],&V[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) if (b[i][j])
            for (int k1=1;k1<=k;k1++) if (onpath(U[k1],i,V[k1])&&onpath(i,j,V[k1])) child[i][k1]++;
    memset(dp,0x3f,sizeof dp);
    dp[T][0]=0;
/*  for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) cout<<d[i][j]<<" "; cout<<endl;
    }
    cout<<endl;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) cout<<way[i][j]<<" "; cout<<endl;
    }
    cout<<endl;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=k;j++) cout<<child[i][j]<<" "; cout<<endl;
    }*/
    memset(pd,0x00,sizeof pd);
    for (int dis=0;dis<=k;dis++){
        int head=0,now=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=k;j++) if (dp[i][j]==dis){head++; A[head]=i; B[head]=j;}
        while (head>now){
            now++; //cout<<"new "<<A[now]<<" "<<B[now]<<" ";
            int k1=A[now],k2=B[now]; pd[k1][k2]=1; //cout<<onpath(U[k2],k1,V[k2])<<" "<<U[k2]<<" "<<V[k2]<<endl;
            if (onpath(U[k2],k1,V[k2])==2) dp[k1][0]=min(dp[k1][0],dp[k1][k2]+1);
            if (k2!=0&&pd[k1][0]==0){
                for (int i=1;i<=n;i++) if (b[i][k1]&&onpath(U[k2],i,V[k2])&&onpath(i,k1,V[k2])){
                    child[i][k2]--; if (child[i][k2]==0){dp[i][k2]=dis; head++; A[head]=i; B[head]=k2;}
                }
            } else if (k2==0){
                for (int i=1;i<=k;i++)
                    for (int j=1;j<=n;j++)
                        if (b[j][k1]&&onpath(U[i],j,V[i])&&onpath(j,k1,V[i])&&pd[k1][i]==0){
                            child[j][i]--; if (child[j][i]==0){dp[j][i]=dis; head++; A[head]=j; B[head]=i;}
                        }
            }
        }
    }
/*  cout<<endl;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=k;j++) cout<<dp[i][j]<<" "; cout<<endl;
    }*/
    if (dp[S][0]>=inf){cout<<-1<<endl; return 0;}
    cout<<dp[S][0]<<endl; return 0;
}