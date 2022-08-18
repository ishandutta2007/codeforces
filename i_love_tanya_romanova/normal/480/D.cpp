/*
Cries in the night
Wounds of the soul burning times
Like every time
Your mind refuses
Not able to choose it
Don't give up, don't give up
You've got to fight!

Your heart is tainted
Your job is to make it through this agonizing night!

In ancient melody
Hidden key to your memory
Your heart defrosting
In every note playing
You've got to start claiming
It's your will, it's your life
You've got to fight!

Your heart is tainted
Your job is to make it through this agonizing night!

You'll have to decide
And make up your mind
You know it is time for you
To stand up on your own two feet
And dare to dream.

Your heart is tainted
Your job is to make it through this agonizing night!
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
#define free adsgasdg

using namespace std;

long n,S,in[1<<15],out[1<<15],w[1<<15],s[1<<15],v[1<<15];
vector<long> topsort;
long id,ins[1<<15];
long wl,ps,dp[1<<12][1<<11];

bool cmp(long a,long b)
{
 if (out[a]!=out[b])
  return (out[a]<out[b]); // inside | ipdep
 return in[a]>in[b];// inside
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>S;
for (int i=1;i<=n;i++)
 cin>>in[i]>>out[i]>>w[i]>>s[i]>>v[i];

in[0]=0;
out[0]=1001;
s[0]=S;

for (int i=0;i<=n;i++)
 topsort.push_back(i);

sort(topsort.begin(),topsort.end(),cmp);

/*for (int i=0;i<topsort.size();i++)
 cout<<topsort[i]<<" ";
 cout<<endl;
 */
for (int i=0;i<=n;i++)
{
 id=topsort[i];
 for (int pw=w[id];pw<=S;pw++)
 {
  for (int j=0;j<=1001;j++)
   ins[j]=0;
  wl=pw-w[id];
  if (wl>s[id])wl=s[id];// bneck
  ps=in[id];
  for (int j=0;j<i;j++)
  {
      if (in[topsort[j]]<in[id])continue;// to the left
      while (ps<=in[topsort[j]])
      {
       if (ps>0)ins[ps]=max(ins[ps-1],ins[ps]);
       ++ps;
      }
      ins[out[topsort[j]]]=max(ins[out[topsort[j]]],ins[in[topsort[j]]]+dp[j][wl]);//take this box, rec dp
  }
  for (int j=in[id];j<=out[id];j++)
   dp[i][pw]=max(dp[i][pw],ins[j]+v[id]);
//  cout<<i<<" "<<pw<<"  "<<dp[i][pw]<<endl;
 }
}

cout<<dp[n][S]<<endl;

cin.get();cin.get();
return 0;}