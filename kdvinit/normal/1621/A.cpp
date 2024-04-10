/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    int mx = (n+1)/2;

    if(k>mx) { cout<<-1<<endl; return; }

    int cnt=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i!=j) cout<<".";
            else
            {
                if(i%2==1 && cnt<k) { cout<<"R"; cnt++; }
                else cout<<".";
            }
        }
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}