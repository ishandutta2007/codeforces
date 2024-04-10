#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,x,a,b,y,ans;
map<int,int> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
    cin>>n;
    ans=-1;
    mp.clear();
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(mp[a]!=0){if(ans==-1)ans=i-mp[a]+1;else ans=min(ans,i-mp[a]+1);}
        mp[a]=i;
    }

    cout<<ans<<endl;
    }
    return 0;
}