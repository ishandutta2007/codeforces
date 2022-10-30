// Hydro submission #625ceab781ef68d42bcba9d4@1650256567855
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,i,s,mx=0;
    cin>>n>>m;s=m;
    for(i=0;i<n;i++)
    {
        cin>>a;s+=a;
        mx=max(mx,a);
    }
    printf("%d %d\n",max(mx,(s+n-1)/n),mx+m);
    return 0;
}