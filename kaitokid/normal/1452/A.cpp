#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 int t,x,y;
 cin>>t;
 while(t--)
 {
     cin>>x>>y;
     if(x>y)swap(x,y);
     if(y<=x+1){cout<<x+y<<endl;continue;}
     int ans=2*x+1;
     y-=x+1;
     ans+=2*y;
     cout<<ans<<endl;
 }
    return 0;
}