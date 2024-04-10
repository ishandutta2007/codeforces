/*
Grasped by this certain thing
Expressing what I feel
Doin' it for my belief
Knowin' in my heart it's real

Mastermind won't let it stay
Givin' it his sentiment
You can put your thoughts away
Compromise ain't what was meant

Who gave you
The right to choose
Tell you why I'm here today
Never ever gonna lose

Make a believer
Out of you
Make a believer
What will you do?

I know that I'm the only one that
Needs to prove it to myself
I don't need to fix your mind
It's already added to my wealth

Make a believer
Out of you
Make a believer
What will you do?

What will you do?
No
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

long n,q;
vector<long> v;
vector<pair<long, long> > v1,v2;
long ans1,ans2;
long m;

vector<pair<long, long> > make(vector<long> v)
{
 vector<pair<long, long> > res;
long cnt=1;
 for (int i=1;i<v.size();i++)
 {
  if (v[i]!=v[i-1])
  {
   res.push_back(make_pair(v[i-1],cnt));
   cnt=1;
  }
  else ++cnt;
 }
 res.push_back(make_pair(v.back(),cnt));
 return res;
}

long l,r,s1,s2;

int main(){
//freopen("knockout.in","r",stdin);
//freopen("knockout.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>q;
 v.push_back(q);
}
sort(v.begin(),v.end());
v1=make(v);
v.clear();
cin>>m;
for (int i=0;i<m;i++)
{
 cin>>q;
 v.push_back(q);
}
sort(v.begin(),v.end());
v2=make(v);

l=0;
r=0;

ans1=n*3;
ans2=m*3;

s1=s2=0;

while (l<v1.size()||r<v2.size())
{
 if (l==v1.size())
 {
  s2+=v2[r].second;
  ++r;
 }
 else if (r==v2.size())
 {
  s1+=v1[l].second;
  ++l;
 }
 else if (v1[l].first<v2[r].first)
 {
  s1+=v1[l].second;
  ++l;
 }
 else if (v1[l].first>v2[r].first)
 {
  s2+=v2[r].second;
  ++r;
 }
 else
 {
  s1+=v1[l].second;
  s2+=v2[r].second;
  ++l;++r;
 }
 if((n*3-s1)-(m*3-s2)>ans1-ans2)
 {
  ans1=n*3-s1;
  ans2=m*3-s2;
 }
}

cout<<ans1<<":"<<ans2<<endl;

cin.get();cin.get();
return 0;}