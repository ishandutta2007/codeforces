#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cmath>      
using namespace std;
long long a[100],n,b,c,s,t,z,zz;

int main(){
cin>>n>>b;
for (int i=1; i<=n; i++)
cin>>a[i];
for (int i=1; i<=n; i++)
{
if (a[i]>=a[b]&&a[i]>0) z++;
 }
 cout<<z;
return 0;
}