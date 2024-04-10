#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll n,m,k;
    ll x,y;
set<ll> a[100009],b[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {

        cin>>x>>y;
        a[x].insert(y);
        b[y].insert(x);
    }
    set<ll>:: iterator it;
    x=1,y=1;
    ll mnx=1,mny=1,mxx=n,mxy=m;
    ll ans1=0;
    while(true)
    {

        if(!a[x].empty()){it=a[x].lower_bound(y); if(it!=a[x].end())mxy=min(mxy,(*it)-1);}
        ans1+=(mxy-y);
        y=mxy;
        mnx++;
        if(mxx<mnx||mxy<mny)break;
        if(!b[y].empty()){it=b[y].lower_bound(x); if(it!=b[y].end())mxx=min(mxx,(*it)-1);}
        ans1+=(mxx-x);
        x=mxx;
        mxy--;
        if(mxx<mnx||mxy<mny)break;
        if(!a[x].empty()){it=a[x].lower_bound(y);if(it!=a[x].begin())

            {
                it--;
                mny=max(mny,(*it)+1);
            }
        }
    ans1+=(y-mny);
    y=mny;
    mxx--;
    if(mxx<mnx||mxy<mny)break;
    if(!b[y].empty()){it=b[y].lower_bound(x);if(it!=b[y].begin())

            {
                it--;
                mnx=max(mnx,(*it)+1);
            }
        }
    ans1+=(x-mnx);
    x=mnx;
    mny++;
    if(mxx<mnx||mxy<mny)break;
    }
    if(ans1+1==((n*m)-k))cout<<"Yes";
    else cout<<"No";
    return 0;
}