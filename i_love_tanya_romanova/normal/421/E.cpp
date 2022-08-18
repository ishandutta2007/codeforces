/*
I lost my mind
I lost myself
I kept on falling
Straight down to hell

Stood at the crossroads
I needed a sign
To find my way
Out of the night

As the light seemed to be too far away
The answer to every prayer
Looked into my eyes and took my hand

(It took)
Two hearts but only one wish
Two hearts, together we're strong
(It took)
Two hearts but only one wish
Two hearts, together we're strong

The wheels of life
Spinning around
I kept on'falling
No feet on the ground

Reached out for something
But I forgot to give
It took an angel to show me how to live

As the light seemed to be too far away
The answer to every prayer
Looked into my eyes and took my hand

(It took)
Two hearts but only one wish
Two hearts, together we're strong
(It took)
Two hearts but only one wish
Two hearts, together we're strong
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

long n,m;
long subsize[10000000],ar[10000000];
long x,y,tp,er;
vector<long> ans;
long anss[3000000];
long q;
set<long> f;
set<long>::iterator it;
long usd[2000000];

void build (long v,long tl,long tr)
{
 if (tl==tr){if (tl>1000000&&tl<=1000000+n)subsize[v]=1;return ;}
 long tm=tl+tr;
 tm/=2;
 build(v*2,tl,tm);
 build(v*2+1,tm+1,tr);
 subsize[v]=subsize[v*2]+subsize[v*2+1];
}

long solve(long v,long tl,long tr,long need)
{
 if (tl==tr)
 {return tl;}
 long tm=tl+tr;
 tm/=2;
 if (subsize[v*2]>=need){return solve(v*2,tl,tm,need);}
 need-=subsize[v*2];
 return solve(v*2+1,tm+1,tr,need);
}

void update(long v,long tl,long tr,long ps,long val)
{
 if (tl==tr){ar[tl]=val;if (val==0)subsize[v]=0;else subsize[v]=1;return;}
 long tm=tl+tr;
 tm/=2;
 if (ps<=tm){update(v*2,tl,tm,ps,val);}
 else update(v*2+1,tm+1,tr,ps,val);
 subsize[v]=subsize[v*2]+subsize[v*2+1];
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
build(1,1,2000000);

for (int i=1;i<=m;i++)
{
 cin>>x>>y;
 tp=solve(1,1,2000000,y);
 //cout<<tp<<" "<<ar[tp]<<endl;
 if (ar[tp]!=0&&ar[tp]!=x){er=1;}
 anss[tp]=x;
 update(1,1,2000000,tp,0);
 update(1,1,2000000,1000001-i,x);
}

for (int i=1;i<=n;i++)
f.insert(i);

for (int i=1000001;i<=1000000+n;i++)
{
 if (anss[i]==0)continue;
 if (usd[anss[i]])er=1;
 usd[anss[i]]=1;
 f.erase(anss[i]);
}

for (int i=1;i<=n;i++)
{
 if (anss[i+1000000]==0){it=f.begin();q=(*it);f.erase(it);ans.push_back(q);}
 else
 {
  ans.push_back(anss[i+1000000]);
 }
}
if (er)cout<<-1<<endl;else
{
for (int i=0;i<ans.size();i++)
{if (i)cout<<" ";cout<<ans[i];}
cout<<endl;
}
cin.get();cin.get();
return 0;}