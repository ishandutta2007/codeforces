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
int x;
cin>>x;
if(x==180){cout<<-1;return 0;}
int r=__gcd(180,x);
int y=x/r;
int n=180/r;
if(n<3||n-y<2)cout<<2*n<<endl;
else cout<<n<<endl;


}
    return 0;
}