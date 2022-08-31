/*
Whenever I stumble, Whenever I fall
Whenever I'm pushed against the wall
The white man's world won't tell me what to do
Nowhere to run, my native blood
I want to reach and touch the sun
Blistering my soul but I can't feel
You hear me say, get out of my way
I'll do it my own way
Cross my path and get what you deserve
I'm warning this world
To stay out of my way
My voice will be heard
I'm alone
I won't be afraid
I got something to say
My voice will be heard
So loud
Native Blood
Forever proud, so goddamn loud
It's me alone against the crowd
Right or wrong it's the road I must choose
There's no excuse, attitude
Got something here the I must prove
Live to win instead of born to lose
I'm warning this world
To stay out of my way
My voice will be heard
So strong
I won't be afraid
I got something to say
My voice will be heard
So loud
Native Blood
I learned to walk before I could crawl
Whenever pushed, I push back
Not afraid to throw the first punch
I'm never wrong 'cause I'm always right
And when I'm wrong i won't admit it
I'm the person your mother warned you about
They broke the mould after I came out
What gives me strength is my beliefs
Whenever I stumble, Whenever I fall
I won't be pushed against the wall
The white man's world won't tell me what to do
Nowhere to run, native blood
I want to reach and touch the sun
Blistering my soul but I can't feel
I'm warning this world
To stay out of my way
My voice will be heard
I'm alone
I won't be afraid
I got something to say
My voice will be heard
So loud
Native Blood
I'm warning this world
To stay out of my way
My voice will be heard
So strong
I won't be afraid
I got something to say
My voice will be heard
So loud
Native Blood
My Native Blood
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

long n,ar[1<<20];
map<long,long> has,was;
long t[1<<20];
long long ans;

long sum(long r)
{
 long res=0;
 for (;r>=0;r=(r&(r+1))-1)
  res+=t[r];
 return res;
}

void inc(long i,long val)
{
 for (;i<1000100;i=(i|(i+1)))
  t[i]+=val;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int i=n;i;--i)
{
 ++has[ar[i]];
 inc(has[ar[i]],1);
}

for (int i=1;i<=n;i++)
{
 inc(has[ar[i]],-1);
 --has[ar[i]];
 ++was[ar[i]];
 ans+=sum(was[ar[i]]-1);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}