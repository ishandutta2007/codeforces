/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int ans=n;

    int pos=0;
    int freq0=0,freq1=0;
    while(n--)
    {
        string s;
        cin>>s;
        int m=s.size();
        if(m%2==1) pos=1;
        for(int i=0;i<m;i++)
        {
            if(s[i]=='0') freq0++;
            else freq1++;
        }
    }

    if(pos==0 && freq0%2==1) cout<<ans-1<<endl;
    else cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}