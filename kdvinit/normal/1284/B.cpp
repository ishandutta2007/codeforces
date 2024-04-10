/*
K.D. Vinit  |,,|
Hello
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int l[n+1],x;
    vector< vector<int> > a(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>l[i];
        for(int j=1;j<=l[i];j++)
        {
            cin>>x;
            a[i].push_back(x);
        }
    }

    int cnt=0;
    vector<int> mx,mn;
    for(int i=1;i<=n;i++)
    {
        int pos=0;
        for(int j=1;j<l[i];j++)
        {
            if(a[i][j-1]<a[i][j]) pos=1;
        }
        if(pos==1) cnt++;
        else
        {
            mx.push_back(a[i][0]);
            mn.push_back(a[i][l[i]-1]);
        }
    }

    sort(mx.begin(),mx.end());
    sort(mn.begin(),mn.end());

    int gt=mn.size();
    int ans = (cnt*n) + (n-cnt)*(cnt);

    int m=mn.size();

    for(int i=0;i<mn.size();i++)
    {
        while(gt>0 && mx[m-gt]<=mn[i]) gt--;
        ans+=gt;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}