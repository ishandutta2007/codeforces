/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int q;
    cin>>q;

    int fs[26]={0};
    int ft[26]={0};

    fs[0]=1;
    ft[0]=1;

    while(q--)
    {
        int typ, k;
        cin>>typ>>k;

        string s;
        cin>>s;

        if(typ==1) for(char x: s) fs[x-'a']+=k;
        else for(char x: s) ft[x-'a']+=k;

        int cnt=0;
        for(int i=1; i<26; i++) cnt+=ft[i];

        if(cnt!=0) { cout<<"YES"<<endl; continue; }

        cnt=0;
        for(int i=1; i<26; i++) cnt+=fs[i];

        if(cnt==0 && fs[0]<ft[0]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}