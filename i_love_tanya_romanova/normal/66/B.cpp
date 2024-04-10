#include <math.h>
#include <iostream>
#include <algorithm>
//#include <fstream>
#include <string>
#include <vector>
#define M_PI        3.14159265358979323846
using namespace std;
long n,i,ar[10000],ans,s,q;
int main()
{//freopen("C://input.txt","r",stdin);freopen("C://output.txt","w",stdout);
cin>>n;
for (i=1;i<=n;i++)
{cin>>ar[i];}
ar[0]=ar[n+1]=1000000000;
for (i=1;i<=n;i++)
{s=1;q=i-1;while (ar[q]<=ar[q+1]){s++;q--;}
 q=i+1;
 while (ar[q]<=ar[q-1]){s++;q++;}
 ans=max(ans,s);}
 cout<<ans<<endl;
cin.get();cin.get();
return 0;}