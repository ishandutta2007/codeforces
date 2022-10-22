#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,t,x1,x2,y2,x3,y3,x4,y4;
int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)
{
    ll y1;
    cin>>n>>m>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    ll w=(n*m)/2;
    ll b=(n*m)/2;
    if(((n*m)%2)==1)w++;
  ll h1 =x2-x1+1;
    ll h2=y2-y1+1;
    ll w1=(h1*h2)/2;
    ll b1=w1;
    if((h1*h2)%2==1)if((x1+y1)%2==0)w1++; else b1++;
    w+=b1;
    b-=b1;
     h1 =x4-x3+1;
     h2=y4-y3+1;
    ll w2=(h1*h2)/2;
    ll b2=w2;
    if((h1*h2)%2==1)if((x3+y3)%2==0)w2++; else b2++;
    b+=w2;
    w-=w2;
    x1=max(x1,x3);
    y1=max(y1,y3);
    x2=min(x2,x4);
    y2=min(y2,y4);
    if(x2<x1||y2<y1){cout<<w<<" "<<b<<endl;continue;}
  h1 =x2-x1+1;
     h2=y2-y1+1;
     w1=(h1*h2)/2;
     b1=w1;
    if((h1*h2)%2==1)if((x1+y1)%2==0)w1++; else b1++;
    w-=b1;
    b+=b1;
    cout<<w<<" "<<b<<endl;

}

 return 0;
}