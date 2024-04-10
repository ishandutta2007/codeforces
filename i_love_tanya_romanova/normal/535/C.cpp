/*
You come to me with salvation
Saying I must repent
You offer up your redemption
A guarantee for a better life in your safe world

Your illusions are comfort for your conscience
My sacrifices will be made
In honor of what is truly sacred

How can you save me
When you can't save yourself?

You can't save yourself
You can't save yourself
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

using namespace std;

long long A,B,tests,s[1<<23];
long long l,t,m;

long long get_s(long long x)
{
 return A+1ll*(x-1)*B;
}

long long safe_mult(long long a,long long b)
{
 if (a==0||b==0)return 0;
 if (1e18/b<=a)return 1e18;
 return a*b;
}

bool check(long long ps)
{
 if (get_s(ps)>t)return false;
 long long span=ps-l+1;
 long long val1=get_s(l);
 long long val2=get_s(ps);
 long long s=val1+val2;
 s=safe_mult(s,span);
 s/=2;
 long long iters=s/m+(s%m>0);
 return (iters<=t);
}

long long solve()
{
 if (get_s(l)>t) return -1;
 long long l1,r1;
 l1=l;
 r1=1e12;
 while (l1<r1)
 {
  long long mid=l1+r1+1;
  mid/=2;
  if (check(mid))l1=mid;
  else r1=mid-1;
 }
 return l1;
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>A>>B>>tests;

for (;tests;--tests)
{
 cin>>l>>t>>m;
 cout<<solve()<<endl;
}
cin.get();cin.get();
return 0;}