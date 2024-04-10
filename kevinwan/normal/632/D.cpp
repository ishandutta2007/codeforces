#include <bits/stdc++.h>
using namespace std;
const int mn=1e6+10;
int a[mn],b[mn],c[mn];
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",a+i);
        if(a[i]<=m)b[a[i]]++;
    }
    for(i=1;i<=m;i++){
        for(j=i;j<=m;j+=i)c[j]+=b[i];
    }
    int l=0x3f3f3f3f,k=-1;
    for(i=1;i<=m;i++){
        if(c[i]>k)k=c[i],l=i;
    }
    printf("%d %d\n",l,k);
    for(i=0;i<n;i++)if(l%a[i]==0)printf("%d ",i+1);
}