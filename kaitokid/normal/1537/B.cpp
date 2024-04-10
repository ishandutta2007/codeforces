#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,x,y,mx,u1,v1,u2,v2;
ll dst(ll z,ll c, ll u,ll v)
{
    return abs(z-u)+abs(c-v);
}
void ch(ll a,ll b,ll q,ll w)
{
    ll r=dst(a,b,q,w)+dst(x,y,a,b)+dst(x,y,q,w);
    if(r>mx){mx=r;u1=a;v1=b;u2=q;v2=w;}

}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y;
        mx=-1;
        ch(1,1,n,m);
        ch(1,1,1,m);
        ch(1,1,n,1);
        ch(n,1,n,m);
        ch(n,1,1,m);
        ch(1,m,n,m);
        cout<<u1<<" "<<v1<<" "<<u2<<" "<<v2<<endl;

        }
    return 0;

}