/*
,   ,
   
   .
   ,
   .
   ,
   ,
   ...

,   ,
   
   .
   ,
   .
   
,   ,
   .

:
  ...

,    
 
 .
   ,
   
   
,  ,
,   .

,   ,
   ,
  
  ,
  ,
  ,
  
 .


*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

long have[15000000],n,k,val[100000];
long tests;
long need;
long ans,rem;
long tv;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{ 
 cin>>val[i];
 have[val[i]]=1;
 
}

cin>>tests;
for (;tests;--tests)
{
 cin>>need;
 ans=1000;
 
 for (long i=1;i<=n;i++)
 {
  for (long q=1;q<=k;q++)
  {
   rem=need-val[i]*q;
   if (rem<0)continue;
   if (rem==0)
   {
    ans=min(ans,q);continue;
   }
   for (long ad=1;ad+q<=k;ad++)
   {
    if (rem%ad)continue;
    tv=rem/ad;
    if (tv>11000000)continue;
    if (have[tv]==0)continue;
    ans=min(ans,q+ad);
   }
  }
 }      
 if (ans>500)cout<<-1<<endl;
 else cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}