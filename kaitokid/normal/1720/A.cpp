#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll u=a*d,v=b*c;
    if(u==v){cout<<0<<endl;continue;}
    if(u<v)swap(u,v);
    if(v==0){cout<<1<<endl;continue;}
    if(((u%v)==0)){cout<<1<<endl;continue;}
    cout<<2<<endl;
}
return 0;
}