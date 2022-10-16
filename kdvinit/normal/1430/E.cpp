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
    int n;
    cin>>n;

    char x;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]=x-96;
    }

    int freqlr[n+1][27],freqrl[n+1][27];
    for(int j=1;j<=26;j++) freqlr[1][j]=0;

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=26;j++)
        {
            freqlr[i][j]=freqlr[i-1][j];
        }
        freqlr[i][a[i-1]]=freqlr[i-1][a[i-1]]+1;
    }

    for(int j=1;j<=26;j++) freqrl[n][j]=0;

    for(int i=n-1;i>0;i--)
    {
        for(int j=1;j<=26;j++)
        {
            freqrl[i][j]=freqrl[i+1][j];
        }
        freqrl[i][a[i+1]]=freqrl[i+1][a[i+1]]+1;
    }

    vector< vector<int> > pos(27);
    for(int i=1;i<=n;i++)
    {
        pos[a[i]].push_back(i);
    }

    int cnt[27];
    for(int j=1;j<=26;j++)
    {
        cnt[j]=pos[j].size();
        cnt[j]--;
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int temp,tp;
        temp=pos[a[i]][cnt[a[i]]--];
        tp=temp;
        temp=n-temp;
        for(int j=1;j<=26;j++)
        {
            temp-=min(freqlr[i][j],freqrl[tp][j]);
        }
        ans+=temp;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}