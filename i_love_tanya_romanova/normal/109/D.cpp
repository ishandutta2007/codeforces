/*
All it's all or nothing with your ego tripping
Everybody's looking for a Sunday mission
Ain't nobody searching for a second chance
I'm just looking for a new romance

And all it's all or nothing with your ego tripping
Everybody's looking for a Sunday mission
Ain't nobody searching for a second chance
I'm just looking for a new romance

Because you're too serious
You're gonna make me delirious
Because you're too serious for

Losing, losing, losing and I'm feeling lucent
Everybody's losing and there's no one choosing
Ain't nobody searching for a second chance
I'm just looking for a new romance

Because you're too serious
You're gonna make me delirious
Because you're too serious for me

Because you're too serious
You're gonna make me delirious
Because you're too serious
You're gonna make me delirious
Because you're too serious for me
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

long n,ar[1<<18];
long er;
vector<pair<long, long> > v;
long lp,ps[1<<18];
vector<pair<long, long> > ans;
long lv;

void solv(long a,long b)
{
 if (a==b)return;
 ans.push_back(make_pair(a,b));
 swap(ps[ar[a]],ps[ar[b]]);
 swap(ar[a],ar[b]);
}

bool luck(long x)
{
 while (x)
 {
  if (x%10!=4&&x%10!=7)return 0;
  x/=10;
 }
 return 1;
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
cin>>ar[i];

er=0;
for (int i=2;i<=n;i++)
if (ar[i]<ar[i-1])er=1;

if (er==0)
{
 cout<<0<<endl;
 return 0;
}

for (int i=1;i<=n;i++)
{
 v.push_back(make_pair(ar[i],i));
}

sort(v.begin(),v.end());

lp=-1;
for (int i=1;i<=n;i++)
{
 if (luck(v[i-1].first))
   {lp=v[i-1].second;break;}
}

if (lp==-1)
{
           cout<<lp<<endl;
           return 0;
}

for (int i=0;i<n;i++)
 ar[v[i].second]=i+1;

for (int i=1;i<=n;i++)
 ps[ar[i]]=i;
 
lv=ar[lp];

for (int i=1;i<=n;i++)
{
 if (i==lp)continue;
 if (ps[i]==i)continue;
 solv(i,ps[lv]);
 solv(i,ps[i]);
/* for (int j=1;j<=n;j++)
  cout<<ar[j]<<" ";
  cout<<endl;*/
}

if (ar[lv]!=lv)
solv(lv,ar[lv]);

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

cin.get();cin.get();
return 0;}