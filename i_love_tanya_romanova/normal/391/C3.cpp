/*
The dream inside of me
Is a death inside of you
You're redemption was being different
We last way too late
That your laugh was always fake
It bends until it breaks
Illusions we've forsaken

A vision still remains
Of a world that lost and can't be saved
It's a chance we have to take
Our only chances are the ones we create

Waiting for this day to come
Thought I'd be left for dead
But the light still shines ahead
The whole world has come undone
Though we will carry on
Until your ways are dead and gone

The answers can't be seen
And hatred's all you've had
Living lie for the tangling
See through all the lies
Destroy your last disguise
Defend to survive
Refuse to compromise

Way to replace the pain
And make a stake we're all the same
Escape comprehend leave behind
And follow it till the echo dies

Waiting for this day to come
Thought I'd be left for dead
But the light still shines ahead
The whole world has come undone
Though we will carry on
Until your ways are dead and gone

The dream inside of me
Is a death inside of you
You're redemption was being different
We last way too late
That your laugh was always fake
It bends until it breaks
And mends you dream forsaken

A vision still remains
Of a world that lost and can't be saved
Escape comprehend leave behind
And follow it till the echo dies

Waiting for this day to come
Thought I'd be left for dead
But the light still shines ahead
The whole world has come undone
Though we will carry on
Until your ways are dead and gone
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