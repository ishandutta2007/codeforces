/*
   ,
    .
 
  
 ,   .

:
    .
    .
     ,
   .

  ,   .
 ,   .
  
  
    .



    .
 ,  .
 
 
    .

 (2)
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long long n,m,k;

long long gett(long long span, long long cuts)
{
 if (cuts<=0)return span;
 ++cuts;
 if (cuts>span)return -1;
 return span/cuts;
}

long long solve()
{
 if (n-1+m-1<k)return -1;
 long long res=0;
  for (long long i=0;i<=40000;i++) 
  res=max(res,n/(i+1)*gett(m,k-i));
  
  long long cdo;
  
  for (long long i=1;i<=40000&&i<=n;i++)
  {
   cdo=n/i-1;
   res=max(res,i*gett(m,k-cdo));
  }
  return res;
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
cout<<solve()<<endl;
//cout<<n*m-solve()*(k+1)<<endl;

cin.get();cin.get();
return 0;}