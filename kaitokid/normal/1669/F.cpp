#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sum=0;
        map<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            mp[sum]=i;
        }
        int ans=0,ff=0;
        for(int i=n;i>0;i--)
        {
            ff+=a[i];
            if(ff>(sum/2))break;
            int g=mp[ff];
            if(g)ans=max(ans,g+n-i+1);
        }
        cout<<ans<<endl;

    }

    return 0;

}