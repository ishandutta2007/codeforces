#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
int k=1;
while(n>0)
{
if(n==1){cout<<k;return 0;}
if(n==2){cout<<k<<" "<<2*k;return 0;}
if(n==3){cout<<k<<" "<<k<<" "<<3*k;return 0;}
for(int i=0;i<n/2+n%2;i++)cout<<k<<" ";
n/=2;
k*=2;


}
   return 0;
}