#include <iostream>
#include <math.h>
#include <vector> 
#include <string> 
#include <stdio.h>
#include <algorithm>
#define M_PI 3.14159265358979323846
using namespace std;
long n,i,v,q,s[100000],ans;
int main()
{
//  freopen("input.txt","r",stdin);
 // freopen("output.txt","w",stdout);
cin>>n;
for (i=1;i<=n;i++){cin>>q;s[i]=s[i-1]+q;}
v=s[n]/2;
if (s[n]%2!=0)cout<<0<<endl; else
{for (i=1;i<n;i++)if (s[i]==v)ans++;
cout<<ans<<endl;}
cin.get();cin.get();cin.get();
return 0;}