/*
And it feels right this time
On his crash course with the big time
Pay no mind to the distant thunder
New day filled his head with wonder, boy

Says it feel right this time
Turned around and found the light lime
"Good day to be alive.
It's a good day to be alive", he said

Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way
Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way, hey, yeah

Don't it feel right like this?
All the pieces fall to his wish
"Sucker for that quick reward, boy
Sucker for that quick reward", they say

Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way
Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way, hey, yeah
It's comin' your way, it's comin' your way, yeah, yeah, here it comes

Yeah, then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way

Then it comes to be, yeah, yeah
Then it comes to be, yeah, yeah
Then it comes to be, yeah, yeah
Then it comes to be, yeah

Then it comes to be, yeah
Then it comes to be, yeah
Then it comes to be, yeah, yeah
Then it comes to be, yeah
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
//#define bs 1000000007
#define bsize 256

using namespace std;

bool nice(long x1,long y1,long x2,long y2)
{
 if (x1==x2)return false;
 if (y1==y2)return false;
 return true;
}

long a,b,ti,tj;
pair<pair<long, long> ,pair<long, long> > ans;
vector<pair<long, long> > v;
long s,af;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>a>>b;

for (int i=-1200;i<=1200;i++)
 for (int j=-1200;j<=1200;j++)
  if (i*i+j*j==b*b)v.push_back(make_pair(i,j));
  
for (int i=-1200;i<=1200;i++)
 for (int j=-1200;j<=1200;j++)
 {
  if (i*i+j*j!=a*a)continue;
  for (int q=0;q<v.size();q++)
  {
   ti=v[q].first;
   tj=v[q].second;
   s=i*tj-j*ti;
   s=abs(s);
//   cout<<s<<" "<<a*b*2<<endl;
   if (s!=a*b)continue;
   //cout<<i<<" "<<j<<" "<<ti<<" "<<tj<<endl;
   
   if (nice(0,0,i,j)&&nice(0,0,ti,tj)&&nice(i,j,ti,tj))
   {af=1;ans=make_pair(make_pair(i,j),make_pair(ti,tj));}
  }
 }

if (af==0)cout<<"NO"<<endl;
else
{
 cout<<"YES"<<endl;
 cout<<0<<" "<<0<<endl;
 cout<<ans.first.first<<" "<<ans.first.second<<endl;
 cout<<ans.second.first<<" "<<ans.second.second<<endl;
 
} 
cin.get();cin.get();
return 0;}