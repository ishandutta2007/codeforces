/*
What fine judgement I see
in the eyes of our world leaders
Oh how beautiful life could be
if it hadn't been shot to pieces

Shot to pieces

What secret music do I hear
upon the drums of my ear

What great pleasure I feel
I come from nowhere and I shall return
Because of you people I will flee
I see my late identity burn
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

vector<pair<long, pair<long, long> > >v;
long n,h,l,r;
multiset<long> s;
multiset<long>::iterator it;
long cur;
long th;
long mx;
vector<pair<long,long> > ans;

void add_point(long a,long b)
{
 ans.push_back(make_pair(a,b));
}

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>h>>l>>r;
 v.push_back(make_pair(l,make_pair(1,-h)));
 v.push_back(make_pair(r,make_pair(2,h)));
}
sort(v.begin(),v.end());

cur=0;
for (int i=0;i<v.size();i++)
{
 if (v[i].second.first==1)
 {
  th=v[i].second.second;
  th=-th;
  if (th>cur)
  {
   add_point(v[i].first,cur);
   add_point(v[i].first,th);
   cur=th;
  }
   s.insert(th);
 }   
 if (v[i].second.first==2)
 {
  th=v[i].second.second;
  it=s.find(th);
  s.erase(it);
  it=s.end();
  if (it==s.begin())mx=0;
  else
  {
      --it;
      mx=(*it);
  }
  if (mx!=cur)
  {
   add_point(v[i].first,cur);
   add_point(v[i].first,mx);
   cur=mx;
  }
 }
}

cout<<ans.size()<<endl;

for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

cin.get();cin.get();
return 0;}