/*
I heard somebody fixed today
There was no last goodbyes to say
His will to live ran out
I heard somebody turned to dust

Looking back at what he left
A list of plans and photographs
Songs that never will be sung
These are the things he won't get done
The things he won't get done

I've seen the man use the needle
Seen the needle use the man
I've seen them crawl from the cradle
To the gutter on their hands
The fight a war but it's fatal
It's so hard to understand
I've seen the man use the needle
Seen the needle use the man

Just one shot to say goodbye
One last taste to mourn and cry
Cry, cry
Scores and shoots, the lights go dim
Just one shot to do him in

He hangs his head and wonders why
Why the monkey only lies
Lies, lies
But pay the pauper, he did choose
He hung his head inside the noose
He hung his head inside the noose

I've seen the man use the needle
Seen the needle use that man
I've seen them crawl from the cradle
To the coffin on their hands
They fight a war but it's fatal
It's so hard to understand
I've seen the man use the needle
Seen the needle in his hand
Cryptic writing on the wall
The beginning of the end
I've seen myself use the needle
Seen the needle in my hand

I've seen the man use the needle
Seen the needle use that man
I've seen them crawl from the cradle
To the coffin on their hands
They fight a war but it's fatal
It's so hard to understand
I've seen myself use the needle
Seen the needle in my hand

In my hand
In my hand
In my hand
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long m,k,p,a,b;
vector<long> g[200000];
long used[200000];
long dep[200000];
long level[200000];
long l,r,mid;

void dfs(long v)
{
 used[v]=1;
 level[dep[v]]++;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
  dep[q]=dep[v]+1;
  dfs(q);
 }
}

long long ttl,lev,qlev,tcost;
long long d,upl;

void pop(long val)
{
 ttl-=(level[qlev]);
 tcost-=ttl;
 if (ttl<=0||tcost<0)ttl=tcost=0;
}

void add(long val)
{
 if (ttl==val)return;
 if (d<level[upl]){long span=min(level[upl]-d,val-ttl);ttl+=span;tcost+=(qlev-upl)*span;d+=span;return;}
 d=0;
 upl--;
// if (upl<=1){ttl=1e9;return;}
}

bool solve(long val)
{
 if (val==0)return true;
 if (val==1)return (k>0);
 
long long bcost=2e9;
 upl=m;
 d=0;
 ttl=0;
 tcost=0;
 for (int i=m+1;i;--i)
 {
  qlev=i;
  if (upl>qlev){upl=qlev;d=0;}
  while (ttl<val&&upl>1){add(val);}
  if (tcost<bcost&&ttl==val)bcost=tcost;
//  cout<<i<<"   "<<tcost<<" "<<val<<endl;
  pop(val);
//  cout<<i<<"   "<<" "<<upl<<" "<<d<<" "<<tcost<<" "<<val<<endl;
  
 }
// cout<<val<<"  "<<bcost<<endl;
 if (bcost<=p)return true;
 return false;
}

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>m>>k>>p;
for (int i=1;i<m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

dep[1]=1;

dfs(1);

/*for (int i=0;i<=10;i++)
cout<<level[i]<<endl;
*/

l=0;
r=m-1;
if (r>k)r=k;

while (l<r)
{
 long mid=l+r+1;
 mid/=2;
 if (solve(mid))l=mid;
 else r=mid-1;
}
cout<<l<<endl;

cin.get();cin.get();
return 0;}