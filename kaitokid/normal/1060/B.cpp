#include<bits/stdc++.h>	
using namespace std;
typedef long long ll;
ll n,ans;
int main() 
{ 
cin>>n;
while(n>0)
{
if(n>=9){ans+=9;n-=9;}
ans+=n%10;
n/=10;

}
cout<<ans;
}