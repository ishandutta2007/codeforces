#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define mo 1000000007
using namespace std;
int n,m,k;
int a[15][15];
int b[15][15];
int ans=0;
int cur[15]={0};
int go[15],back[15];
int fact[15];
int tot=0;
void check(){
    for (int i=1;i<=k;i++)go[i]=back[i]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if(a[i][j]){
                if(go[a[i][j]]){
                    if(go[a[i][j]]!=b[i][j])return;
                }else go[a[i][j]]=b[i][j];
                if(back[b[i][j]]){
                    if(back[b[i][j]]!=a[i][j])return;
                }else back[b[i][j]]=a[i][j];
            }
    int t=1;
    while(t<=k && cur[t])t++; t--;
    ans+=fact[k-tot]/fact[k-t];
    if(ans>=mo)ans-=mo;
}
void dfs(int i,int j){
    if(i==n+1)check();
    else if(j==m+1)dfs(i+1,1);
    else{
        int bo[15]={0};
        for (int ii=1;ii<=i;ii++)
            for (int jj=1;jj<=j;jj++){
                if(ii==i &&jj==j)break;
                bo[b[ii][jj]]=1;
            }
        for(int s=1;s<=k && cur[s-1];s++)
            if(!bo[s]){
                cur[s]++;
                b[i][j]=s;
                dfs(i,j+1);
                cur[s]--;
            }
    }
}
int main()
{
    int ap[15]={0};ap[0]=1;
    fact[0]=1;
    for (int i=1;i<=10;i++)fact[i]=fact[i-1]*i;
    scanf("%d%d%d",&n,&m,&k);
    if(n+m-1>k){
        printf("0\n");
        return 0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(!ap[a[i][j]]){
                tot++;
                ap[a[i][j]]=1;
            }
        }
    cur[0]=1;
    dfs(1,1);
    printf("%d\n",ans);
    return 0;
}