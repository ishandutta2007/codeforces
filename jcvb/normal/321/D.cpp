#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n,x;
int a[40][40];
int main()
{
    scanf("%d",&n);x=n>>1;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)scanf("%d",&a[i][j]);
    int ans=-1000000000;
    for (int B=-1;B<=1;B+=2)
        for (int b=0;b<1<<x;b++){
            int su=B*a[x][x];
            for (int j=0;j<x;j++)su+=((b>>j&1)*2-1)*(a[j][x]+B*a[j+x+1][x]);
            for (int k=0;k<x;k++){
                int ma=-1000000000;
                for (int bk=-1;bk<=1;bk+=2){
                    int suu=bk*(a[x][k]+B*a[x][k+x+1]);
                    for (int j=0;j<x;j++)suu+=abs(a[j][k]+((b>>j&1)*2-1)*a[j][k+x+1]+bk*a[j+x+1][k]+B*((b>>j&1)*2-1)*bk*a[j+x+1][k+x+1]);
                    ma=max(suu,ma);
                }
                su+=ma;
            }
            ans=max(ans,su);
        }
    printf("%d\n",ans);
    return 0;
}