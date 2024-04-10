
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long stq,flag,qq,qs,m;
bool pr[11000000];
long s[11000000],num[11000000];
long long tpow[1100000];
long long n,q,qpow,r;
vector<long long> v;
long long temp,l,mid;

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

pr[1]=1;
for (int i=2;i<=10000000;i++)
if (pr[i]==0)
for (int j=i*2;j<=10000000;j+=i)
pr[j]=1;

for (int i=1;i<=10000000;i++)
if (pr[i]==0)
v.push_back(i);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;num[q]++;
}

for (int i=1;i<=10100000;i++)
{s[i]=s[i-1]+num[i];}

//cout<<v.size()<<endl;

for (int i=0;i<v.size();i++)
{
 stq=v[i];
 while (stq<=10000000)
 {
  q=stq;qpow=1;
  while (q<=10000000)
 {
  r=q+stq;
  if (r>10000000)r=10000001;
  if (s[r-1]-s[q-1]!=0)
  //cout<<r<<" "<<q<<" "<<qpow<<endl;
  
  tpow[i]+=qpow*(s[r-1]-s[q-1]);
  ++qpow;
  q+=stq;
 }   stq*=v[i];
 } 
}

//for(int i=0;i<5;i++)
//cout<<i<<" "<<tpow[i]<<endl;

l=1;
r=1000000000000000ll;
while (l<r)
{
      mid=l+r;
      mid/=2;
      flag=0;
      for (int i=v.size()-1;i+1;i--)
      {
          qq=mid;
          qs=0;
          while(qq){temp=qq/v[i];qs+=temp;qq=temp;}
          if (qs<tpow[i])flag=1;
          if (flag)break;
        //  if (i==0)cout<<qs<<" "<<mid<<endl;
      }
//      cout<<mid<<" "<<qs<<endl;
      
      if (flag)l=mid+1;
      else r=mid;
}
cout<<l<<endl;

cin.get();cin.get();
return 0;}