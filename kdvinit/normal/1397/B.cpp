/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

void solve()
{
    long long int n;
    cin>>n;

    long long int a[n];
    for(long long int i=0;i<n;i++) cin>>a[i];

    sort(a,a+n);
    long long int mx=1e15,ans=1e15;

    for(long long int i=1;1;i++)
    {
        long long int temp=0,cnt=1,x,j;
        for(j=0;j<n;j++)
        {
            x=abs(a[j]-cnt);
            temp+=x;
            cnt*=i;
            if(cnt>mx) break;
        }
        if(j!=n) break;
        ans=min(ans,temp);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}