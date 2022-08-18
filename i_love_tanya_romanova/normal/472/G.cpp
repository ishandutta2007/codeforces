/*
Wow, I'm sick of doubt
Live in the light of certain
South
Cruel bindings.
The servants have the power
dog-men and their mean women
pulling poor blankets over
our sailors

I'm sick of dour faces
Staring at me from the TV
Tower, I want roses in
my garden bower; dig?
Royal babies, rubies
must now replace aborted
Strangers in the mud
These mutants, blood-meal
for the plant that's plowed.

They are waiting to take us into
the severed garden
Do you know how pale and wanton thrillful
comes death on a strange hour
unannounced, unplanned for
like a scaring over-friendly guest you've
brought to bed
Death makes angels of us all
and gives us wings
where we had shoulders
smooth as raven's
claws

No more money, no more fancy dress
This other kingdom seems by far the best
until it's other jaw reveals incest
and loose obedience to a vegetable law.

I will not go
Prefer a Feast of Friends
To the Giant Family.
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
#define right adsgasgadsg

using namespace std;

string st1,st2;
long ar1[1<<18],ar2[1<<18];
unsigned long v1[35][1<<15],v2[35][1<<15];
long tests,a,b,c,res;
long of1,of2;
long prec[1<<17];

long calc(unsigned long x)
{
 long res=0;
 while (x){if (x%2)++res;x/=2;}
 return res;
}

long get(unsigned long x)
{
 //cout<<x<<" "<<prec[x>>16]+prec[x&65535]<<" "<<calc(x)<<endl;
 
 return prec[x>>16]+prec[x&65535];
}

long brute()
{
 long res=0;
 for (int i=0;i<c;i++)
  if (ar1[i+a]!=ar2[i+b])++res;
 return res;
}

int main(){
//freopen("army.in","r",stdin);
//freopen("army.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<(1<<16);i++)
 prec[i]=calc(i);
 
/*st1=st2="";
for (int i=0;i<=200000;i++)
 st1+=char(rand()%2+'0'),
 st2+=char(rand()%2+'0');
 */
cin>>st1;
cin>>st2;
for (int i=0;i<st1.size();i++)
 ar1[i]=st1[i]-48;
for (int i=0;i<st2.size();i++)
 ar2[i]=st2[i]-48;

for (int ofset=0;ofset<32;ofset++)
{
 for (int i=0;i+ofset<st1.size();i++)
 {
  v1[ofset][i/32]+=(1<<(i%32))*ar1[i+ofset];
 }
 for (int i=0;i+ofset<st2.size();i++)
 {
  v2[ofset][i/32]+=(1<<(i%32))*ar2[i+ofset];
 }
}

long iters,sp1,sp2;

cin>>tests;
for (;tests;--tests)
{
cin>>a>>b>>c;
/*a=rand()%100;
b=rand()%100;
c=199900;
*/
// cout<<brute()<<endl;
 res=0;
 of1=a%32;
 of2=b%32;
 
 iters=c/32;
 sp1=a/32;
 sp2=b/32;
 
 for (int i=0;i<iters;i++)
 {
  res+=get(v1[of1][sp1+i]^v2[of2][sp2+i]);
 }
 c-=iters*32;
 a+=iters*32;
 b+=iters*32;
 
 for (int i=0;i<c;i++)
 {
  if (ar1[a+i]!=ar2[b+i])++res;
 }
 cout<<res<<"\n";
}

cin.get();cin.get();
return 0;}