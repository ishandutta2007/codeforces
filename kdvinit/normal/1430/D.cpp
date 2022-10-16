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

    int a[n+1],cnt=1,ans=0;
    char x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]=x-48;
    }

    vector<int> freq;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) cnt++;
        else { freq.push_back(cnt); cnt=1; }
    }
    freq.push_back(cnt);

    int m=freq.size(),j=0;
    for(int i=0;i<m;i++)
    {
        j=max(i,j);
        while(freq[j]==1 && j<m) j++;
        if(j==m)
        {
            ans+=(j-i+1)/2;
            break;
        }
        freq[j]--;
        ans++;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}