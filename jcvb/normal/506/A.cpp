#include<cstring>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int f[30005][500];
int a[30005]={0};
int n,d;
int main()
{
    scanf("%d%d",&n,&d);
    for (int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        a[x]++;
    }
    memset(f,-1,sizeof(f));
    f[d][250]=a[d];
    int ans=0;
    for (int i=d;i<30000;i++){
        for (int las=0;las<500;las++)if(~f[i][las]){
            int lasd=d+las-250;
            for (int k=-1;k<=1;k++)if(lasd+k>=1 && i+lasd+k<=30000){
                f[i+lasd+k][las+k]=max(f[i+lasd+k][las+k],f[i][las]+a[i+lasd+k]);
            }
        }
    }
    for (int i=d;i<=30000;i++)
        for (int j=0;j<500;j++)ans=max(ans,f[i][j]);
    printf("%d\n",ans);
    return 0;
}