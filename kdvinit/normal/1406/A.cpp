/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int freq[102]={0};
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        freq[x]++;
    }

    int ans=0,cnt=0;
    for(int i=0;i<=101;i++)
    {
        if(freq[i]>=2) continue;
        if(freq[i]==1)
        {
            if(cnt==0) ans+=i;
            cnt=1;
        }
        if(freq[i]==0)
        {
            if(cnt==1) ans+=i;
            else ans+=(2*i);
            break;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}