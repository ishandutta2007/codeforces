/*
Ticking away the moments that make up a dull day
Fritter and waste the hours in an off-hand way
Kicking around on a piece of ground in your home town
Waiting for someone or something to show you the way

Tired of lying in the sunshine staying home to watch the rain
You are young and life is long and there is time to kill today
And then one day you find ten years have got behind you
No one told you when to run, you missed the starting gun

And you run and you run to catch up with the sun but it's sinking
Racing around to come up behind you again
The sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death

Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
Hanging on in quiet desperation is the English way
The time is gone, the song is over, thought I'd something more to say

Home, home again
I like to be here when I can
When I come home cold and tired
It's good to warm my bones beside the fire
Far away, across the field
The tolling of the iron bell
Calls the faithful to their knees
To hear the softly spoken magic spell
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,m,s,a[200000],b[200000],c[200000];
long long l,r,tcost;
set<pair<long long, long long> > ::iterator it;
vector<pair<long long, long long> > v1,v2;
long long mid;
set<pair<long long, long long> > sett;
long long qp;
long long tp;
long ans[333333];

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
  
cin>>n>>m>>s;
for (int i=0;i<m;i++)
cin>>a[i];
for (int i=0;i<n;i++)
cin>>b[i];
for (int i=0;i<n;i++)
cin>>c[i];

l=1;
r=1e6;

for (int i=0;i<m;i++)
v1.push_back(make_pair(a[i],i));
for (int i=0;i<n;i++)
v2.push_back(make_pair(b[i],i));// bBd

sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());             
while (l<r)
{
 mid=l+r;
 mid/=2;
 tcost=0;
 sett.clear();
 qp=n-1;
 for (int i=m-1;i>=0;i-=mid)
 {
  while (qp>=0&&v2[qp].first>=v1[i].first){tp=v2[qp].second;sett.insert(make_pair(c[tp],tp));--qp;}
  // d push yT
  if (sett.size()==0)tcost+=1e10;// easBv
  else
  {
   it=sett.begin();
   tcost+=(*it).first;
   sett.erase(it);
  }
 }
 if(tcost>s)l=mid+1;
 else r=mid;
}

if (l>333333){cout<<"NO"<<endl;}
else
{
    mid=l;
    cout<<"YES"<<endl;
    // ttQ
    
    tcost=0;
 sett.clear();
 qp=n-1;
 for (int i=m-1;i>=0;i-=mid)
 {
  while (qp>=0&&v2[qp].first>=v1[i].first){tp=v2[qp].second;sett.insert(make_pair(c[tp],tp));--qp;}
  if (sett.size()==0)tcost+=1e10;
  else
  {
   it=sett.begin();
//   tcost+=(*it).first;
   tp=(*it).second;
   
    for (int j=i;j>i-l&&j>=0;--j)
     ans[v1[j].second]=tp+1;
  
   sett.erase(it);
  }
 }
 // dn
 for (int i=0;i<m;i++)
 {
  if (i)cout<<" ";
  cout<<ans[i];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}