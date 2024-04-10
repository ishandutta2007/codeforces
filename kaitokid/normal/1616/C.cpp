#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300],n;
int cal(int x,int y)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i==x||i==y)continue;
        if(((a[y]-a[x])*(i-x))!=((a[i]-a[x])*(y-x)))ans++;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {

    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];

    if(n==1){cout<<0<<endl;continue;}
    int ans=n-1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        ans=min(ans,cal(i,j));
    cout<<ans<<endl;
    }

    return 0;
}