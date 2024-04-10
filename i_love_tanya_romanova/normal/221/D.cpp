/*
Let it rain a day, a week, a year
Let it rain a thousand years a day
That's the divine answer to all the shed tears
That's the cyclic Flood well known by those who know
One drop for every broken dream
and one for every conceived plan
Our seeds sown larger
Our roots will go deeper
Our trees will grow higher and now we wait the rain
Let cry the skies to cleanse the souls
Let fall the seas to wash the pain away
That's the final run to the New Age
That's the first step beyond the threshold of this world
One drop for every broken dream
and one for every conceived plan
Our seeds sown larger
Our roots will go deeper
Our trees will grow higher and now we call the rain
Here rings a warning
A day of wrath for all the days of war
A storm of fury
to calm the hunger left
Our seeds sown larger
Our roots will go deeper
Our trees will grow higher and now we bring the rain
Our seeds - larger
Our roots - deeper
Our trees - higher and we - stronger
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

long n,tests,ar[200000];
long calc[200000];
vector<long> t,vec[200000];
long l,r,ans;
long mapp[200000];
long c[105000][520];
long td;
bool nice[200000];

long gett(long x,long p)
{
 return c[p][mapp[x]];
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>tests;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 if (ar[i]<=100000)
  calc[ar[i]]++;
}

for (int i=1;i<=n;i++)
if (calc[i]>=i)
{
 t.push_back(i);
 nice[i]=1;
 mapp[i]=td;
 ++td;
}

for (int i=1;i<=n;i++)
{
    for (int j=0;j<t.size();j++)
     c[i][j]=c[i-1][j];
    if (ar[i]<=100000&&nice[ar[i]]==1)
     c[i][mapp[ar[i]]]++;
}

for (;tests;--tests)
{
 cin>>l>>r;
 ans=0;
 for (int i=0;i<t.size();i++)
 {long v=gett(t[i],r);
  if (v<t[i])continue;
  v-=gett(t[i],l-1);
  if (v==t[i])++ans;}
 cout<<ans<<"\n";
}

cin.get();cin.get();
return 0;}