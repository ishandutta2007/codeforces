/*
I'm lonely and abandoned
Washed up, left for dead
I'm lost inside the desert
Of every word you said

Like a nuclear reactor
Or TNT
I'm thinking about the times
When you lied to me

All the innuendo
Caught up on your hook
I was just a name
In your little black book

Ah, I'll get even with you

I'm bitter and I'm twisted
I haven't slept in days
I'm lonely and I'm angry
I can't make it go away

I'm like a bomb that's ticking
I got voices in my head
I got a doll with needles in
Wishing you were dead

I'll get you back somehow
That's what I'm gonna do
I'll get you back somehow
Your nightmare coming true

Ah, I'll get even with you
Ah, that's what I'm gonna do
Gonna get even with you

You better look behind you
'Cause there I'm gonna be
I'll be standing in the shadows
With who I used to be

He's slightly schizophrenic
Me and me and me and me agree
That you are gonna pay
For what you did to me

Ah, I'll get even with you
Gonna get even with you
Ah, that's what I'm gonna do
I'm gonna do
Ah, I'll get even with you
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long res,fb1,fb2;
long long n,m,k,block;

long long gcd(long long a, long long b)
{
     while (a&&b)a>b?a%=b:b%=a;
     return a+b;
} 

long long dist[1000000];

long long solve(long long a,long long b)
{
 for (int i=0;i<=block;i++)
 dist[i]=10000000;
 dist[a]=0;
 for (int j=a;j>0;--j)
 {
  dist[j-1]=min(dist[j-1],dist[j]+1);
  for (int q=2;q<=k;q++)
  dist[j-j%q]=min(dist[j-j%q],dist[j]+1);
 }
 return dist[b];
}

int main(){
//freopen("galaxy.in","r",stdin);
//freopen("galaxy.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
block=1;

for (long long i=2;i<=k;i++)
{
 long q=gcd(i,block);
 block*=i;block/=q;   
}
//cout<<block<<endl;

fb1=n/block;
fb2=m/block;
if (fb1==fb2)
{
 res=solve(n%block,m%block);
}
else
{
 res=solve(n%block,0);
 res+=solve(block,m%block);
 res+=solve(block,0)*(fb1-fb2-1);   
}
cout<<res<<endl;
cin.get();cin.get();
return 0;}