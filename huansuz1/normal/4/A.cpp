#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cmath>      
using namespace std;
long long a,b,c,s,t,z,zz;

int main(){
cin>>a;
z=1;
for (int i=2; i<=a/2; i+=2)
if ((a-i)%2==0) { z=0; break; }
if (z==1) cout<<"NO"; else cout<<"YES";
return 0;
}