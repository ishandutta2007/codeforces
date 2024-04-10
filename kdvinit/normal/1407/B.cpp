/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

int gcd(int a,int b)
{
    if(a%b==0) return b;
    a%=b;
    return gcd(b,a);
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+n+1);
    int freq[n+1]={0},temp;

    freq[n]=1;
    cout<<a[n]<<" ";
    temp=a[n];

    for(int i=1;i<n;i++)
    {
        int mx=0,tmpmx,mxi;
        for(int j=1;j<n;j++)
        {
            if(freq[j]==1) continue;
            tmpmx=gcd(temp,a[j]);
            if(tmpmx>mx)
            {
                mx=tmpmx;
                mxi=j;
            }
        }
        temp=mx;
        cout<<a[mxi]<<" ";
        freq[mxi]=1;
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}