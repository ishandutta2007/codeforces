#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        ll ans;
        if(l%2)
        {
            if(r%2) ans=(r-l)/2,ans+=-1*r;
            else ans=(r-l+1)/2;
        }
        else
        {
            if(r%2) ans=(r-l+1)/2*-1;
            else ans=(r-l)/2*-1,ans+=r;
        }
        cout<<ans<<endl;
    }
}