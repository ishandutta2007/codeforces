/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    string s;
    cin>>s;

    int n = s.size();

    int cnt[2]={0};
    for(int i=0; i<n; i++)
    {
        int x = s[i]-'0';
        cnt[x]++;
    }

    if(cnt[0]==0) { cout<<0<<endl; return; }
    if(cnt[1]==0) { cout<<1<<endl; return; }

    int dif=0;
    for(int i=1; i<n; i++)
    {
        if(s[i]!=s[i-1]) dif++;
    }

    if(dif==1) { cout<<1<<endl; return; }
    if(dif==2 && s[0]=='1') { cout<<1<<endl; return; }

    cout<<2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}