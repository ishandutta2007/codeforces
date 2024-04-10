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

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int m=n/2;

    int l=m,r=n,b[n+1],strt=1,ans=0;

    int freq[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        if(i%2==1) { freq[r]=1; b[i]=a[r--]; }
        if(i%2==0)
        {
            while(l>0 && a[l]>=a[r]) l--;
            if(i!=n && l>0)
            {
                b[i]=a[l];
                ans++;
                freq[l]=1;
                l--;
            }
            else
            {
                while(freq[strt]==1) strt++;
                b[i]=a[strt];
                freq[strt]=1;
            }
        }
    }

    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}