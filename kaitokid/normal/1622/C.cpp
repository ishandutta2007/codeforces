#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200009],k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll s=0;
        for(int i=0;i<n;i++){cin>>a[i];s+=a[i];}
        k=max(0LL,s-k);
        ll ans=k;
        sort(a,a+n);
        ll r=0;
        for(int i=n-1;i>0;i--)
        {
            k-=a[i]-a[0];
            if(k<0){ans=min(ans,n-i);break;}
            ll u=n-i+1;
            ll p=(k+u-1)/u;
            ans=min(ans,p+n-i);
        }
        cout<<ans<<endl;
    }
    return 0;
}