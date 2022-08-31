#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

int n,p;
int a[50],tot=0;
int id[50];
int lasp[32][32][50000];
inline int len(int x){
    return x<=9?10:100;
}
int ans[50];
int main()
{
    memset(lasp,-1,sizeof(lasp));
    scanf("%d%d",&n,&p);
    for (int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        if(x<=31)a[++tot]=x,id[tot]=i;
    }
    n=tot;
    lasp[0][0][0]=-2;
    for (int i=0;i<n;i++)
        for (int j=0;j<32;j++)
            for (int k=0;k<p;k++)if(~lasp[i][j][k]){
                lasp[i+1][j^a[i+1]][(k*len(a[i+1])+a[i+1])%p]=k;
                if(!~lasp[i+1][j][k])lasp[i+1][j][k]=-2;
            }
    if(~lasp[n][0][0]){
        tot=0;
        for (int i=n,j=0,k=0;i;i--)
            if(lasp[i][j][k]!=-2){
                ans[++tot]=id[i];
                k=lasp[i][j][k];
                j^=a[i];
            }
        if(!tot)printf("No\n");
        else{
            printf("Yes\n");
            printf("%d\n",tot);
            for (int i=tot;i>=1;i--){
                printf("%d",ans[i]);
                if(i==1)printf("\n");
                else printf(" ");
            }
        }
    }else printf("No\n");
    return 0;
}