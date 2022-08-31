/*
, ,
 ,
,   
 .
     ,
   
,  ...

:
!
,   
   ?!
!
  ,   ,
    !
,  ...
!  !

,  -
  -
   
  ...
  ,   
,   
 ...

 (2)

,  ...
!
*/

#pragma comment(linker, "/STACK:16777216")
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

using namespace std;

long long a,b,n;
long long need,p;

long long pw(long long a,long long b)
{
 long long r=1;
 for (int i=1;i<=b;i++)
  r*=a;
  return r;
}

void solve()
{
 if (a==0&&b!=0){cout<<"No solution"<<endl;return;}
 if (a==0&&b==0){cout<<1<<endl;return;}
 if (b%a){cout<<"No solution"<<endl; return;}
 need=b/a;
 if (n%2==0&&need<0){cout<<"No solution"<<endl;return;}
 p=pow(fabs(need)+1e-6,1.0/n);
 if (pw(p,n)!=abs(need)){cout<<"No solution"<<endl;return;}
 if (need<0)cout<<-p<<endl;
 else cout<<p<<endl;
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b>>n;
solve();

cin.get();cin.get();
return 0;}