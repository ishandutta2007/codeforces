/*  
  
  ,
  ,
  .

   
 ,  ,
    
    .

  ,
   .
, , ,
  .

   
 ,  ,
    ,
    .

   
   ,
  ,
    .

   
 ,  ,
 ,  , 
    ...
*/

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
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg

using namespace std;

long long ms,l,c,m,r,s;
vector<long long> ans;
long long fl,d;

long long gf(long long x)
{
       long  q=x;
    s=0;
    while (q%2==0){s+=q/2;q/=2;}
    s+=q*(q-1)/2;
    return s;
}
int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
/*
for (int i=1;i<=100;i++)
{
  long  q=i;
    s=0;
    while (q%2==0){s+=q/2;q/=2;}
    s+=q*(q-1)/2;
    cout<<i<<" "<<s<<" "<<q<<" "<<(2*s-q*q)/q<<endl;
    
}*/


cin>>c;
//c=1000000001ll*1000000000/2;

/*c=(1ll<<60)-1;
cout<<c<<endl;
*/
l=0;
r=sqrt(c*1.0);
r+=1000000000;
//cout<<l<<" "<<r<<endl;
while (l<r)
{m=l+r;
m/=2;
s=m*(m-1)/2;
if (s==c)if (m%2==1){ans.push_back(m);break;}
if (s<c)l=m+1;
else r=m;
//cout<<l<<" "<<r<<" "<<m<<endl;
}
/*
for (int i=0;i<ans.size();i++)
cout<<ans[i]<<" ";
cout<<endl;
*/
c*=2;
for (int bs=1;bs<=60;bs++)
{
    ms=2*(1ll<<bs);
    ms-=3;
    l=1;
    r=c;
    
    while (l<r)
    {
     m=l+r+1;
     m/=2;
     fl=0;
     if (c/m<m){fl=1;}
     if (fl==0)
     {
      d=c-m*m;
      if (d/ms<m){fl=1;}
      //if (d/ms==m&&d%ms>0)fl=1;
     }     
     if (fl==0)l=m;
     else r=m-1;
    }
    if (l*l+l*ms==c){if (l%2)ans.push_back(l*(1ll<<bs));//cout<<l<<" "<<ms<<" "<<l*(1ll<<bs)<<endl;
    }
}

if (ans.size()==0)ans.push_back(-1);
sort(ans.begin(),ans.end());
vector<long long> ans1=ans;
ans.clear();

for (int i=0;i<ans1.size();i++)
{
 //   if (ans1[i]%2!=0)
    if (i==0||ans1[i]!=ans1[i-1])ans.push_back(ans1[i]);
}

if (ans.size()==0)ans.push_back(-1);

for (int i=0;i<ans.size();i++)
cout<<ans[i]<<endl;

cin.get();cin.get();
return 0;}