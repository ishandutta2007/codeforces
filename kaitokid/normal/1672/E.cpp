#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009];
int b[200009],fr[200009];
int main()
{
    int n;
    cin>>n;
    int l=1,r=1e7;
    while(l<r)
    {
        int mid=(l+r)/2;
        cout<<"? "<<mid<<endl;
        fflush(stdout);
        int x;
        cin>>x;
        if(x==1)r=mid;
        else l=mid+1;
    }
    ll ans=l;
    for(int i=2;i<=n;i++)
    {
        int u=(l-(i-1));
        u=(u+i-1)/i;
        cout<<"? "<<u<<endl;
        fflush(stdout);
        int x;
        cin>>x;
        if(x!=0)ans=min(ans,u*1LL*x);
    }
    cout<<"! "<<ans<<endl;
    fflush(stdout);



return 0;
}