#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool bl[100000];
int main()
{
ios::sync_with_stdio(0);
ll a,b;
cin>>a>>b;
ll ans=sqrt(2*(a+b));
while((ans*(ans+1))/2>a+b)ans--;
ll ansa=sqrt(2*a);
while((ansa*(ansa+1))/2>a)ansa--;
cout<<ansa<<endl;
ll h=a-((ansa*(ansa+1))/2);
ll q=ansa+1-h;
for(ll i=1;i<=ansa+1;i++)
    if(i==q)continue; else cout<<i<<" ";
cout<<endl;
cout<<ans-ansa<<endl;
if(ans-ansa>0)
cout<<q<<" ";
for(ll i=ansa+2;i<=ans;i++)cout<<i<<" ";

    return 0;
}