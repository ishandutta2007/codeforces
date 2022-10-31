// Hydro submission #62ef1fb574879b352565d756@1659838389941
#include<bits/stdc++.h>
using namespace std;
int a[300001],p[300001],s[5001],t;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,x,i;
    cin>>n;
    for(i=1;i<=n*2;i++)
    {
        cin>>x;
        if(s[x])
        {
            a[++t]=s[x];
            p[t]=i;
            s[x]=0;
        }
        else s[x]=i;
    }
    if(t==n) for(i=1;i<=n;i++)
    printf("%d %d\n",a[i],p[i]);
    else printf("-1\n");
    return 0;
}