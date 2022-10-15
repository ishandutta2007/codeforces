/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    string a, b;
    cin>>a>>b;

    int ans=0, cur=-1;
    for(int i=0; i<n; i++)
    {
        if(a[i]!=b[i])
        {
            ans+=2;
            if(cur==0) ans++;
            cur=-1;
            continue;
        }

        if(a[i]=='0')
        {
            if(cur==-1) { cur=0; continue; }

            if(cur==0) { ans++; cur=0; }
            else { ans+=2; cur=-1; }

        }
        else
        {
            if(cur==-1) { cur=1; continue; }
            if(cur==0) { ans+=2; cur=-1; }
            else { ans+=0; cur=1; }
        }
    }

    if(cur==0) ans++;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}