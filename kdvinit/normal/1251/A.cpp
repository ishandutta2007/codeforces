/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define ya cout<<"YES"<<endl
#define nah cout<<"NO"<<endl

void solve()
{
    string s;
    cin>>s;

    int n = s.size();

    int pos[27]={0},pres[27]={0};
    for(int i=0;i<n;i++) pres[s[i]-96]=1;

    for(int i=0;i<n;i++)
    {
        int cnt=0;
        char x=s[i];
        while(s[i]==x) { i++; cnt++; }
        i--;
        if(cnt%2==1) pos[x-96]=1;
    }

    for(int i=1;i<=26;i++)
    {
        if(pos[i]==1 && pres[i]==1)
        {
            char x=i+96;
            cout<<x;
        }
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}