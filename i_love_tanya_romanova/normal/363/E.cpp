/*
Sometimes I know
I feel untouchable
Drowning in life
Caught up in the accessible
Back down the ground
I hear the sound
there's no escape
The concrete cloud
Spilling on me
Drenching me with
Laymen's sins
I hear the sirens
From the back of me
I'm crashing face first
Into the glass eye

Clash with reality
It rears it's ugly head
Clash with reality
The indescribable
Let the dogs lie
Where we sleep
Irrelevant theme

A situation and there's
Nothing but right
In kicks the door
Nobody moves
'Cause in walks the problem
Dictates your fate
Evicts, convicts
Who'll sign the writ of life?
This now becomes
Their morbid game
Who's piss poor excuse
Is this for a world?
It swells my hatred
Day by day

Clash with reality
It rears it's ugly head
Clash with reality
The indescribable
Let the dogs lie
Where we sleep
Irrelevant theme
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,r,ar[666][666];
long lim[666];
long rem;
long s[666][666];
long lj,rj,circ[777][777];
long bpref[666][666],bsuf[666][666],
cpref[666][666],csuf[666][666];
long bd[666];
long bdj;
long span;
long anss,bcalc,bs;
long tj1,tj2,s1,s2,calc1,calc2;
long long anscalc;

int main(){
//freopen("gnu.in","r",stdin);
//freopen("gnu.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>r;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {cin>>ar[i][j];s[i][j]=s[i][j-1]+ar[i][j];}

for (int dx=0;dx<=r;dx++)
{
    rem=r*r-dx*dx;
    lim[dx]=sqrt(rem+0.5);
}

for (int i=r+1;i+r<=n;i++)
 for (int j=r+1;j+r<=m;j++)
 {
     for (int q=i-r;q<=i+r;q++)
     {
         lj=j-lim[abs(i-q)];
         rj=j+lim[abs(i-q)];
         circ[i][j]+=s[q][rj]-s[q][lj-1];
     }
 }

// left crc
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    if (circ[i][j]>bpref[i][j-1])
    {
     bpref[i][j]=circ[i][j];
     cpref[i][j]=(circ[i][j]>0?1:0);
    }
    else if (circ[i][j]==bpref[i][j-1])
    {
     bpref[i][j]=circ[i][j];
     cpref[i][j]=(cpref[i][j-1]+1)*(circ[i][j]>0);
    }
    else 
    {
     bpref[i][j]=bpref[i][j-1];
     cpref[i][j]=cpref[i][j-1];
    }
} 

// rht crc
for (int i=1;i<=n;i++)
for (int j=m;j;j--)
{
    if (circ[i][j]>bsuf[i][j+1])
    {
     bsuf[i][j]=circ[i][j];
     csuf[i][j]=(circ[i][j]>0?1:0);
    }
    else if (circ[i][j]==bsuf[i][j+1])
    {
     bsuf[i][j]=circ[i][j];
     csuf[i][j]=(csuf[i][j+1]+1)*(circ[i][j]>0);
    }
    else 
    {
     bsuf[i][j]=bsuf[i][j+1];
     csuf[i][j]=csuf[i][j+1];
    }
} 

for (int di=0;di<=500;di++)
{
 bdj=0;
 for (int j=0;j<=r;j++)
 {
  if (di-j>r)continue;
  span=lim[j]+lim[di-j]+1;
  bdj=max(bdj,span);
 }   
 bd[di]=bdj;
}

anss=0;
anscalc=0;

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 if (circ[i][j])
 {
  bs=0;
  bcalc=0;
  
  for (int q=1;q<=n;q++)
  {
   tj1=j-bd[abs(i-q)];
   tj2=j+bd[abs(i-q)];
   
   if (tj1==tj2)--tj1;
   if (tj1<0)tj1=0;
   if (tj2>m)tj2=m+1;
   
   s1=bpref[q][tj1];
   s2=bsuf[q][tj2];
   calc1=cpref[q][tj1];
   calc2=csuf[q][tj2];
   if (s1>s2)calc2=0;
   else if (s1<s2)calc1=0;
   s1=max(s1,s2);
   calc1+=calc2;
   if (bs<s1)bcalc=0;
   else if (bs>s1)calc1=0;
   bs=max(bs,s1);
   bcalc+=calc1;
  // cout<<i<<" "<<j<<" "<<q<<" %%"<<" "<<tj1<<" "<<tj2<<endl;
  }
  bs+=circ[i][j];
  if (bs>anss){anscalc=0;}
  if (bs<anss)bcalc=0;
  anss=max(anss,bs);
  anscalc+=bcalc;
//  cout<<i<<" "<<j<<" "<<anscalc<<endl;
 }

if (anscalc==0)anss=0;

cout<<anss<<" "<<anscalc/2<<endl;

cin.get();cin.get();
return 0;}