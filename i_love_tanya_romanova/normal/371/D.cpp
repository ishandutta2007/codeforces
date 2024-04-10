/*
As the sun goes down, I move around
Keeping to the shadows
Life, hangs by a thread
And I've heard it said, that I'll not see tomorrow

If that's my destiny, it'll have to be
So I'll face the future
Running out of time
I'm on the line
But I'll go down fighting

Felt the hand of justice
Telling wrong from right
Threw me out upon the street in the middle of the night

Cybernetic heartbeat
Digital precise
Pneumatic fingers nearly had me in their vice

Not begging you
I'm telling you

You won't break me
You won't make me
You won't take me,
Under blood red skies

You won't break me
You won't take me
I'll fight you under
blood red skies

Through a shattered city, watched by laser eyes
Overhead the night squad glides
The decaying paradise

Automatic sniper
With computer sights
Scans the bleak horizon for its victim of the night

They're closing in
They'll never win

You won't break me
You won't take me
You won't make me,
Under blood red skies

You won't break me
You won't take me
I'll fight you under
blood red skies

As the end is drawing near
Standing proud, I won't give in to fear
As I die a legend will be born
I will stand, I will fight
You'll never take me alive
I'll stand my ground
I won't go down

You won't break me
You won't make me
You won't take me,
Under blood red skies

You won't break me
You won't take me
just I'll face you under
blood red skies

You'll never take me alive
I'm telling you
Hands of justice
I will stand, I will fight
Never surrender
As the sun goes down
I won't give in to fear
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
#define eps 1e-4
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000
#define double long double

using namespace std;

long long n,cap[300000],pre[300000],nxt[300000],tests,ins[300000];
long long tp,q,a,b;
long long cput;
set<long long> fre;
set<long long>::iterator it;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>cap[i];
for (int i=1;i<=n+1;i++)
fre.insert(i);

cap[n+1]=1e18;

for (int i=1;i<=n;i++)
{pre[i]=i-1;nxt[i]=i+1;}

cin>>tests;
for (;tests;--tests)
{
 cin>>tp;
 if (tp==2)//gett
 {
  cin>>q;cout<<ins[q]<<endl;
 }   
 else
 {
  cin>>a>>b;
  it=fre.lower_bound(a);
  a=(*it);
  while (b>0)
  {
   cput=min(b,cap[a]-ins[a]);
   b-=cput;
   ins[a]+=cput;
   if (ins[a]==cap[a])
   {
    nxt[pre[a]]=nxt[a];
    pre[nxt[a]]=pre[a];
    fre.erase(a);
    a=nxt[a];
   }
  }
 }
}

cin.get();cin.get();
return 0;}