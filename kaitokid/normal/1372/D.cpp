#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009],pr[200009],suf[200009];
int main()
{
    ios::sync_with_stdio(0);
    int t,n;

        cin>>n;
        ll sum=0;
        for(int i=0;i<n;i++){
        cin>>a[i];sum+=a[i];}
        if(n==1){cout<<sum<<endl;return 0;}
    pr[0]=a[0];
    pr[1]=a[1];
    for(int i=2;i<n;i++)pr[i]=a[i]+pr[i-2];
    suf[n]=0;
    suf[n+1]=0;
    suf[n+2]=0;
    suf[n-1]=a[n-1];
    suf[n-2]=a[n-2];
    for(int i=n-3;i>=0;i--)suf[i]=a[i]+suf[i+2];
    ll mn=1e18;
    for(int i=0;i<n;i++)
    {
        //cout<<pr[i]<<" "<<suf[i]<<endl;
        ll u=pr[i-1]+suf[i+2];
        mn=min(mn,u);
    }
    sum-=mn;
    cout<<sum<<endl;

    return 0;

}