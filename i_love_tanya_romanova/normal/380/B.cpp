/*
On a cold winter morning, in the time before the light
In flames of death's eternal reign we ride towards the fight
When the darkness has fallen down, and the times are tough all right
The sound of evil laughter falls around the world tonight

Fighting hard, fighting on for the steel, through the wastelands evermore
The scattered souls will feel the hell bodies wasted on the shores
On the blackest plains in hell's domain, we watch them as we go
In fire and pain, and once again we know

So now we fly ever free
We're free before the thunderstorm
On towards the wilderness our quest carries on
Far beyond the sundown, far beyond the moonlight
Deep inside our hearts and all our souls

[Chorus:]
So far away we wait for the day
For the lives all so wasted and gone
We feel the pain of a lifetime lost in a thousand days
Through the fire and the flames we carry on

As the red day is dawning
And the lightning cracks the sky
They'll raise their hands to the heavens above
With resentment in their eyes
Running back from the mid-morning light
There's a burning in my heart
We're banished from a time in a fallen land
To a life beyond the stars

In your darkest dreams see to believe
Our destiny is time
And endlessly we'll all be free tonight

And on the wings of a dream, so far beyond reality
All alone in desperation, now the time has gone
Lost inside you'll never find, lost within my own mind
Day after day this misery must go on

[Chorus]

Now here we stand with their blood on our hands
We fought so hard now can we understand
I'll break the seal of this curse if I possibly can
For freedom of every man

[Chorus]
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long dv[2000000],used[2000000],n,m,
tp,lvl[200000],l[200000],r[200000],val[200000];
long L[200000],R[200000];
long ttl,qlvl,qv,ans;

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=0;i<=20;i++)
{
 dv[1<<i]=1;
}
for (int i=1;i<=1000000;i++)
dv[i]+=dv[i-1];

cin>>n>>m;
for (int i=0;i<=1000000;i++)
used[i]=-1;

for (;m;--m)
{
 cin>>tp;
 if (tp==1)
 {
  cin>>lvl[ttl]>>l[ttl]>>r[ttl]>>val[ttl];
  ++ttl;
  continue;
 }
 cin>>qlvl;
 cin>>qv;
 ans=0;
 L[qlvl]=qv-1;
 R[qlvl]=qv;
 for (int i=qlvl+1;i<=n;i++)
 {
  L[i]=L[i-1]+dv[L[i-1]];
  R[i]=R[i-1]+dv[R[i-1]];
 }
 ans=0;
 for (int i=0;i<ttl;i++)
 {
  if (lvl[i]>=qlvl&&max(L[lvl[i]]+1,l[i])<=min(R[lvl[i]],r[i])&&used[val[i]]!=m)
  {
   used[val[i]]=m;
   ++ans;
  }
 }
 cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}