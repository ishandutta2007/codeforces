/*
I don't know how to live through this hell
Woken up, I'm still locked in this shell
Frozen soul, frozen down to the core
Break the ice, I can't take anymore

Freezing, can't move at all
Screaming, can't hear my call
I am dying to live, cry out
I'm trapped under ice

Crystallized, as I lay here and rest
Eyes of glass stare directly at death
From deep sleep I have broken away
No one knows, no one hears what I say

Freezing, can't move at all
Screaming, can't hear my call
I am dying to live, cry out
I'm trapped under ice

Scream from my soul
Fate, mystified
Hell, forever more
Scream from my soul
Fate, mystified
Hell, forever more

No release from my cryonic state
What is this? I've been stricken by fate
Wrapped up tight, cannot move, can't break free
Hand of doom has a tight grip on me

Freezing, can't move at all
Screaming, can't hear my call
I am dying to live, cry out
I'm trapped under ice

Freezing, can't move at all
Screaming, can't hear my call
I am dying to live, cry out
I'm trapped under ice
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

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;


class Fenwick
{
 long long *m,*mt,N;
 public:
 Fenwick(long n);
 Fenwick(long long a[],long n);
 void add_range(long l,long long d);
 void add_range(long l,long r,long long d);
 long long sum(long r);
 long long sum(long l,long r);
};

Fenwick::Fenwick(long n)
{
 N=n;
 m=new long long[N];
 mt=new long long[N];
 for (int i=0;i<n;i++)
 m[i]=mt[i]=0;
}

void Fenwick::add_range(long r,long long d)
{
 if (r<0)return;
 for (int i=r;i>=0;i=(i&(i+1))-1)mt[i]+=d;
 for (int i=r|(r+1);i<N;i|=i+1)m[i]+=d*(r-(i&(i+1))+1);
}

void Fenwick::add_range(long l,long r,long long d)
{
 add_range(r,d);
 add_range(l-1,-d);
}

long long Fenwick::sum(long r)
{
 if (r<0)return 0;
 long long res=0;
 for (int i=r;i>=0;i=(i&(i+1))-1)res+=m[i]+mt[i]*(i-(i&(i+1))+1);
 for (int i=r|(r+1);i<N;i|=i+1)res+=mt[i]*(r-(i&(i+1))+1);
 return res;
}

long long Fenwick::sum(long l,long r)
{
 return sum(r)-sum(l-1);
}

Fenwick F(150000);

// ----------

set<pair<long, long> > v;
set<pair<long, long> > ::iterator it;
long n,m;
long cur[200000];
long tp,l,r,clr;
long gclr;

void add_pair(pair<long, long> p)
{
/* cout<<p.first<<"  "<<p.second<<endl;
 cin.get();
 */
 cur[p.first]=gclr;
 it=v.lower_bound(p);
 pair<long, long> tp1;
 if (it!=v.end())
 {
  tp1=(*it);
  if (cur[tp1.first]==cur[p.first]&&tp1.first==p.second+1)
  {
   v.erase(it);
   p.second=tp1.second;
   
  }
 }
 it=v.lower_bound(p);
 if (v.size()>0&&it!=v.begin())
 {
  --it;
  tp1=(*it);
  if (cur[tp1.first]==cur[p.first]&&p.first==tp1.second+1)
  {
   v.erase(it);
   p.first=tp1.first;
  }
 }
 v.insert(p);
 cur[p.first]=gclr;
}

void upd(long l, long r,long clr)
{
 //cout<<l<<"    "<<r<<endl;
 if (r<l)return;
 /*
 for (it=v.begin();it!=v.end();++it)
  cout<<"%%"<<(*it).first<<"  "<<(*it).second<<"  "<<cur[(*it).first]<<endl;
 cout<<endl;
 */
 pair<long, long> tp=make_pair(l+1,-1);
 it=v.lower_bound(tp);
 --it;
 pair<long, long> tp1=(*it);
 long cc=tp1.first;
 v.erase(tp1);
 
 pair<long, long> tp2;
  
  //cout<<l<<"   "<<r<<" "<<tp1.first<<"  "<<tp1.second<<endl;
  
  gclr=clr;
  
 if (tp1.first<=l&&tp1.second>=r) // cvrs
 {
  F.add_range(l,r,abs(clr-cur[tp1.first]));
  long old=cur[tp1.first];
  cur[l]=clr;
  if (tp1.first<l){tp2=make_pair(tp1.first,l-1);gclr=old;
  add_pair(tp2);}
  if (tp1.second>r){tp2=make_pair(r+1,tp1.second);gclr=old;add_pair(tp2);}
  tp2=make_pair(l,r);
  gclr=clr;
  add_pair(tp2);
//  v.insert(tp2);
  return ;
 }
 
 F.add_range(l,tp1.second,abs(clr-cur[tp1.first]));
 cur[l]=clr;
 if (tp1.first<l){tp2=make_pair(tp1.first,l-1);gclr=cur[tp1.first];//cur[tp2.first]=clr;
 add_pair(tp2);}
 tp2=make_pair(l,tp1.second);
 gclr=clr;
 add_pair(tp2);
// v.insert(tp2);
 
 upd(tp1.second+1,r,clr);
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
{
 v.insert(make_pair(i,i));
 cur[i]=i;
}

for(;m;--m)
{
 cin>>tp;
 if (tp==2)
 {
  cin>>l>>r;
  cout<<F.sum(l,r)<<endl;
 }
 else
 {
  cin>>l>>r>>clr;
  upd(l,r,clr);
 }
}

cin.get();cin.get();
return 0;}