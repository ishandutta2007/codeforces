/*
I've been hurt so many times
And been told so many lies
No one cares what's on my mind
At all

I feel lost while on my own
There's no place I call home
But I still want to believe
I've not been mistreated
Not been mistreated

It's my heart that goes on
To believe there's someone
Who needs me to carry on
'till the end I'm holding on

I've not been mistreated
Not been mistreated
Not been mistreated

I know in ways - have to be strong
Pouring my strain - it's turning out wrong
Feels like a stream of endless old fears
But I still want to believe

I've not been mistreated
Not been mistreated
Not been mistreated
I've not been ...

These are the days when dreams are lost
Bleeding in vain and wearing the cost
Of nonpaid lies - I'm crying for help
But I still want to believe

I've not been mistreated
Not been mistreated
Not been mistreated
I've not been ...

I've tried more than once before
To find out what I've done wrong
Still don't know how to go on
To understand why I've been mistreated - mistreated

Still don't know where to go
Still got no place I call home - call home

I've been hurt so many times
And been told so many lies
No one cares what's on my mind
At all

I feel lost while on my own
Can't believe there's someone
Who needs me to carry on
I'm holding on

I've not been mistreated
Not been mistreated
I've not been mistreated
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long t[200000],s[200000],p[200000];
long long bpos;
set<long long> upr;
vector<long long> g;
long long n;
long long etime[200000];
long long endtime;
vector<pair<long long,long long> > evs;
set<pair<long long, long long> > events,ev1;
set<pair<long long, long long> >::iterator it;
long long qtime;
long long rem[200000];

void check()
{
 long long l;
 
 events.clear();
 for (int i=1;i<=n;i++)
 rem[i]=s[i];

 for (int i=1;i<=n;i++)
 {
  events.insert(make_pair(t[i],i));   
 }
 
 while (events.size())
 {
  it=events.begin();
  
  long long i=(*it).second;
  long long qtime=(*it).first;
  events.erase(it);
  ev1.insert(make_pair(-p[i],i));
  while (true)
  { 
   if (ev1.size()==0)break;
   it=ev1.begin();
   long long i=(*it).second;
   
   //cout<<rem[2]<<" "<<rem[1]<<" "<<rem[3]<<"%"<<endl;
   //cout<<qtime<<" "<<i<<" "<<rem[i]<<" "<<events.size()<<endl;
   if (events.size()==0)
   {
    etime[i]=qtime+rem[i];
    rem[i]=0;
    qtime=etime[i];
    ev1.erase(ev1.begin());
   }
   else
   {
    it=events.begin();
    long long t1,t2;
    t1=(*it).first;
    t2=qtime+rem[i];
  //  cout<<" "<<t1<<" "<<t2<<endl;
    if (t2<=t1)
    {
     etime[i]=t2;ev1.erase(ev1.begin());
     qtime=etime[i];
    }
    else
    {
    // cout<<t1<<"^^"<<qtime<<" "<<rem[i]<<endl;
     rem[i]-=(t1-qtime);
     break;
    }
   }
  }
 }
 /*for (int i=1;i<=n;i++)
 cout<<etime[i]<<" ";
 cout<<endl;
 */
}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=1;i<=n;i++)
{
    cin>>t[i]>>s[i]>>p[i];
    if (p[i]==-1)
     bpos=i;
     else
     {
         upr.insert(p[i]);
     }
}

cin>>endtime;

for (int i=1;i<=n;i++)
{
    if (i==bpos)continue;
    if (upr.find(p[i]-1)==upr.end()&&p[i]>1)
    g.push_back(p[i]-1);
    if (upr.find(p[i]+1)==upr.end())
    g.push_back(p[i]+1);
}
sort(g.begin(),g.end());
/*
for (int i=0;i<g.size();i++)
cout<<g[i]<<" ";
cout<<endl;
*/

long l,r,m;
l=0;
r=g.size()-1;

while (l<r)
{
 m=l+r;m/=2;
 p[bpos]=g[m];
 check();
 if (etime[bpos]>endtime){l=m+1;} else r=m;
 //cout<<m<<" "<<g[m]<<" "<<etime[bpos]<<endl;
}

//cout<<g[l]<<endl;
p[bpos]=g[l];
//p[bpos]=929825080;
check();
cout<<g[l]<<endl;
for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<etime[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}