#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t;

    cin>>t;
    while(t--)
    {


   ll n,g,b;
   cin>>n>>g>>b;
   if(g>=b){cout<<n<<endl;continue;}
   ll u=((n+1)/2-1)/g;
   ll v=((n+1)/2)-u*g;
   ll r=u*(b+g)+v;
cout<<max(r,n)<<endl;
    }
    return 0;
}