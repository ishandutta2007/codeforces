/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int req;

int val(int n)
{
    int ans=0,temp=4;
    while((temp-2)<=n)
    {
        temp*=2;
        ans++;
    }
    temp/=2;
    req=temp-2;
    return ans;
}

void solve()
{
    int k;
    cin>>k;

    if(k%2==1) { cout<<-1<<endl; return; }

    vector<int> ans;
    int sum=0;

    while(k>0)
    {
        int x=val(k);
        sum+=x;
        ans.push_back(x);
        k-=req;
    }

    if(sum>2000) { cout<<-1<<endl; return; }

    cout<<sum<<endl;
    for(int i=0;i<ans.size();i++)
    {
        int x=ans[i];
        cout<<1<<" ";
        x--;
        while(x--) cout<<0<<" ";
    }
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}