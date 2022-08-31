/*
Grey visions of today
Every sight the same
I can not break free
I think I'm gone
As though I never wake
Always drawn into descent
And my hope decays, just out of reach

Cursed through life & condemned to misery
To be left with nothing...

If only for a moment; a way out
To see the faintest glimmer amongst the dark
To mend the broken dawn so bleak
Somehow I think I'm gone

But like ashes to the wind i will fade
Nameless and Forgotten
The thorn upon the withered rose
Somehow I always knew...
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

long n,m,a[500000],b[500000],c[500000];
vector<long> edges[500000];
long id,temp,rdp[500000],dp[500000];
vector<pair<long, long> > toupd;
long answ;
long v,val;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a[i]>>b[i]>>c[i];
 edges[c[i]].push_back(i);
}

for (int i=100000;i;--i)
{
 for (int j=0;j<edges[i].size();j++)
 {
  id=edges[i][j];
  temp=dp[b[id]]+1;
  if (rdp[a[id]]<temp)
  {
   toupd.push_back(make_pair(a[id],temp));
   rdp[a[id]]=temp;
  }
 }
 for (int j=0;j<toupd.size();j++)
 {
  v=toupd[j].first;
  val=toupd[j].second;
  dp[v]=val;
 }
 toupd.clear();
}

answ=0;
for (int i=1;i<=n;i++)
 answ=max(answ,dp[i]);

cout<<answ<<endl;

cin.get();cin.get();
return 0;}