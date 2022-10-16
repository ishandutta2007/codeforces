/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n,k,cnt=0,suml=0,cntw,ans=0,m,first=0;
    cin>>n>>k;

    char s[n+1];
    cin>>s[1];
    if(s[1]=='L') cnt=1;
    else first=1;
    vector<int> cntl;
    for(int i=2;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]=='W')
        {
            if(first==0){ suml+=cnt; cnt=0; first=1; continue; }
            if(cnt!=0) cntl.push_back(cnt);
            cnt=0;
            continue;
        }
        cnt++;
    }
    if(cnt!=0) suml+=cnt;
    sort(cntl.begin(),cntl.end());

    for(int i=0;i<cntl.size();i++) suml+=cntl[i];
    cntw=n-suml+k;
    if(cntw==0) { cout<<0<<endl; return; }
    ans=(2*cntw)-1;

    if(k>=suml) { cout<<(2*n-1)<<endl; return; }
    m=cntl.size();

    for(int i=0;i<cntl.size();i++)
    {
        m--;
        if(cntl[i]>k) { m++; break; }
        if(cntl[i]==k) break;
        k-=cntl[i];
    }

    ans-=m;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}