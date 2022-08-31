/*
I went outside
To take a walk
So I could relive memories
I thought that you would lend a hand

But you were never ever there
It's all in your mind
You do what you want to do
Your promises are all played out

You've got your wish
You've worn me down
I've treated you the best I could
I realize that I don't need you

I lost my way
When you left home
I thought that you could change your life
What did I do

Why do you lie
You've walked back in
My hands are tied
It's all in your mind

You do what you want to do
Your promises are all played out
You've got your wish
You've worn me down

I've treated you the best I could
I realize that I don't need you
It's all in your mind
You do what you want to me

It's all in your mind
You do what you want, to me
I'm tired
I'm so damn angry with you

You're not gonna change
I see who you really are
Your promises are all played out
You've got your wish

You've worn me down
I've treated you the best I could
I realize that I don't need you
Your promises

Your promises
Your promises
They're all played out
You're so played out

You're so played out
You're so played out
They're all played out
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

long tests,m;
string tp;
vector<pair<long, long> > vec;
set<pair<long, long> > ::iterator it;
set<pair<long, long> > hv;
long s,need,fen;
long sz[200000];
long total;
long mem[200000];
long has[200000];

void place(long id,long ps)
{
 hv.insert(make_pair(ps,id));
 for (int i=ps;i<ps+sz[id];i++)
  mem[i]=1;
 has[id]=ps;
}

bool cput(long start,long total)
{
 if (start+total>m+1)return false;
 for (int i=start;i<start+total;i++)
  if (mem[i])return false;
  return true;
}

void create(long s)
{
 ++total;
 sz[total]=s;
 has[total]=1;
}

void del(long id)
{
 for (int i=has[id];i<has[id]+sz[id];i++)
  mem[i]=0;
 hv.erase(make_pair(has[id],id));
 has[id]=0;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests>>m;
for (;tests;--tests)
{
 cin>>tp;
 if (tp=="defragment")
 {
  vec.clear();
  for (it=hv.begin();it!=hv.end();it++)
  {
  pair<long, long> tp=(*it);
   vec.push_back(tp);
  }
  for (int i=1;i<=m;i++)
   mem[i]=0;
   
  s=0;
  hv.clear();
  for (int i=0;i<vec.size();i++)
  {
   place(vec[i].second,s+1);
   s+=sz[vec[i].second];
   
  }
 }
 else if (tp=="alloc")
 {
  cin>>need;
  fen=1e9;
  for (long i=1;i<=m;i++)
   if (cput(i,need))fen=min(fen,i);
  if (fen>m)
  {
   cout<<"NULL"<<endl;
  }
  else
  {
   create(need);
   place(total,fen);
   cout<<total<<endl;
  }
 }
 else
 {
 cin>>need;
 if (need>total||need<1||has[need]==0)
 cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
 else
 {
  del(need);
 }
 }
/* for (int i=1;i<=m;i++)
  cout<<mem[i]<<" ";
  cout<<endl;*/
}

cin.get();cin.get();
return 0;}