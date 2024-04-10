/*
K.D. Vinit  |,,| :)
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int infy=1e18;
int neg_infy=(-1)*infy;

void solve()
{
    int k,k2,x,y;
    cin>>k;
    k2=k/2;

    if(k==1) { cin>>x; cout<<x<<endl; return; }

    int a[k],sum=0,Len,n=0,m=0;
    for(int i=1;i<=k;i++)
    {
        cin>>x;
        a[i-1]=x;
        if(i==2) Len=x;
        if(i%2==0) Len=max(Len,x);
        if(x>=0) n++;
        else m++;
        sum+=abs(x);
    }
    sort(a,a+k);

    int key1,key2;
    if(k%3==0) key1=1;
    if(k%3==1) key1=0;
    if(k%3==2) key1=2;
    key2=m%3;

    x=key2-key1;
    if(x<0) x+=3;
    y=3-x;
    int ans1=neg_infy,ans2=neg_infy;
    if(m>=x)
    {
        ans1=sum;
        for(int i=1;i<=x;i++) ans1+=(2*a[m-i]);
        if(k%2==1 && k2==(m-x) && Len==a[m-x-1] )
        {
            ans1+=(2*a[m-x-1]);
            ans1-=(2*a[m-x]);
        }
    }
    if(n>=y)
    {
        ans2=sum;
        for(int i=1;i<=y;i++) ans2-=(2*a[m+i-1]);
        if(k%2==1 && k2==(m+y) && Len==a[m+y-1] )
        {
            ans2+=(2*a[m+y-1]);
            ans2-=(2*a[m+y]);
        }
    }
    int ans=max(ans1,ans2);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}