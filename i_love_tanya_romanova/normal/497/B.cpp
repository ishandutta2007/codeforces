/*
Feelings cold as ice, I never, never think twice
Hunting down my prey - they die
Cross my line of death and there's nothing else left
Any way you choose - you lose
Architect of pain, deadly is my middle name
And I'm living proof - crime pays
I'm a psychopath and I create the aftermath
That sets the sun forever - on you

Haven't you figured out it open season?
I'll track you down and kill you for no apparent reason
Running like a frightened little rabbit would run
I won't be satisfied
Until you're nullified
Before my eyes

Intoxicating
Invigorating
It's open season on you

Calling the police and I'm gonna pull my piece
Your heart's gonna cease - to beat
Just look in my eye, black as pitch to horrify
You can scream and cry - goodbye
It may never last and I blame it on the past
Being told to kill - at will
Shivers down my spine when the victim is all mine
You begin to beg - for help

Haven't you figured out it open season?
I'll track you down and kill you for no apparent reason
Running like a frightened little rabbit would run
I won't be satisfied
Until you're nullified before my eyes

Intoxicating, invigorating
It's open season on you

Go ahead and run, the chase is always fun
But the kill is the icing on the cake
A curtain of red from my hailstorms of lead
Will rain on you as you die
Your face will be spewing chunks of bloody ruin
Your baby face will be a gory mask
My personal crusade is to see that you are flayed
And my hunting knife will complete the task
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
#define bs1 1000000007ll
#define bs2 1000000009ll
#define P1 173
#define P2 187
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n;
long ar[1<<20];
long ttl[10];
long y;
long pt[10];
vector<pair<long, long> > ans;
long s[1<<20][3];

void check(long x)
{
 long set[10];
 set[1]=set[2]=0;
 long qp=0;
 long win=0;
 
 while (true)
 {
  long l,r;
  long mid;
  l=qp+1;
  r=n+1;
  while (l<r)
  {
   mid=l+r;
   mid/=2;
   if (s[mid][1]-s[qp][1]<x&&s[mid][2]-s[qp][2]<x)
    l=mid+1;
    else r=mid;
  }
  if (l>n)return;
  if (s[l][1]-s[qp][1]==x)
   win=1,set[1]++;
   else win=0,set[2]++;
  qp=l;
  if (qp==n)break;
//  cout<<qp<<endl;
 }
 //cout<<win<<" "<<set[1]<<" "<<set[2]<<endl;
 
 if (set[1]>set[2]&&win==1)
  ans.push_back(make_pair(set[1],x));
}

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

if (ar[n]==2)
 for (int i=1;i<=n;i++)
  ar[i]=3-ar[i];

for (int i=1;i<=n;i++)
 s[i][1]=s[i-1][1]+(ar[i]==1),
 s[i][2]=s[i-1][2]+(ar[i]==2);

  
for (int i=1;i<=100000;i++)
{
    check(i);
}

sort(ans.begin(),ans.end());

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
 
cin.get();cin.get();
return 0;}