/*
I'm tired of always doing as I'm told
Your shit is starting to grow really old
I'm sick of dealing with all you crap
You pushed me too hard now you'll watch me snap

Whack, whack, what's wrong with your head?
I can't believe a fuckin' word you've said
Whack, whack, what, are you dead?
Permanently done, gone to bed

Whack, whack, out of you mind
I think you'll like it if you try it some time
Whack, whack, if you look you'll find
I'm whacked, I'm whacked, I'm whacked, get whacked
I'm whacked, you're whacked let's go it's whack time

Get whacked-gimme gimme gimme gimme gimme
Some whack time
Get whacked, all I need, I need, I need, I need is some whack time
Get whacked, oh no no get whacked

Ain't nobody gonna tell me what to do
I'm gonna save my best whack for you
Bust out hard in a brand new way
Now every second is a psycho day

I'm whacked and I don't care no more
I'm whacked, right down to the core
I'm whacked like never before
I'm whacked, I'm whacked, I'm whacked, I'm whacked

Get whacked, won't you follow me?
Get whacked,what fun it'll be
Get whacked and do it naturally
Get whacked, get whacked, get whacked, get whacked
It's whack time!

Whack time get whacked
Whack time get whacked, get whacked, get whacked
Whack time, get whacked, get whacked, get whacked
Whack time, get whacked I'm whacked, you're whacked
Let's go it's whack time

Get whacked, gimme, gimme, gimme, gimme
Gimme some whack time
Get whacked all I need, I need, I need, I need is some
Whack time, get whacked no no no get whacked

You don't want none you got the right
When I get whacked it's not a pretty sight
One-quarter Scottish, three-quarters insane
I think I've gone a little flat in the brain

Whack, whack, what you got in your head
Another word, another lie that you've said
Whack, whack, your mind is dead
Permanently done, gone to bed

Whack whack, what do you know?
This ain't no script, this ain't no picture show
Whack, whack, up away you go, oh no no no
Get whacked!

It's whack time, get whacked

Won't see me later you'll see me right now
If you think I'm crazy I'll show you just how
I know what's scaring you the most about me
This mo-fo be getting whacked naturally
Get whacked
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long n,k;
string st;
vector<pair<long, long> > v[1<<20];
long q;
vector<pair<long, long> > block;
long l1;
vector<long> tv;
long er;
long ans[1<<20];

vector<long> solve(vector<pair<long, long> > v,long lwr,long upr)
{
// cout<<lwr<<"  "<<upr<<" "<<v.size()<<endl;
/* for (int i=0;i<v.size();i++)
  cout<<v[i].second<<" ";
 cout<<endl;
 */
 long sz=v.size();
 if (lwr+sz>=upr)
  er=1;
  
 vector<long> res;
 res.resize(v.size());
 
 if (er)return res;
 if (upr<=sz-1-sz/2)
 {
  for (int i=0;i<v.size();i++)
   res[i]=upr-sz+i;
  return res;
 }
 if (lwr>=-(sz/2))
 {
  for (int i=0;i<v.size();i++)
  {
   res[i]=lwr+i+1;
  }
  return res;
 }
 for (int i=0;i<v.size();i++)
 res[i]=i-sz/2;
 return res;
}

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 cin>>st;
 if (st=="?") 
 {
  v[i%k].push_back(make_pair(i,-2000000000));
 } 
 else
 {
  stringstream s(st);
  s>>q;
  v[i%k].push_back(make_pair(i,q));
 }
}

for (int i=0;i<k;i++)
{
    block.clear();
    l1=-1100000001;
    for (int j=0;j<v[i].size();j++)
    {
//     cout<<i<<"  "<<j<<"   "<<er<<endl;
     if (v[i][j].second>-1.5e9)
     {
      if (block.size())
      {
      tv=solve(block,l1,v[i][j].second);
    /*  for (int j=0;j<tv.size();j++)
       cout<<tv[j]<<" ^ ";
      cout<<endl;
     */
      for (int q=0;q<tv.size();q++)
       v[i][j-tv.size()+q].second=tv[q];
      }
    //  cout<<i<<"  "<<j<<" "<<er<<endl;
      
      block.clear();
      if (j>0&&v[i][j].second<=v[i][j-1].second)er=1;
      l1=v[i][j].second;
     }
     else
     {
      block.push_back(v[i][j]);
     }
    }
   if (block.size())
   {
    tv=solve(block,l1,1100000001);
  /*  for (int j=0;j<tv.size();j++)
     cout<<tv[j]<<" ^";
     cout<<endl;
    */ 
    for (int j=0;j<tv.size();j++)
     v[i][v[i].size()-tv.size()+j].second=tv[j];
   }
}

if (er)
cout<<"Incorrect sequence"<<endl;
else
{
    for (int i=0;i<k;i++)
     for (int j=0;j<v[i].size();j++)
      ans[v[i][j].first]=v[i][j].second;
     for (int i=1;i<=n;i++)
     {
         if (i>1)cout<<" ";
         cout<<ans[i];
     }
     cout<<endl;
}

cin.get();cin.get();
return 0;}