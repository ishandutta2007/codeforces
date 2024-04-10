#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
long n,fl,m,ar[20000],ara[20000];
 int main(){
 //   freopen("input.txt","r",stdin);
 //   freopen("output.txt","w",stdout);)answ=max(answ,ans[i]);
cin>>n;
for (int i=1;i<=n;i++)cin>>ar[i];
for (int i=1;i<=n;i++)ara[i]=i;

for (int i=1;i<=n;i++)
for (int j=i+1;j<=n;j++)
if (ar[i]>ar[j]){swap(ar[i],ar[j]);
swap(ara[i],ara[j]);}

if (ar[1]==ar[n])
{cout<<"Exemplary pages."<<endl;cin.get(); cin.get();return 0;}
if (n<3||ar[2]*2==ar[1]+ar[n])fl=1; else fl=0;
if ((ar[1]!=ar[n]&&ar[2]==ar[n-1]&&(ar[n]-ar[1])%2==0&&fl)||(n==2&&(ar[2]+ar[1])%2==0))
{cout<<(ar[n]-ar[1])/2<<" ml. from cup #"<<ara[1]<<" to cup #"<<ara[n]<<"."<<endl;cin.get();cin.get();return 0;}
cout<<"Unrecoverable configuration."<<endl;
cin.get();cin.get();cin.get();
return 0;
}