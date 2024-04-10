/*
Sometimes I wonder what went wrong
Do I even belong here at all no
Where am I how did I get here
Wale me up from this nightmare
I don't deserve this no one does

And then he stared into the sky
Feeding his fright denying
Feeling the pain hear the screaming
I don't want to die

Clear my mind
So many times I've tried I've failed
So many people slaughtered
Don't they have a conscience
Slaves brainwashed to be that way

The darkness clouds I can't see
Will I see my family
They pray
Would they die for me
Bury me
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

long n;
double d,x,y,r,span,t;
double ang;
long at0;
vector<pair<double, long> > evs;
double temp;
long ans;

double ev(double e)
{
 while (e<0)e+=2*M_PI;
 while (e>=2*M_PI)e-=2*M_PI;
 return e;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>d;
for (int i=1;i<=n;i++)
{
 cin>>x>>y>>r;
 span=0;
 t=x*x+y*y;
 t=sqrt(t);
 while (true)
 {
  span+=d;
  if (span>t+r+eps)break;
  if (span<=t-r-eps)continue;
  ang=atan2(y,x);
  temp=t*t+span*span-r*r;
  temp=temp/t/span;
  temp/=2;
  temp=acos(temp);
  if (ang-temp<0&&ang+temp>0)++at0;
  evs.push_back(make_pair(ev(ang-temp),-1));
  evs.push_back(make_pair(ev(ang+temp),1));
 }
}

sort(evs.begin(),evs.end());
ans=at0;
for (int i=0;i<evs.size();i++)
{
 at0-=evs[i].second;
 ans=max(ans,at0);
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}