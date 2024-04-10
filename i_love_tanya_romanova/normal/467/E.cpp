/*
I never thought the taste of you
Would be the only thing to make me bleed
Why am I so alive while you lay still in the ground beneath me?

Fear of death, the dark inside have become your only children
Now they're in front of you, watching you
Lost screams, unholy dreams unrest
I laugh at your God as he's passing through

Slicing out your throat to warm my skin
Never thought it'd come to this
What the fuck I've gone wrong, no rest

Your children still call
Can't you hear them screaming out your name?
You've gone insane, they're in my head

They want you to die in front of me, die in front of me
Thinking why me, wishing this was all a dream
Insanity, reality, you're going to die in front of me

Pestilence is here, death awaits
Your body's not of Christ, it's my altar
Helpless and alone, violate
Enveloped in my sin, faceless canvas

Tearing at your flesh, bathed in blood
Violently regress, death's so endless
Brutal is the pain, anguish is the game
Broken and afraid, God can't help you now

You wish you were in hell
You wish you were in hell
You wish you were in hell

Ghostly figures are always standing still
Are they mocking me? What do they see?
I didn't want your death to end so fast
But once you start you cannot stop
I need it now to fucking last

Die in front of me, die in front of me
Thinking why me, wishing this was all a dream
Insanity, reality, you're going to die in front of me

Pestilence is here, death awaits
Your body's not of Christ, it's my altar
Brutal is the pain, anguish is the game
Broken and afraid, God can't help you now

You wish you were in hell
You wish you were in hell
You wish you were in hell
You wish you were in hell

I never thought the taste of you
Would be the only thing to make me bleed
All alone in my funeral home
Playing in blood there's just got to be
Something wrong with me

Draining veins, it's all the same
The torture in my head it won't stop
Until I am fucking dead

Pestilence is here, death awaits
Your body's not of Christ, it's my altar
Helpless and alone, violate
Enveloped in my sin, faceless canvas

Tearing at your flesh bathed in blood
Violently regress, death's so endless
Brutal is the pain, anguish is the game
Broken and afraid, God can't help you now

You wish you were in hell
You wish you were in hell
You wish you were in hell
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

#define eps 1e-10
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n,ar[1<<20];
vector<long> v;
map<long, long> mapp,rmapp;
long calc;
pair<long, pair<long, long> > bst;
vector<pair<pair<long, long> ,pair<long ,long> > > evs;
vector<long> vec[1<<20];
long rp;
long t[1<<22];
long temp;
long lst[1<<20];
long nxt[1<<20];
long prev[1<<20];
long r;
vector<long> ans;

void add(pair<pair<long,long> ,pair<long, long> > p1)
{
 ans.push_back(rmapp[ar[p1.first.first]]);
 ans.push_back(rmapp[ar[p1.first.second]]);
 ans.push_back(rmapp[ar[p1.second.first]]);
 ans.push_back(rmapp[ar[p1.second.second]]);
 
}

bool cmp(pair<pair<long, long> ,pair<long, long> > p1,pair<pair<long, long> ,pair<long, long> > p2)
{
 return p1.second.second<p2.second.second;
}

void build(long v,long tl,long tr)
{
 if (tl==tr)
 {
  t[v]=-1e9;
  return;
 }
 long tm=tl+tr;
 tm/=2;
 build(v*2,tl,tm);
 build(v*2+1,tm+1,tr);
}

long get(long v,long tl,long tr,long l,long r)
{
 if (l>r)return -1e9;
 if (l==tl&&r==tr)
 {
  return t[v];
 }
 long tm=tl+tr;
 tm/=2;
 return max(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

void update(long v,long tl,long tr,long ps,long val)
{
 if (tl==tr)
 {
  t[v]=val;return;
 }
 long tm=tl+tr;
 tm/=2;
 if (ps<=tm)update(v*2,tl,tm,ps,val);
 else update(v*2+1,tm+1,tr,ps,val);
 t[v]=max(t[v*2],t[v*2+1]);
}

void dodel(long x)
{
 long val=ar[x];
 for (int i=0;i<vec[val].size();i++)
  if (vec[val][i]==x)
  {
   vec[val].erase(vec[val].begin()+i);
   break;
  }
 update(1,1,n,x,-1);
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 v.push_back(ar[i]);
}

sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
    if (i==0||v[i]!=v[i-1])
    {
     mapp[v[i]]=calc+1;
     ++calc;
     rmapp[calc]=v[i];
    }
}

build(1,1,n);

long ls=0;

for (int i=1;i<=n;i++)
 ar[i]=mapp[ar[i]];

for (int i=1;i<=n;i++)
{
 if (lst[ar[i]]){prev[i]=lst[ar[i]];nxt[prev[i]]=i;}
 lst[ar[i]]=i;
}
/*
for (int i=1;i<=n;i++)
 cout<<prev[i]<<" ";
 cout<<endl;
for (int i=1;i<=n;i++)
 cout<<nxt[i]<<" ";
 cout<<endl;
 */
for (int i=1;i<=n;i++)
{ 
 long t=ar[i];
 vec[t].push_back(i);
 if (vec[t].size()==4)
 {
  add(make_pair(make_pair(vec[t][0],vec[t][1]),make_pair(vec[t][2],vec[t][3])));
  for (int j=0;j<vec[t].size();j++)
  {
   long id=vec[t][j];
   update(1,1,n,id,-1);
  }
  
  for (int j=ls+1;j<=i;j++)
    dodel(j);
   ls=i;
  continue;
 }
 for (int j=0;j+1<vec[t].size();j++)
 {
  long id=vec[t][j];
  temp=get(1,1,n,1,id-1);
  if (temp>id)// found
  {
   long bb=-1;
//   cout<<id<<"%"<<endl;
   for (int q=0;q<vec[ar[temp]].size();q++)
    if (vec[ar[temp]][q]<id)bb=vec[ar[temp]][q];
//    cout<<"^"<<bb<<endl;
   add(make_pair(make_pair(bb,id),make_pair(temp,i)));
/*   dodel(bb);
   dodel(temp);
   dodel(id);
   dodel(i);
  */
  for (int j=ls+1;j<=i;j++)
    dodel(j);
   ls=i;
   break;
  }
 }
 for (int j=0;j<vec[t].size();j++)
  update(1,1,n,vec[t][j],i);
}

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
 if (i)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}