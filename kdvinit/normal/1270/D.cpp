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
    int n,k;
    cin>>n>>k;

    int freq[k+2]={0},x,y,a[k+2];
    for(int i=1;i<=k+1;i++)
    {
        cout<<"? ";
        for(int j=1;j<=k+1;j++)
        {
            if(j==i) continue;
            cout<<j<<" ";
        }
        cout<<endl;
        cin>>x>>y;
        freq[x]++;
        a[x]=y;
    }

    int mni=-1,mn,mxi,mx;
    for(int i=1;i<=k+1;i++)
    {
        if(freq[i]==0) continue;
        if(mni==-1)
        {
            mni=a[i];
            mn=freq[i];
        }
        else
        {
            mxi=a[i];
            mx=freq[i];
        }
    }

    if(mx<mx)
    {
        swap(mx,mn);
        swap(mxi,mni);
    }

    if(mxi>mni)
    {
        cout<<"! "<<mx<<endl;
    }
    else
    {
        cout<<"! "<<mn<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}