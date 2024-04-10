/*
Trying to conceal his murders the
Maniac
Stabs the heart
Stops the flow
Cleaning up the blood's a problem he
Now solves
Hooks through heels
Hung and bled

Corpses are suspended by their feet
Swaying dripping bloody piece of meat
Fastened to the ceiling leaking gore
Splashing down to the floor

Congealing fluids fester the stench
Revolting septic gruel
Putrid slop
Licks the surface of his dungeon
A gruesome meal
Rancid feast live on death

Corpses dangle lifeless gray and cold
Rotting flesh the meat hooks lose their
Hold
Stenching body falls onto the ground
Bones and flesh form a mound

Sanguinary killer will not stop
Hanging dead replacing those that drop
Blood he drinks like wine their flesh
His bread in his maw dripping red
Hung and bled

Oozing blood the butcher's victims
Soak the concrete
Putrefy
Halls of dread
Draped with death
Ornate crimes
Stalactites made of flesh
Festooned with innards
Gaining life
Sentient place, the stone walls
Breathe
Hungry soul
It can think
A genuine living hell
Created by
The butcher he lost control
Owner and property change their roles
Constantly feeding the gluttonous room
He once ruled the chamber
Now it's his tomb

Hung by their feet
Drained of blood
Swallowed by death
Greed of this place
Bodies
Decay, devoured by evil
Slave to this hell
He creates
Undying

Corpses are suspended by their feet
Swaying dripping bloody piece of meat
Fastened to the ceiling leaking gore
Splashing down to the floor
Corpses he suspended turning pale
All the blood drained into his grail
Fastened to the ceiling dry and dead
Fluids of life have been shed
Hung and bled
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

set<pair<long, long> > dw,db,rw,rb;
set<pair<long, long> > ::iterator it,it1,it2;
long n,c[200000],s[200000];
long c1,c2,nv1,nv;
vector<pair<pair<long, long> ,long> > ans;
void add_edge(long a,long b,long c)
{
 ans.push_back(make_pair(make_pair(a,b),c));
 
}

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>c[i]>>s[i];
 if (c[i]==0)
 rb.insert(make_pair(s[i],i));
 else rw.insert(make_pair(s[i],i));   
}

for (int i=1;i<n;i++)
{
 if (rb.size()>0)
 {it1=rb.begin();
 c1=(*it1).first;}
 else c1=2e9;
 if (rw.size()>0){
 it2=rw.begin();
 c2=(*it2).first;}
 else c2=2e9;
 
 if (rb.size()==1&&c1<=c2)
 {
  it1=rb.begin();
  long qq=(*it1).second;
  for (it=rw.begin();it!=rw.end();++it)
  {
      long q=(*it).second;
      add_edge(q,qq,s[qq]);s[qq]=0;
  }
  break;
 }
 
 if (rw.size()==1&&c1>=c2)
 {
  it1=rw.begin();
  long qq=(*it1).second;
  for (it=rb.begin();it!=rb.end();++it)
  {
      long q=(*it).second;
      add_edge(q,qq,s[qq]);s[qq]=0;
  }
  break;
 }
// cout<<c1<<" "<<c2<<endl;
 
 if (c1>c2)
 {
  nv=(*it2).second;
  if (rb.size())
  {nv1=(*it1).second;}
  else {it1=db.begin();nv1=(*it1).second;}
  add_edge(nv,nv1,c2);
  rw.erase(rw.begin());
  if (rb.size())
  {
   rb.erase(rb.begin());
   s[nv1]-=c2;
//   if (s[nv1])
   rb.insert(make_pair(s[nv1],nv1));
  // else db.insert(make_pair(s[nv1],nv1));
  }
  dw.insert(make_pair(0,nv));
 }
 
 else
 {
     nv=(*it1).second;
  if (rw.size())
  {nv1=(*it2).second;}
  else {it2=dw.begin();nv1=(*it2).second;}
  add_edge(nv,nv1,c1);
  rb.erase(rb.begin());
  if (rw.size())
  {
   rw.erase(rw.begin());
   s[nv1]-=c1;
//   if (s[nv1])
   rw.insert(make_pair(s[nv1],nv1));
 //  else dw.insert(make_pair(s[nv1],nv1));
  }
  db.insert(make_pair(0,nv));
 }
 
}

for (int i=0;i<n-1;i++)
{
 cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
}
cin.get();cin.get();
return 0;}