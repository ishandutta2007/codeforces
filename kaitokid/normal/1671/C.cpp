#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        for(int i=1;i<=n;i++)
            cin>>sum[i];
            //sum[i]+=sum[i-1];
        sort(sum+1,sum+n+1);
        for(int i=1;i<=n;i++)
        sum[i]+=sum[i-1];
        ll ans=0;
        for(int i=n;i>0;i--)
        {
            if(x<sum[i])continue;
            ans+=((x-sum[i])/i)+1;
            
        }
        cout<<ans<<endl;
    }
    return 0;

}