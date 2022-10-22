#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool vis[1000009];
int main()
{
    ios::sync_with_stdio(0);
long double t,l,r,x,y,k;

cin>>k>>l>>r>>t>>x>>y;
if(k+y<=r)k+=y;
if(x>y)
{
    k-=(t-1)*(x-y)+x;
    if(k>=l)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
r-=l;
k-=l;
ll d=(r-y);
if(d>=x-1){cout<<"Yes";return 0;}
ll z=x,h=k,ss=y;
ll u=h%z;
ll p=0;
while(true)
{
    if(u>d)break;
    if(vis[u]){p=-1;break;}
    vis[u]=1;
    p++;
    u=(u+ss)%z;


}
if(p==-1){cout<<"Yes\n";return 0;}
long double gg= k+y*p;
long double ff=gg/x;
if(ff>=t)cout<<"Yes";
else cout<<"No";
    return 0;
}