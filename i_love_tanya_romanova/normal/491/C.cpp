/*
Tell you a thing that you ought to know
Two minutes of your time, then on you go
Tell tale of the men, all dressed in black
That most of them, not coming back

Sent off to war to play little games
And on their return, can't name no names
Some strange yellow gas
Has played with their minds
Has reddened their eyes, removed all the lies

And strange as it sounds, death knows no bounds
How many get well, only time will tell
Only time will tell

You lie in your death bed now
But what did you bring to the table?
Brought us only holy sin
Utter trust is a deadly thing

To the prayer of holy peace
We didn't know what was lying underneath
So how could we be such fools?
And to thing that we thought you the answer

I can't begin to understand in all the lies
But on your death bed, I can see it in your eyes
Just as clear as all the sweat upon your brow
It really makes sense, I can see it clearly now

Tangled up in a web of lies
Could have been a way to prophesize
Unaware of the consequence
Not aware of the secrets that you kept

Nothing that we could believe
To reveal the facade of faceless men
Not a thing that we could foresee
Now a sign that would tell us the outcome

You had us all strung out with promises of peace
But all along your cover plan was to deceive
Can it put to rights? Now only time will tell
Your prophecies will send us all to hell as well

Left to all our golden sons
All to pick up on the peace
You could have given all of them
A little chance at least

Take the world to a better place
Given them all just a little hope
Just think what a legacy
You know will leave

We seem destined to live in fear
And some that would say Armageddon is near
But where there's a life while there's hope
That man won't self destruct

Why can't we treat our fellow men
With more respect and a shake of their hands?
But anger and loathing is rife
The death on all sides is becoming a way of life

We live in an uncertain world
Fear, understanding and ignorance
Is leading to death
Only the corpses are left
For vultures that prey on their bones

But some are just not wanting peace
Their whole life is death and misery
The only thing that they know
Fight fire with fire, life is cheap

But if they do stop to think
That man is teetering right on the brink
But do you think do they care?
They benefit from death and pain and despair
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

long u[1<<20],v[1<<20],p[1<<20],way[1<<20];
long n,k,a[1<<10][1<<10];
long id1,id2;
string st1,st2;

long get(char c)
{
 if (c<='z'&&c>='a') return c-'a'+1;
 return c-'A'+27;
}

long N,M;
long ANS,ans[1<<20];

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
cin>>st1>>st2;

for (int i=0;i<st1.size();i++)
{
 id1=get(st1[i]);
 id2=get(st2[i]);
 a[id1][id2]--;
}

N=M=k;
for (int i=1;i<=N;i++)
{
    p[0]=i;
    long j0=0;
    vector<long> minv;
    minv.resize(M+1);
    for (int j=0;j<minv.size();j++)
     minv[j]=1e9;
    vector<long> used;
    used.resize(M+1);
    for (int j=0;j<used.size();j++)
     used[j]=0;
    
    do
    {
     used[j0]=1;
     long i0,delta,j1;
     i0=p[j0];
     delta=1e9;
     for (int j=1;j<=M;j++)
     {
         if (used[j])continue;
         long cur=a[i0][j]-u[i0]-v[j];
         if (cur<minv[j])
          minv[j]=cur,way[j]=j0;
         if (minv[j]<delta)
          delta=minv[j],j1=j;
     }
     for (int j=0;j<=M;j++)
      if (used[j])
       u[p[j]]+=delta,v[j]-=delta;
      else
       minv[j]-=delta;
      j0=j1;
    }
    while (p[j0]!=0);
    
    do
    {
     long j1=way[j0];
     p[j0]=p[j1];
     j0=j1;
    }while (j0);
}

for (int i=1;i<=M;i++)
 ans[p[i]]=i;

for (int i=1;i<=M;i++)
 ANS-=a[i][ans[i]];

cout<<ANS<<endl;

for (int i=1;i<=M;i++)
{
 int t=ans[i];
 if (t<=26) cout<<char(t+'a'-1);
 else cout<<char(t+'A'-27);
}
cout<<endl;

cin.get();cin.get();
return 0;}