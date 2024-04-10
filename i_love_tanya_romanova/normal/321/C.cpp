/*
Change over the suit of flesh.
Can't touch my mind with all their poisons.
Take over the white padded space.
Imprisoned spirit stays in full motion.

Hurry not endless time.

Convulsions, my bones crack.
Cannot break, will not bend.
Convulsions, fade to black.
Orgastic 'til the end.

Stay over here with me.
Some day I'll walk out the wearing your face.

Worry not, patience be.

Convulsions, my bones crack.
Cannot break, will not bend.
Convulsions, fade to black.
Orgastic 'til the end.
Convulsions, migraine head.
Insides are twisting free.
Convulsions, soiled my bed.
The devil is still in me.
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

long n,a,b;
vector<long> g[200000];
long subsize[200000],ans[200000];

long gsize(long v,long par)
{
 subsize[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (ans[q])continue;
  if (q==par)continue;
  subsize[v]+=gsize(q,v);
 }
 return subsize[v];
}

pair<long, long> gheavy(long v,long par)
{
 pair<long, long> bst=make_pair(-1,-1);
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (ans[q])continue;
  if (subsize[q]>bst.second&&q!=par){bst=make_pair(q,subsize[q]);}
 }
 return bst;
}

void solve(long v,long dep)
{
 //cout<<v<<"  "<<dep<<endl;
 
 long lii=gsize(v,-1);
 lii=lii/2+1;
 pair<long, long> tp=gheavy(v,-1);

 while (tp.second>lii)// dwn in heavy sb3
 {
  long v1=v;
  v=tp.first;
  tp=gheavy(v,v1);
 }
 
  ans[v]=dep;
  for (int i=0;i<g[v].size();i++)
  {
   long q=g[v][i];
   if (ans[q]==0)solve(q,dep+1);
  }
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<n;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

solve(1,1);
for (int i=1;i<=n;i++)
{
 if (i>1)cout<<" ";
 cout<<char(ans[i]+'A'-1);
}
cout<<endl;

cin.get();cin.get();
return 0;}