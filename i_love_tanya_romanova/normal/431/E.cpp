/*
I admit it
What's to say, what
I'll relive it
Without pain, mmmm

Backstreet lover on the side of the road
I got a bomb in my temple that is gonna explode
I got sixteen gauge buried under my clothes, I play

Once upon a time I could control myself
Once upon a time I could lose myself, yeah

Oh, try and mimic
What's insane
I am in it
Where do I stand?
Stand, stand

Indian summer and I hate the heat
I got a backstreet lover on the passenger seat
I got my hand in my pocket, so determined, discreet, I pray
Once upon a time I could control myself
Once upon a time I could lose myself, yeah yeah yeah

Once upon a time I could control myself
Once upon a time I could lose myself, yeah yeah yeah
Once, upon a time I could love myself
Once upon a time I could love you

Once, once
Once, once
Once, once
Yeah
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

long n,q,ar[200000];
long tp;
long a,b;
long long t;
double l,r,mid;
set<long> done;
vector<pair<long, long> > v;
vector<long> vv;
long long s[200000];

double gv(double x)
{
long mid;
 if (vv[0]>x)return 0;
 long l,r;
 l=0;
 r=n-1;
 while (l<r)
 {
       mid=l+r+1;
  mid/=2;
  if (vv[mid]>x)r=mid-1;
  else l=mid;
 }
// cout<<x<<"   "<<l<<" "<<vv[l]<<"  "<<s[l]<<endl;
 return x*(l+1)-s[l];
}

double v1,t1,t2;

bool solve(double x)
{
 v1=gv(x);
 t1,t2;
 
// cout<<x<<"  "<<v1<<endl;
 for (int i=0;i<v.size();i++)
 {
  if (ar[v[i].first]>x){t1=0;} else t1=x-ar[v[i].first];
  if (v[i].second>x){t2=0;} else t2=x-v[i].second;
  v1-=t1;
  v1+=t2;
 }
// cout<<x<<"  ^ "<<v1<<endl;
 if (v1<t)return false;
 return true;
}

void construct()
{
 done.clear();
 for (int i=0;i<v.size();i++)
  ar[v[i].first]=v[i].second;
 vv.clear();
 for (int i=1;i<=n;i++)
  vv.push_back(ar[i]);
  sort(vv.begin(),vv.end());
 
 s[0]=vv[0];
 for (int i=1;i<n;i++)
  s[i]=s[i-1]+vv[i];
 v.clear();
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>q;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
//ar[i]=rand();
}

construct();

for (int i=1;i<=q;i++)
{
 if (v.size()==300)construct();
 cin>>tp;
//tp=rand()%2+1;

 if(tp==1)
 {
  cin>>a>>b;
  //a=rand()%n+1;
  //b=rand();
  if (done.find(a)==done.end())
  {
   done.insert(a);
   v.push_back(make_pair(a,b));
  }
  else
  {
   for (int j=0;j<v.size();j++)
    if (v[j].first==a)v[j].second=b;
  }
 }
 else
 {
  cin>>t;
//t=rand();
  l=0;
  r=1e9+t/n+2;
  for (int iter=1;iter<=50;iter++)
  {
   mid=l+r;
   mid/=2;
//   cout<<mid<<" "<<solve(mid)<<endl;
   if (solve(mid))r=mid;
   else l=mid;
  }
  cout.precision(9);
  cout<<fixed<<l<<endl;
 }
}

cin.get();cin.get();
return 0;}