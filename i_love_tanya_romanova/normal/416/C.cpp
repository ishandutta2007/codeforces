/*
You take this all for granted.
All the things that used to be you.
By keeping you distracted
Just long enough to bleed you... dry

A reason for your anger,
It's what I need, it's what I need.
To recognize the truth
It's what I need, it's what I need.
So burn your paper Jesus
It's what I need, it's what I need,
And all the things you do,
It's what I need, it's what I need.

Question what they tell you
All the lies that they are teaching,
And they've made a corporation
Out of desperate people's feelings... of fear

Somebody chose these words for you.
Interpretations of the truth.
Somewhere behind your fear they hide.
To fill the holes inside.
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

long n,a,b,m;
vector<pair<pair<long, long> ,long> > v;
vector<pair<long, long> > answ;
long ans,used[20000],bp;
long tt;
vector<pair<long, long> > vec;
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 v.push_back(make_pair(make_pair(b,-a),i));
}
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
cin>>m;
for (int i=1;i<=m;i++){
cin>>tt;vec.push_back(make_pair(tt,i));}

sort(vec.begin(),vec.end());

for (int i=0;i<v.size();i++)
{
 bp=0;
 for (int j=1;j<=m;j++)
  if (vec[j-1].first>=-v[i].first.second&&used[j]==0)
  {
   bp=j;break;
  }
 if (bp){ans+=v[i].first.first;answ.push_back(make_pair(v[i].second,vec[bp-1].second));used[bp]=1;}
}

cout<<answ.size()<<" "<<ans<<endl;
for (int i=0;i<answ.size();i++)
 cout<<answ[i].first<<" "<<answ[i].second<<endl;
 
cin.get();cin.get();
return 0;}