/*
We collapse, hands interlude
Cheek against cheek a pulse duet hums
Through our veins and I'm not sure why
And I continue

When we start to embarrass each other
As our lies attain bi-partial virtue
And all I want is to die
All I want is to die

I gain and lose control
Like some fucked up lust opiate

And now you will forever abhor me
As I purge myself one piece at a time

I won't forget my reflection
Loved and lost in between your thighs
And don't forget how I can't forget you
I continue

When we start to embarrass each other
Hypnotic and gross, stained with a big deal
And all I want is to die
All I want is to die

I gain and lose control
Like some fucked up lust opiate

And now you will forever abhor me
As I purge myself one piece at a time
I'd rather erase my two ton impact on your life
This shouldn't be my only way out

Anxious to have validity
Knowing I just take up space
I'll continue to swell
Thanks to the induction of severity

With pitiless blows
With pitiless blows

And now you will forever abhor me
As I purge myself one piece at a time
I'd rather erase my two ton impact on your life
This shouldn't be my only way out
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,er;
string st[1<<20];
string tst;

string better(string st1,string st2)
{
// cout<<st1<<"  "<<st2<<endl;
 if (st1.size()<st2.size())return "*";
 if (st1.size()>st2.size())
 {
  for (int i=0;i<st1.size();i++)
  {
   if (st1[i]!='?')continue;
   if (i==0)st1[i]='1';else st1[i]='0';
  }
  return st1;
 }
 
 for (int i=st1.size();i>=0;--i)
 {
  //if (i<st1.size()&&st1[i]!='?')continue;
  if (i<st2.size()&&st2[i]=='9')continue;
  tst=st1;
  if (i<st1.size()&&tst[i]=='?')tst[i]=st2[i]+1;
  for (int j=i+1;j<tst.size();j++)
   if (tst[j]=='?')tst[j]='0';
   long f=0;
  for (int j=0;j<i;j++)
   if (tst[j]=='?') tst[j]=st2[j];
   else
   {
    if (tst[j]!=st2[j])f=1;
   }
//   cout<<tst<<endl;
   if (f)continue;
  if (tst>st2) return tst;
 }
 return "*";
}
int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;

st[0]="0";

for (int i=1;i<=n;i++)
 cin>>st[i];

for (int i=1;i<=n;i++)
{
 st[i]=better(st[i],st[i-1]);
// cout<<st[i]<<endl;
 if (st[i]=="*")
  {er=1;break;}
} 
if (er)cout<<"NO"<<endl;
else
{
 cout<<"YES"<<endl;
 for (int i=1;i<=n;i++)
 {
  cout<<st[i]<<endl;
 }
}

cin.get();cin.get();
return 0;}