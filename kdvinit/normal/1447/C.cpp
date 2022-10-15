/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n,W,x;
    cin>>n>>W;

    vector< pair<int,int> > w;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        w.push_back( make_pair(x,i) );
    }
    sort(w.begin(),w.end());

    int sum=0;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        int x,y;
        x=w[i].first;
        y=w[i].second;
        if(2*x<W)
        {
            sum+=x;
            ans.push_back(y);
            if(2*sum>=W) break;
        }
        else
        {
            if(x<=W) { cout<<1<<endl; cout<<y<<endl; }
            else cout<<-1<<endl;

            return;
        }
    }
    if(2*sum<W) { cout<<-1<<endl; return; }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}