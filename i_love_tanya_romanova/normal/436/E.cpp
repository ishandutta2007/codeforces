/*
All around me are familiar faces
Worn out places, worn out faces
Bright and early for their daily races
Going nowhere, going nowhere

Their tears are fillin' up their glasses
No expression, no expression
Hide my head I want to drown my sorrow
No tomorrow, no tomorrow

And I find it kind of funny
I find it kind of sad
The dreams in which I'm dyin'
Are the best I've ever had

I find it hard to tell you
'Cause I find it hard to take
When people run in circles
It's a very, very

Mad world, mad world
Mad world, mad world

Children waitin' for the day they feel good
Happy birthday, happy birthday
Made to feel the way that every child should
Sits and listen, sits and listen

Went to school and I was very nervous
No one knew me, no one knew me
Hello teacher tell me what's my lesson?
Look right through me, look right through me

And I find it kind of funny
I find it kind of sad
The dreams in which I'm dyin'
Are the best I've ever had

I find it hard to tell you
'Cause I find it hard to take
When people run in circles
It's a very, very

Mad world, mad world
Mad world, mad world

And I find it kind of funny
I find it kind of sad
The dreams in which I'm dyin'
Are the best I've ever had

I find it hard to tell you
'Cause I find it hard to take
When people run in circles
It's a very, very

Mad world, mad world
I'm watching your world
Mad world
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

long long ans;
long used[500000],a[500000],b[500000];
set<pair<long, long> > s1,s2;
long ps,val;
long n;
set<pair<long, long> >::iterator it;
pair<long, long> tp;
long need;
long c1,c2;

void take1()
{
 tp=(*s1.begin());
 s1.erase(s1.begin());
 ps=tp.second;val=tp.first;
 if (used[ps]==0)s2.erase(make_pair(b[ps],ps));
 ans+=val;
 --need;
 if (used[ps]==0)s1.insert(make_pair(b[ps]-a[ps],ps));
 ++used[ps];
}

void take2()
{
 tp=(*s2.begin());
 s2.erase(tp);
 ps=tp.second;val=tp.first;
 s1.erase(make_pair(a[ps],ps));
 ans+=val;
 used[ps]=2;
 need-=2;
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>need;
for (int i=1;i<=n;i++)
{
 cin>>a[i]>>b[i];
 s1.insert(make_pair(a[i],i));
 s2.insert(make_pair(b[i],i));
}

while (need)
{
 if (need%2==1||s1.size()==1||s2.size()==0)
  take1();
  else
  {
   it=s1.begin();
   c1=(*it).first;
   ++it;
   c1+=(*it).first;
   it=s2.begin();
   c2=(*it).first;
   if (c1<c2)
   take1(),take1();
   else take2();
  }
}

cout<<ans<<endl;
for (int i=1;i<=n;i++)
 cout<<used[i];
cout<<endl;

cin.get();cin.get();
return 0;}