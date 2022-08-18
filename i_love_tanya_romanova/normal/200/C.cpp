/*
The more I dare
The less do I care
My mind is thirsting for more
The time is right
The day turns to night
Awakening of the dawn

Join eternity
Struggle to be free
(when will you ever see)
You can choose what to be
Create infinity

So enter to our spheres
The darkest voids
The Serpents kiss
The great expansion
Of your mind
The Dragon's calling
Awaiting the
Dominion

Admire the fire
Of burning desire
And see the gateway to gain
The key of will
The keyhole to fill
Prepare to rise above

Join eternity
Struggle to be free
(when will you ever see)
You can choose what to be
Create infinity

Join with the fallen ones
Open your eyes and see
There is no pain to fear
Your strength will carry you
And when the sky turns black
Gaze through eternity
To stars so far away
But trust me, they can be reached
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st1[100],st2[100],st3[100];
vector<string> names;
long calc;
map<string, long> mapp;
map<long, string> rmap;
long a,b;
vector<long> tv;
long goals[100],igoals[100],points[100];
long plays[100];
long ans1,ans2,x;
long tgoals[100],tigoals[100],tpoints[100];
vector<pair<pair<long, long> ,pair<long, string> > > tvv;
vector<long> parse(string st)
{
 st+=":";
 long r=0;
 vector<long> rs;
 for (int i=0;i<st.size();i++)
 {if (st[i]==':'){rs.push_back(r);r=0;}
 else r=r*10+st[i]-48;}
 return rs;            
}

int main(){
//freopen("keeper.in","r",stdin);
//freopen("keeper.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=5;i++)
{
 cin>>st1[i]>>st2[i]>>st3[i];
 names.push_back(st1[i]);
 names.push_back(st2[i]);
}
sort(names.begin(),names.end());

for (int i=0;i<names.size();i++)
 if (i==0||names[i]!=names[i-1])
 {
  mapp[names[i]]=calc+1;++calc;
  rmap[calc]=names[i];
 }

for (int i=1;i<=5;i++)
{
 a=mapp[st1[i]];
 b=mapp[st2[i]];
 tv=parse(st3[i]);
 goals[a]+=tv[0];
 goals[b]+=tv[1];
 igoals[a]+=tv[1];
 igoals[b]+=tv[0];
 
 if (tv[0]>tv[1])points[a]+=3;
 else if (tv[0]<tv[1])points[b]+=3;
 else {points[a]++;points[b]++;}
 plays[a]++;
 plays[b]++;
}

a=mapp["BERLAND"];
for (int i=1;i<=4;i++)
{
 if (rmap[i]!="BERLAND"&&plays[i]==2)b=i;
}

//for (int i=1;i<=4;i++)
//cout<<points[i]<<" "<<goals[i]<<" "<<igoals[i]<<endl;

ans1=ans2=-1;

for (int dif=1;dif<=100;dif++) 
 for (int y=0;y<=100;y++)
 {
   x=y+dif;
   for (int i=1;i<=4;i++)
   tgoals[i]=goals[i];
   for (int i=1;i<=4;i++)
   tpoints[i]=points[i];
   for (int i=1;i<=4;i++)
   tigoals[i]=igoals[i];
   
   tgoals[a]+=x;
   tgoals[b]+=y;
   tigoals[b]+=x;
   tigoals[a]+=y;
   tpoints[a]+=3;
   
   tvv.clear();  
   for (int i=1;i<=4;i++)
   {
       tvv.push_back(make_pair(make_pair(-tpoints[i],-tgoals[i]+tigoals[i]),
       make_pair(-tgoals[i],rmap[i])));
   }
   sort(tvv.begin(),tvv.end());
   
   if (tvv[0].second.second=="BERLAND"||tvv[1].second.second=="BERLAND")
   {
    if (ans1+ans2<0){ans1=x;ans2=y;}
   }
    
 }
  if (ans1<0){cout<<"IMPOSSIBLE"<<endl;}
  else
  cout<<ans1<<":"<<ans2<<endl;
  
cin.get();cin.get();
return 0;}