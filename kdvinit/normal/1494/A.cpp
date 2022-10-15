/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin>>s;

    int n=s.size();

    if(s[0]==s[n-1]) { cout<<"NO"<<endl; return; }

    int sum0=0, sum1=0;
    int pos0=1, pos1=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[0]) { sum0++; sum1++; }
        else if(s[i]==s[n-1]) { sum0--; sum1--; }
        else { sum0++; sum1--; }

        if(sum0<0) pos0=0;
        if(sum1<0) pos1=0;
    }

    if(sum0!=0) pos0=0;
    if(sum1!=0) pos1=0;

    if(pos0 || pos1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}