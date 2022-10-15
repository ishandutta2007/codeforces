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

    query(1,n);
    int pos=p;

    int side=0;

    if(pos!=1)
    {
        query(1,pos);
        if(p==pos) { l=1; r=pos-1; side=0; }
        else { l=pos+1; r=n; side=1; }

    }
    else { l=pos+1; r=n; side=1; }

    int ans;
    while( l<r )
    {
        int mid=(l+r)/2;

        if(l+1==r)
        {
            if(side==0)
            {
                query(r,pos);
                if(p==pos) ans=r;
                else ans=l;
            }
            else
            {
                query(pos,l);
                if(p==pos) ans=l;
                else ans=r;
            }
            break;
        }

        if(side==0)
        {
            query(mid,pos);
            if(p==pos) l=mid;
            else r=mid;
        }
        else
        {
            query(pos,mid);
            if(p==pos) r=mid;
            else l=mid;
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