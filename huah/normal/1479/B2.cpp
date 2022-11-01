#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n,a[N],nex[N],vis[N],f[N];
int main()
{
    memset(f,inf,sizeof(f));
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int m=0;
    a[0]=-1;
    for(int i=1;i<=n;i++)
        if(a[i]!=a[i-1])
        a[++m]=a[i];
    n=m;
    for(int i=n;i>=1;i--)
    {
        nex[i]=vis[a[i]];
        vis[a[i]]=i;
    }
    f[1]=1;
    for(int i=1;i<=n;i++)
    {
        f[i+1]=min(f[i+1],f[i]+1-(a[i+1]==a[i-1]));
        if(nex[i])
            f[nex[i]]=min(f[nex[i]],f[i]+nex[i]-i-1-(a[i+1]==a[i-1]));
        if(nex[i-1])
            f[nex[i-1]]=min(f[nex[i-1]],f[i]+nex[i-1]-i-1);
    }
    printf("%d\n",f[n]);
}
/*
6
3 8 5 3 4 5
*/