/*
It's the same in every country
When you say you're leaving
Left behind the loved ones
Waiting silent in the hall
Where you're going lies adventure
others only dream of
Red and green light this is real
and so you go to war

For the passion, for the glory
For the memories, for the money
You're a soldier, for your country
What's the difference, all the same

Far away from the land of our birth
We fly a flag in some foreign earth
We sailed away like our fathers before
These colours don't run, from a cold bloody war

Here is no one that will save you
Going down in flames
No surrender certain death
You look it in the eye
On the shores of tyranny you

Crashed the human wave
Paying for my freedom with your
Lonely unmarked graves

For the passion, for the glory
For the memories, for the money
You're a soldier, for your country
What's the difference, all the same

Far away from the land of our birth
We fly a flag in some foreign earth
We sailed away like our fathers before
These colours don't run, from a cold bloody war
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,d,sz[30];
long temp;
set<long> sett[30];
set<long>::iterator it;
long bst[1200000];
long val[1200000];
long ans;
long tmask;
long r;
long last[1000];
long bad[1200000];
long calc[1200000];

long gb(long x)
{r=0;
for (int i=0;i<m;i++)
if (x&(1<<i))++r;
return r;}

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>d;
for (int i=0;i<m;i++)
{
    cin>>sz[i];
    for (int j=1;j<=sz[i];j++)
    {
     cin>>temp;
     val[temp]=i;
    }
}

for (int i=0;i<m;i++)
last[i]=0;

for (int i=1;i<=n;i++)
{
    last[val[i]]=i;
    if (i>=d)
    {
     long mask=0;
     for (int j=0;j<m;j++)
     if (i-last[j]>=d)
      mask|=(1<<j);
    bad[mask]=1;
    }
}
/*
for (int i=0;i<(1<<m);i++)
cout<<i<<" "<<bad[i]<<endl;
*/
ans=10050051;


for (int mask=(1<<m)-1;mask+1;--mask)
{
//    cout<<mask<<" "<<bad[mask]<<endl;
//    calc[mask]=calc[mask>>1]+(mask&1);
    if (bad[mask])
    {for (int j=0;j<m;j++)
    if (mask&(1<<j))bad[mask^(1<<j)]=1;
    }else ans=min(ans,gb(mask));
}

cout<<ans<<endl;
cin.get();cin.get();
return 0;}