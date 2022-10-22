#include <bits/stdc++.h>
using namespace std;
long long n,k;

int main()
{
cin>>n>>k;
long long mx=0;
cin>>mx;
long long d=mx,l=0,x;
for(int i=1;i<n;i++)
{
cin>>x;
if(x<d)l++;
if(x>d){l=1;d=x;}
if(l==k){cout<<d;return 0;}

}
cout<<d;
return 0;
}