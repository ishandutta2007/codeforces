#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300009],c[300009];
ll pr[300009][30],q;
ll g,f,w;
ll cal(ll x)
{
    ll rs=0;
    for(int i=29;i>=0;i--)
    if(a[pr[x][i]]>0){
            x=pr[x][i];rs|=(1<<i);}
    return rs;
}
ll anc(ll x,ll d)
{
    for(int i=29;i>=0;i--)
        if(d&(1<<i))x=pr[x][i];
        return x;
}
void go(ll x)
{

    ll r=min(a[x],w);
    g+=r;
    f+=r*c[x];
    a[x]-=r;
    w-=r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>q>>a[1]>>c[1];
    for(int i=2;i<=q+1;i++)
    {
        int t;
        cin>>t;
        if(t==1){cin>>pr[i][0]>>a[i]>>c[i];
        pr[i][0]++;
        for(int u=1;u<=29;u++)pr[i][u]=pr[pr[i][u-1]][u-1];
        continue;
        }
        ll x;
        cin>>x>>w;
        x++;
        ll d=cal(x);
        g=0,f=0;
        while((d>=0)&&(w>0))
        {
            go(anc(x,d));
            d--;
        }
      cout<<g<<" "<<f<<endl;
      fflush(stdout);
    }
    return 0;
}