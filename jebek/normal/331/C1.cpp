#include <iostream>

using namespace std;
int n,d[1000100];
int dp(int p)
{
    if(d[p]!=-1)
        return d[p];
    if(p==0)
        return 0;
    int k=p;
    int ans;
    while(k%10==0)
        k=k/10;
    ans=dp(p-k%10);
    k=k/10;
    while(k>0)
    {
        if(k%10!=0)
            ans=min(ans,dp(p-k%10));
        k=k/10;
    }
    d[p]=ans+1;
    return d[p];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        d[i]=-1;
    cout<<dp(n);
}