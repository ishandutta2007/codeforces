/*
Here I lay, still and breathless
Just like always, still I want some more
Mirrors sideways, who cares what's behind
Just like always, still your passenger

Chrome buttons, buckles an' leather surfaces
These and other lucky witnesses
Now to calm me, this time won't you please
Drive faster

Roll the windows down, this
Cool night air is curious
Let the whole world look in,
Who cares who sees anything
I'm your passenger
I'm your passenger

Drop these down and put them on me
Nice cool seats there to cushion your knees
Now to calm me take me 'round again
Don't pull over this time won't you please
Drive faster

Roll the windows till this
Cool night air is curious
Let the whole world look in
Who cares who sees what tonight

Roll these misty windows
Down to catch my breath and then
Go and go and don't just
Drive me home and back again

Here I lay, just like always
Don't let me go go go go go go go go go
Take me to the edge
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

long pr[2000];
vector<long> v;
long dp[105][1<<17];
long par[105][1<<17];
long tm[200];
long n,ar[200];
long tval,bst,bp;
vector<long> av;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pr[1]=1;
for(int i=2;i<=60;i++)
if (pr[i]==0)
 for (int j=i*2;j<=60;j+=i)
  pr[j]=1;

for (int i=2;i<=60;i++)
 if (pr[i]==0)
  v.push_back(i);
//cout<<v.size()<<endl;

for (int i=1;i<=60;i++)
{
 for (int j=0;j<v.size();j++)
  if (i%v[j]==0)
   tm[i]|=(1<<j);
}

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>ar[i];
}

for (int i=0;i<=n;i++)
{
 for (int mask=0;mask<(1<<v.size());mask++)
  dp[i][mask]=1e9;
}

dp[0][0]=0;
for (int i=0;i<n;i++)
 for (int mask=0;mask<(1<<v.size());mask++)
  for (int ad=1;ad<=60;ad++)
  {
   if (mask&tm[ad])continue;// gcd
   tval=dp[i][mask]+abs(ad-ar[i]);
   if (dp[i+1][mask|tm[ad]]>tval)// upd
   {
    dp[i+1][mask|tm[ad]]=tval;
    par[i+1][mask|tm[ad]]=ad;
   }
  }

bst=1e9;
bp=0;
for (int i=0;i<(1<<17);i++)
{
 if (dp[n][i]<bst)
 {
  bst=dp[n][i];
  bp=i;
 }
} 

for (int i=n;i;--i)
{
 av.push_back(par[i][bp]);
 bp^=(tm[par[i][bp]]);
}

reverse(av.begin(),av.end());
for (int i=0;i<av.size();i++)
{
 if (i)cout<<" ";
 cout<<av[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}