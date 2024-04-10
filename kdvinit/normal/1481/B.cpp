/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define yeh cout<<"YES"<<endl;
#define neh cout<<"NO"<<endl;

void solve()
{
    int n,k;
    cin>>n>>k;

    int h[n+1];
    for(int i=1;i<=n;i++) cin>>h[i];

    int lst=0;
    while(k--)
    {
        int as=1;
        for(int i=2;i<=n;i++)
        {
            if(h[i-1]<h[i]) as=0;
        }

        if(as==1) { lst=-1; break; }

        for(int i=1;i<n;i++)
        {
            if(h[i]<h[i+1]) { lst=i; h[i]++; break;}
        }
    }

    cout<<lst<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}