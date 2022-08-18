/*
     i
 i i  .
     i ,
   .

 , ,   -
 ,   .
 , ,   -
 , ...

    i ,
    .
   i i
 ...   i?

 , ,   -
 ,   .
 , ,   -
 ,   .

 , ,   -
 ,   .
 , ,   -
 ,   .
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
#define N 120000

using namespace std;

long long x,y,c,d,a,b;

long long gcd(long long a,long long b,long long& x,long long &y)
{
 if (a==0)
 {
  x=0,y=1;return b;
 }
 long long x1,y1;
 long long d=gcd(b%a,a,x1,y1);
 x=y1-b/a*x1;
 y=x1;
 return d;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b>>c;
c*=-1;
d=gcd(a,b,x,y);
if (c%d)cout<<-1<<endl;
else cout<<x*c/d<<" "<<y*c/d<<endl;

cin.get();cin.get();
return 0;}