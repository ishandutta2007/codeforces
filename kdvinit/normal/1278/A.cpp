/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s,h;
    cin>>s>>h;

    int n=s.size();
    int m=h.size();

    int of[27]={0};
    for(int i=0;i<n;i++)
    {
        of[s[i]-96]++;
    }

    int pos=0;
    for(int i=0;(i+n-1)<m;i++)
    {
        int nf[27]={0};
        for(int j=i;j<i+n;j++)
        {
            nf[h[j]-96]++;
        }

        int flag=1;
        for(int j=1;j<=26;j++)
        {
            if(nf[j]!=of[j]) flag=0;
        }

        if(flag==1) { cout<<"YES"<<endl; return; }
    }

    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}