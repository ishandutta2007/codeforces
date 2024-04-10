/*
This is the sound of the lost
The beaten and broken
Rising up and finding what has been
Taken from us, from the shadows of the past
From the depth of our own failures

Stepping forward into the light
Denying our demise
Decimating all eternity
But with you only
You can place judgment upon me

Give me your broken
Give me your beaten
I will build them up
I will lead them to the threshold

Make you stronger
Make you believe
I am one and the same
But now I'm stronger than eternity

Within this army
This is more than a battle cry
It's the blood of my lifeline
Flowing faster

This is the sound of the lost
Beaten and broken
Decimating all fears
Stronger than ever, the young have retrieved
Ascension led to supremacy

Now we're stronger than ever
Harder than ever

Give me your broken
Give me your beaten
I will build them up
I will lead them to the threshold

To the threshold
This is more than a battle cry

We were the broken
We were the beaten
I was once like you
Now I push myself to the threshold

Because I am stronger
Because I believe
Now I spit in the face of defeat
Now I'm stronger than all uncertainty
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