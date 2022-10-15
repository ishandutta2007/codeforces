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

    int a[n+1],pos1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) pos1=1;
    }

    int freq[n+1]={0},perm=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>n) { perm=0; continue; }
        if(freq[a[i]]==1) perm=0;
        freq[a[i]]++;
    }

    int ans[n+1]={0};
    if(perm==1) ans[1]=1;
    if(pos1==1) ans[n]=1;

    int strt=1,nd=n,cnt=1;
    while(strt<nd)
    {
        int k=n+1-cnt;
        if(freq[cnt-1]!=0) break;

        if(a[strt]==cnt && a[nd]==cnt) { cnt++; break; }

        if(a[strt]!=cnt && a[nd]!=cnt)
        {
            if(freq[cnt]>0) cnt++;
            break;
        }

        if(a[strt]==cnt)
        {
            freq[cnt]--;
            strt++;
            cnt++;
            continue;
        }
        if(a[nd]==cnt)
        {
            freq[cnt]--;
            nd--;
            cnt++;
            continue;
        }
    }
    cnt--;

    for(int i=n;cnt--;i--) ans[i]=1;
    for(int i=1;i<=n;i++) cout<<ans[i];
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}