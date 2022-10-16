/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;

    int a[n+1]={0},cnt1=0,cnt0,b[n+1];
    char x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x=='1') { a[i]=1; cnt1++; }
    }
    cnt0=n-cnt1;

    int cntr=0,j=n+1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            cntr++;
            if(k<(i-cntr)) { j=i; cntr--; break; }
            k-=(i-cntr);
        }
    }

    for(int i=1;i<=cntr;i++) b[i]=0;
    for(int i=cntr+1;i<j;i++) b[i]=1;
    for(int i=j;i<=n;i++) b[i]=a[i];

    if(j<=n)
    {
        while(k--)
        {
            swap(b[j],b[j-1]);
            j--;
        }
    }

    for(int i=1;i<=n;i++) cout<<b[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}