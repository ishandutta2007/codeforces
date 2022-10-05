#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int a[2521],b[2521],c[51],d[51];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++)scanf("%d %d",a+i,b+i);
    for(int i=1;i<=n*n;i++){
        if(c[a[i]]==0 && d[b[i]]==0)c[a[i]]=d[b[i]]=1,printf("%d ",i);
    }
}