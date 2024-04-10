/*
Do you believe in the darkness below
Well I can summon them up

If you really want to know
As I tow the line
Between bad and evil
Nothing can touch me now
True believer

Born in sin where I pledge my evil oath
Violence is golden now

Did you really want to go
As I draw the line
Between bad and evil
Nothing can touch me now
True believer

True believer
Nothing can touch me now
Nothing can touch me now
True believer

No use in praying forever shall I roam
Smoke dusted angels now

It's the only way I know
As I cross the line
Between bad and evil
Nothing can touch me now
True believer

Ash to ash dust to dust
All I ever wanted was power of the blood
Now look what I have done
What I have become
I'm the chosen one
Never gonna take me
Never gonna change me
Never gonna escape me now

Do you believe there is evil in my soul
One final high is the way

That I really want to go
As I cross the line
Between bad and evil
Nothing can touch me now
True believer

True believer
Nothing can ever touch me now
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
#define right adsgasgadsg

using namespace std;

long t1[200000],t2[200000];
long n,a[200000],b[200000];
long has;
vector<pair<long, long> >vecord;
vector<pair<long, long> > vec[200000];
map<long, long> mapp;
vector<pair<long,long> > tv;
long ans;
long temp;
pair<long, long> tpair;
long tnum;
long ohead;
long need;
long l,r,mid;

long gett1(long r)
{
 long res=0;
 for (;r>=0;r=(r&(r+1))-1)
  res+=t1[r];
 return res;
}
long gett2(long r)
{
 long res=0;
 for (;r>=0;r=(r&(r+1))-1)
  res+=t2[r];
 return res;
}
void add1(long i,long d)
{
 for (;i<=100000;i=(i|(i+1)))
  t1[i]+=d;
}
void add2(long i,long d)
{
 for (;i<=100000;i=(i|(i+1)))
  t2[i]+=d;
}

int main(){
//freopen("refrain.in","r",stdin);
//freopen("refrain.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

long nn;
cin>>nn;
for (int iter=1;iter<=nn;iter++)
{
 cin>>a[n+1]>>b[n+1];
 if (a[n+1]>0)++n;
 else ++has;
}

for (int i=1;i<=n;i++)
{
  tv.push_back(make_pair(b[i],i));
}

for (int i=1;i<=n;i++)
{
 vec[a[i]].push_back(make_pair(b[i],i));
}

sort(tv.begin(),tv.end());

for (int i=0;i<tv.size();i++)
{
 mapp[tv[i].second]=i+1;
}


for (int i=1;i<=100000;i++)
{
 sort(vec[i].begin(),vec[i].end());
 reverse(vec[i].begin(),vec[i].end());
}

for (int i=1;i<=100000;i++)
{
 vecord.push_back(make_pair(vec[i].size(),i));
}

sort(vecord.begin(),vecord.end());
reverse(vecord.begin(),vecord.end());

for (int i=1;i<=n;i++)
{
 add1(mapp[i],1);
 add2(mapp[i],b[i]);
}
/*
for (int i=1;i<=n;i++)
 cout<<gett2(i)<<"  ";
 cout<<endl;
 */
ans=1e9;

for (int clev=100000;clev>=has-1&&clev>=0;--clev)
{
 for (int j=0;j<vecord.size();j++)
 {
  temp=vecord[j].second;
  if (vec[temp].size()<=clev)break;
  tpair=vec[temp].back();
  vec[temp].pop_back();
  tnum=tpair.second;
  add1(mapp[tnum],-1);
  add2(mapp[tnum],-tpair.first);
  ohead+=tpair.first;
  has++;
  n--;
 }
 need=clev+1-has;
 if (need<=0)ans=min(ans,ohead);// already
 if (need>n)continue; // can't
 l=0;
 r=100000;
 while (l<r)
 {
  mid=l+r;
  mid/=2;
  if (gett1(mid)>=need)r=mid;
  else l=mid+1;
 }
 temp=ohead+gett2(l);
 
// cout<<ohead<<" "<<has<<" "<<clev<<"  "<<temp<<" "<<l<<endl;
 
 ans=min(ans,temp);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}