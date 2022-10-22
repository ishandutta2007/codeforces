#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v;
bool bl;
void go (ll x,ll y)
{
ll u=x/y;
if(x/u!=y)u++;
if(x/u!=y){return ;}
bl=false;
cout<<x<<" "<<u<<endl;

}
int main()
{

ios::sync_with_stdio(0);
 int n;
cin>>n;
ll x;
while(n--)
{
cin>>x;
if(x==0){cout<<1<<" "<<1<<endl;continue;}
ll d=sqrt(x);

d++;
 bl =true;
while(d*d-(d/2)*(d/2)<=x)
{
ll u=d*d-x;
ll r =sqrt(u);
if(r*r==u){go(d,r);if(!bl)break;}

d++;

}
if(bl)cout<<-1<<endl;


}
return 0;}