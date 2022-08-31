/*
Day by day, watching you disappear
Wishing that you were still here beside me
On my own, swimming against the tide
There's nobody on my side but your memory

Then you'll rise right before my eyes
On wings that fill the sky
Like a phoenix rising
Like a phoenix rising

Wings on fire, tearing into the night
Screaming into the light of another day
Carry me out of the hurricane
Into the smoke and flame and we'll fly away

And we'll rise right before their eyes
On wings that fill the sky
Like a phoenix rising
Like a phoenix rising

Higher, higher, hear the thunder roar from above
Fire, fire, fire make me whole

And we'll rise right before their eyes
On wings that fill the sky
Like a phoenix rising
Like a phoenix rising

Wings on fire, tearing into the night
And we'll fly away
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

long lab[200000];
long n,m,h,t,deg[200000];
vector<long> g[200000];
vector<pair<long, long> > tocheck;
long a,b;
long ans;
long gi;
long v1,v2,mark[200000];

bool good(pair<long, long> p)
{
 v1=p.first;
 v2=p.second;
 if (deg[v1]<=h)return false;
 if (deg[v2]<=t)return false;
 if (deg[v1]>=h+t+1||deg[v2]>=h+t+1)return true;
 
 long td=deg[v1]+deg[v2]-2;
 
 for (int i=0;i<g[v1].size();i++)
 {
  long q=g[v1][i];
  mark[q]=gi;
 }
 for (int i=0;i<g[v2].size();i++)
 {
  long q=g[v2][i];
  if (mark[q]==gi)--td;// cmn one
 } 
 return (td>=h+t);
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>h>>t;

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 deg[a]++;
 deg[b]++;
 g[a].push_back(b);
 g[b].push_back(a);
 tocheck.push_back(make_pair(a,b));
 tocheck.push_back(make_pair(b,a));
}

for (int iter=1;iter<=tocheck.size();iter++)
{
 gi=iter;
 if (good(tocheck[iter-1]))ans=iter;
}

if (ans==0)
cout<<"NO"<<endl;
else
{
 vector<long> v1,v2;
 
 cout<<"YES"<<endl;
 cout<<tocheck[ans-1].first<<" "<<tocheck[ans-1].second<<endl;
 for (int i=1;i<=n;i++)
  lab[i]=0;
 long v=tocheck[ans-1].first;
 lab[v]=100;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  lab[q]|=1;
 }
 v=tocheck[ans-1].second;
 lab[v]=100;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  lab[q]|=2;
 }
 
 for (int i=1;i<=n;i++)
 {
  if (lab[i]==1&&h>0)
   {
   v1.push_back(i);
   --h;
   }
 }
 
 for (int i=1;i<=n;i++)
 {
  if (lab[i]==2&&t>0)
   {
   v2.push_back(i);
   --t;
   }
 }
 
 
 for (int i=1;i<=n;i++)
 {
  if (lab[i]!=3)continue;
   if (h>0)
   {
   v1.push_back(i);
   --h;
   }
   else if (t>0)
   {v2.push_back(i);
   --t;}
   
 }
 
 for (int i=0;i<v1.size();i++)
 {
  if (i)cout<<" ";
  cout<<v1[i];
 }
 cout<<endl;
 for (int i=0;i<v2.size();i++)
 {
  if (i)cout<<" ";
  cout<<v2[i];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}