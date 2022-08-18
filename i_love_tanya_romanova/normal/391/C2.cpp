/*
I watch it all collapse
It never seems to last
As long as I need it to

A beautiful mistake
A wound without a trace
Was it ever really true?

We can't see the future
We can't rewrite the past
Tried to hold it captive
But it faded all too fast

Is it much too late
To save yourself?

Memories keep calling
Deeper into fear I'm falling
Lost within my mind it haunts me for so long

Trapped beneath the glass
Never a shadow cast
A perfect picture's all I knew

Lost within the struggle
Never felt so much alive
Gave into the rapture
Didn't care if I survived

Is it too much late
To save yourself?

Memories keep calling
Deeper into fear I'm falling
Lost within my mind
It haunts me for so long
All my hope is dying
Even though I keep on trying
Lost within my mind
It haunts me for so long 
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

long long n,k,a,b,need;
vector<pair<long long, long long> > v;
vector<long long> v1,v2;
long long ans,alost,rem,todel,cost;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 v.push_back(make_pair(a,b));
}

sort(v.begin(),v.end());
reverse(v.begin(),v.end());

if (k==v.size()+1)need=0;else
need=v[k-1].first;

ans=1e18;

for (int score=need;score<=need+10;score++)
{
 alost=0;
 if (score>n)continue;
 for (int p=0;p<v.size();p++)
 if (v[p].first>score){alost++;}
 rem=k-alost-1;
 if(rem<0)continue;
 v1.clear();
 v2.clear();
 for (int i=0;i<v.size();i++)
 {
  if (v[i].first>score||v[i].first<score-1)v1.push_back(v[i].second);
  else v2.push_back(v[i].second);
 }
 sort(v1.begin(),v1.end());
 sort(v2.begin(),v2.end());
 if (v2.size()>rem)
 {
  todel=v2.size()-rem;
 }
 else todel=0;
 cost=0;
 if (todel>score)continue;
 for (int i=0;i<todel;i++)cost+=v2[i];
 for (int i=todel;i<v2.size();i++)v1.push_back(v2[i]);
 sort(v1.begin(),v1.end());
 for (int i=todel+1;i<=score;i++)
 cost+=v1[i-todel-1];
 ans=min(ans,cost);
}
if (ans>1e16)ans=-1;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}