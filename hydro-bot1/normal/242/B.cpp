// Hydro submission #62ef1f8374879b352565d6fe@1659838339823
#include<bits/stdc++.h>
using namespace std;
int l[100001],r[100001],mx;
int main()
{
    int n,mn=1e9,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        mn=min(mn,l[i]);
        mx=max(mx,r[i]);
    }
    for(i=1;i<=n;i++)
    if(l[i]==mn&&r[i]==mx)
    {
        printf("%d\n",i);
        return 0;
    }
    printf("-1\n");
    return 0;
}