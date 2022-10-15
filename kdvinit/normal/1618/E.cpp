/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int b[n+1], a[n+1];
    for(int i=1; i<=n; i++) cin>>b[i];

    for(int i=1; i<=n; i++)
    {
        int prv=i-1;
        if(i==1) prv=n;
        a[i] = b[i]-b[prv];
    }

    int rem = a[1]%n;
    if(rem<0) rem+=n;

    for(int i=1; i<=n; i++)
    {
        int cur = (a[i]%n);
        if(cur<0) cur+=n;
        if(cur!=rem) { cout<<"NO"<<endl; return; }
    }

    //sum = n*x + rem;
    int sum=0, tot=0;
    for(int i=1; i<=n; i++)
    {
        int tmp = (rem-a[i])/n;
        int y = (n+1-i);
        tmp*=y; tot+=y;
        sum+=tmp;
    }
    b[n]-=sum;

    if(b[n]%tot!=0) { cout<<"NO"<<endl; return; }

    int s = (b[n]/tot)*n + rem;

    for(int i=1; i<=n; i++)
    {
        a[i] = (s-a[i])/n;
        if(a[i]<=0) { cout<<"NO"<<endl; return; }
    }

    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}