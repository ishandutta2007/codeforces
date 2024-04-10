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
    int n;
    cin>>n;

    char comp[n+1];
    for(int i=1;i<n;i++) cin>>comp[i];
    comp[0]='.'; comp[n]='.';

    int a[n+1],h=n+1,l=n-1,b[n+1],temp,val;
    a[1]=n;

    for(int i=2;i<=n;i++)
    {
        if(comp[i-1]=='>')
        {
            a[i]=l--;
        }
        if(comp[i-1]=='<')
        {
            l++;
            temp=i;
            while(comp[i-1]=='<') i++;
            i--;
            for(int j=i;j>=temp-1;j--) a[j]=l--;
        }
    }

    h=n+1; l=n-1;
    b[n]=n;
    for(int i=n-1;i>0;i--)
    {
        if(comp[i]=='>') b[i]=h++;
        else b[i]=l--;
    }
    for(int i=1;i<=n;i++) b[i]-=l;

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;

    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}