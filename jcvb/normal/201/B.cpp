#include<cstring>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;typedef long long ll;
int a[1005][1005];
ll sh[1005]={0},sv[1005]={0};
ll anh[1005]={0},anv[1005]={0};
ll ans[1005][1005];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            sh[i]+=a[i][j];
            sv[j]+=a[i][j];         
        }
    for (int i=1;i<=n;i++)
        for (int ii=0;ii<=n;ii++)anh[ii]+=1ll*sh[i]*(ii*4-i*4+2)*(ii*4-i*4+2);
    for (int j=1;j<=m;j++)
        for (int jj=0;jj<=m;jj++)anv[jj]+=1ll*sv[j]*(jj*4-j*4+2)*(jj*4-j*4+2);
    ll aaaa=(1ll<<63)-1;
    int ix,jx;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=m;j++){
            if(anh[i]+anv[j]<aaaa){
                aaaa=anh[i]+anv[j];
                ix=i;
                jx=j;
            }
        }
    printf("%I64d\n%d %d\n",aaaa,ix,jx);
    return 0;
}