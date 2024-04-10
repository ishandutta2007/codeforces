/*
Why do you need to look at me?
Why do you need some fuckin' writings to be sure?
Why do you need to compare you?
Probably cause you need a fuckin' self defense...

Why do you need to look at me?
Why do you need some fuckin' writings to be sure?
Why do you need to observe them?
Why do you need to watch tears flowing in their eyes?

You are your self aggression!
You are the self problem of your life!

Why do you need to watch tears flowing in their eyes?
To feel so stronger that you will be never!

Your demonic defense inspires him! You are just like me!
Your demonic defense inspires him! You are just like my mind!

You're feeling something twisting under your skin
The devil is inside!
It's not too late to face your demonic defense
Made in fear by yourself

Don't look around! Cause you'll fear the future!
Don't look at me! Cause there will be a suicide!

Why do you need to look at me?
Why do you need some fuckin' writings to be sure?
Why do you need to compare you?
Probably cause you need a fuckin' self defense...

Why do you need to watch tears flowing in their eyes?
To feel so stronger that you will be never!
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
 
using namespace std;

long pr[1<<20];
long a,b,k;
vector<long> primes;
long mdiv[1<<20];

long solve(long x,long k)
{
 if (x/k<=50000)
 {
  long q=0;
  for (int i=1;i<=x/k;i++) 
   if (mdiv[i]>=k)++q;
  return q;
 }
 long res=x/k;
 for (int i=0;i<primes.size();i++)
 {
     if (primes[i]>=k)break;
     res-=solve(x/k,primes[i]);
 }
 return res;
}

bool prime(long x)
{
 for (int i=2;i*i<=x;i++)
  if (x%i==0) return false;
 return true;
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pr[1]=1;
mdiv[1]=2e9;

for (int i=2;i<=50000;i++)
 if (pr[i]==0){mdiv[i]=i;
  for (int j=i*2;j<=50000;j+=i)
   {
    if (pr[j]==0)mdiv[j]=i;
    pr[j]=1;
   }}

/*for (int i=1;i<=20;i++)
 cout<<i<<" "<<mdiv[i]<<endl;
 cout<<endl;
 */

for (int i=2;i<=50000;i++)
 if (pr[i]==0)
  primes.push_back(i);
  
cin>>a>>b>>k;
if (prime(k)==0)
 cout<<0<<endl;
 else
cout<<solve(b,k)-solve(a-1,k)<<endl;

cin.get();cin.get();
return 0;}