#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
long n,f,ar[1000],i,t,qw,ans;char q;string st;
int main(){
    freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  cin>>n;getline(cin,st);
  for (i=1;i<=n;i++){cin>>q;ar[i]=q-48;}ans=-1;
  for (i=1;i<=n;i++){if (ar[i]==1&&t>=2&&i-qw!=ans)f++;
  if (ar[i]==1){t++;if (t==1)qw=i;if (t==2)ans=i-qw;
  qw=i;};}
  if (f==0)cout<<"YES"<<endl; else cout<<"NO"<<endl;cin>>i;
return 0;}