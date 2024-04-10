#include <iostream>
#include <cmath>
#include <vector> 
#include <string> 
#include <algorithm>
#define M_PI 3.14159265358979323846
using namespace std;
long long n,ans,i;
int main(){
cin>>n;
ans=1;
if (n==0)cout<<1<<endl; else {
for (i=2;i<=n;i++){ans=ans*3%(1000003);}
cout<<ans<<endl;}
cin.get();cin.get();
return 0;}