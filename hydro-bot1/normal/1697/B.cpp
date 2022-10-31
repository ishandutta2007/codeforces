// Hydro submission #62be5cf612be021904691d58@1656642806392
#include<bits/stdc++.h>
using namespace std;
long long s[200001];
int p[200001];
int main()
{
    int n,q,x,y,i;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    cin>>p[i];
    sort(p+1,p+n+1);
    for(i=1;i<=n;i++)
    s[i]=s[i-1]+p[i];
    for(i=0;i<q;i++)
    {
        cin>>x>>y;
        printf("%lld\n",s[n-x+y]-s[n-x]);
    }
    return 0;
}