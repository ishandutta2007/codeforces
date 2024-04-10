/*
Holding the candle in my arms
I'm kneeling down to the altar
Waiting the call from my master
Soon will weight my soul

In the final scale I see my remains
Red dying flower the pan falls down
I see Anubis, ancient judge of fathers
Won't take my rose - falling away
Into hades

I have atomed
Now I'm waiting
Waiting the call
Chance to reborn

Crawling on the ground darkness around
Searching for the light that guides me home
Into my cosmic face never shines the day
Cannot reach out - prisoner of gods
In hades

Turn into blood
Rage of sin
Turn into blood
This is hades
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

using namespace std;

map<string, long> sttoid;
map<long ,string> idtost;
long a,b;
long n,k,bst,temp;
string st1,st2;
long bad[20][20];
long er;
vector<string> av;

long gett(long x)
{
 long s=0;
 for (int i=0;i<=n;i++)
  if (x&(1<<i))++s;
 return s;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=0;i<n;i++)
{
 cin>>idtost[i];
 sttoid[idtost[i]]=i;
}

for (;k;--k)
{
 cin>>st1>>st2;
 a=sttoid[st1];
 b=sttoid[st2];
 bad[a][b]=bad[b][a]=1;
}

bst=0;
for (int mask=0;mask<(1<<n);mask++)
{
 er=0;
 for (int i=0;i<n;i++)
  for (int j=0;j<n;j++)
   if (bad[i][j])
    if (mask&(1<<i))
     if (mask&(1<<j))
      er=1;
 if (er)continue;
 temp=gett(mask);
 if (temp>gett(bst))
  bst=mask;
}

cout<<gett(bst)<<endl;
for (int i=0;i<n;i++)
 if (bst&(1<<i))av.push_back(idtost[i]);

sort(av.begin(),av.end());
for (int i=0;i<av.size();i++)
{
 cout<<av[i]<<endl;
}
cout<<endl;

cin.get();cin.get();
return 0;}