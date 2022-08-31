/*
As you pray like victims
Sworn to fulfill duality
Victimized by your duty
Your awakening incomplete

Seething, seething
Breathing fear within
Seething, seething
Breathing fear within

Fear will be one
With the unknown
And once awake you will find
You've got it all wrong

Accumulate and find the things you lack
To stimulate the change of track
Fear never binds you and never will
(Accumulate and find the things you lack)
Religion holds you and blinds you still
(To stimulate the change of)

As the sage, a victor
Called to end all duality
Terror turns into beauty
Find awakening incomplete

Seething, seething
Breathing fear within
Seething, seething
Breathing fear within

Fear will be one
With the unknown
And once awake you will find
You've got it all wrong

Accumulate and find the things you lack
To stimulate the change of track
Fear never binds you and never will
(Accumulate and find the things you lack)
Religion holds you and blinds you still
(To stimulate the change of)

You come alive and feel this way
Never will life betray you again
Only have the self to blame
Never will life betray you again

Accumulate and find the things you lack
To stimulate the change of track
Fear never binds you and never will
(Accumulate and find the things you lack)
Religion holds you and blinds you still
(To stimulate the change of track)
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

vector<long> masks[20000];

long n,m,a,b,rest[200][200];
long long y;
vector<pair<long, long> > rules;
vector<pair<long, long> > tt[200];
long long res;

long used[200];
long long dp[1<<18];

long gg(long x)
{
 long r=0;
 for (int i=0;i<n;i++)
 if (x&(1<<i))++r;
 return r;
}

long long gett(vector<long> v)
{
 //cout<<"^^^ "<<v[0]<<endl;
 
 for (int i=0;i<n;i++)
  used[i]=0;
  
 for (int i=0;i<v.size();i++)
  used[v[i]]=1;
 
 for (int i=(1<<v.size());i<(1<<n);i++)
  dp[i]=0;
 
 long temp=(1<<v.size());
 temp-=1;
 dp[temp]=1;
 
 long p;
 long v1;
 
 long bm1[20];
 
 long qq=v.size();
 for (int i=0;i<n;i++)
 {
  if(used[i])continue;
  long bmask=0;
  for (int j=0;j<v.size();j++)
   for (int q=0;q<tt[j].size();q++)
   {
    p=tt[j][q].first;
    v1=v[j];
    if (v1>i&&tt[j][q].second<0)bmask|=(1<<p);
    if (v1<i&&tt[j][q].second>0)bmask|=(1<<p);   
   }
//   bmask=0;
  
   for (int j=0;j<n;j++)
    bm1[j]=0;
  
  for (int j=v.size();j<n;j++)
   for (int q=0;q<tt[j].size();q++)
   {
    p=tt[j][q].first;
    if (tt[j][q].second<0&&p>=v.size())
     bm1[j]|=(1<<p);
   }
   
  for (int ttt=0;ttt<masks[qq].size();ttt++)
  {
   int mask=masks[qq][ttt];
    for (int np=v.size();np<n;np++)
    {
     if(mask&(1<<np))continue; // usd alrdy
     if (bmask&(1<<np))continue;
     if (bm1[np]&(mask))continue;
    long er=0;
   /*  for (int j=0;j<tt[np].size();j++)
     {
      p=tt[np][j].first;
      if ((mask&(1<<p))==0)continue;// free
      if (p<v.size())v1=v[p];
      else v1=-1;
     // v1=-1;
      if (v1>i&&tt[np][j].second>0)er=1;
      if (v1<i&&tt[np][j].second<0)er=1;
      if (er)break;
     }*/
//     cout<<mask<<"   "<<i<<" "<<" "<<np<<"  "<<er<<endl;
     if (er==0) // np
     {
     dp[mask|(1<<np)]+=dp[mask];
//     if (dp[mask|(1<<np)]>2e18)dp[mask|(1<<np)]=2e18;
}
     
    }
   }
   ++qq;
 }
 /*
 for (int i=0;i<(1<<n);i++)
  cout<<i<<"   "<<dp[i]<<endl;
  cout<<"%"<<endl;
  */
 return dp[(1<<n)-1];
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>y>>m;

for (int i=0;i<(1<<n);i++)
{
 long temp=gg(i);
 masks[temp].push_back(i);
}

for (int i=0;i<m;i++)
{
 cin>>a>>b;
 --a;
 --b;
 tt[a].push_back(make_pair(b,-1));
 tt[b].push_back(make_pair(a,1));
}

y-=2001;

vector<long> v;

res=gett(v);


if (res<=y)cout<<"The times have changed"<<endl;
else
{
 for (int iter=0;iter<n;iter++)
 {
     
 for (int i=0;i<n;i++)
 {
  long er=0;
  for (int j=0;j<v.size();j++)
   if (v[j]==i)er=1;
  if (er)continue;// dbld
  
  v.push_back(i);
  if (gett(v)<=y){y-=gett(v);v.pop_back();}// tnxt
 else break;
 }
// cout<<v.size()<<" "<<iter<<" "<<v[v.size()-1]<<" "<<y<<endl;
 
}

for (int i=0;i<v.size();i++)
{
 if (i)cout<<" ";
 cout<<v[i]+1;
}
cout<<endl;

}

cin.get();cin.get();
return 0;}