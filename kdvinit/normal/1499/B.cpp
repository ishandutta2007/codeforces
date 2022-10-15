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

    int n = s.size();

    int a[n+1];
    for(int i=1;i<=n;i++) a[i]=s[i-1]-'0';

    int cnt[2]={0};
    for(int i=1;i<=n;i++) cnt[a[i]]++;

    if(cnt[0]==0 || cnt[1]==0) { cout<<"YES"<<endl; return; }

    vector<int> tmp;

    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) tmp.push_back(i);
    }

    int pos=1;
    for(int j=1; j<tmp.size(); j++)
    {
        if(tmp[j-1]+1==tmp[j]) pos=0;
    }
    if(pos==1) { cout<<"YES"<<endl; return; }

    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) continue;
        tmp.clear();
        for(int j=1; j<i; j++)
        {
            if(a[j]==1) tmp.push_back(j);
        }
        for(int j=i+1; j<=n; j++)
        {
            if(a[j]==0) tmp.push_back(j);
        }
        pos=1;
        for(int j=1; j<tmp.size(); j++)
        {
            if(tmp[j-1]+1==tmp[j]) pos=0;
        }
        if(pos==1) { cout<<"YES"<<endl; return; }
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