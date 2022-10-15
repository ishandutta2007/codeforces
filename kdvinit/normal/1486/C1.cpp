/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int p;
void query(int l,int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>p;
}

void solve()
{
    int n;
    cin>>n;

    int l=1,r=n;
    int ans;

    while( l<r )
    {
        query(l,r);

        if(l+1==r)
        {
            if(p==l) ans=r;
            else ans==l;
            break;
        }

        int mid=(l+r)/2;
        int val=p;

        if(p<=mid)
        {
            query(l,mid);
            if(p==val) r=mid;
            else l=mid;
        }
        else
        {
            query(mid,r);
            if(p==val) l=mid;
            else r=mid;
        }
    }

    if(l==r) ans=l;
    cout<<"! "<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}