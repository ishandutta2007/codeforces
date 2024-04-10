/*
Always, known in all my time
A little left of center now
Reflect as I realize
That all I need is to find

The middle pillar
Path to sit like the sun by a
Star in the sky and just be
Sinners, casting stones at me

I, I stand, not crawling
Not falling down
I, I bleed the demons
That pull me down

I, I stand
(For nothing)
Not crawling
(The center)
Not falling down
(Of calms within the eye)

I, I'll bleed
(For no one)
The demons
(But myself)
That pull me down
(For me and no one else)

Goodbye, sunshine, I've put it out again, sad
I'm over, personalities, conflicting
I don't need you, or anyone, but me I'll just be
Living my own life, I feel my glowing center grow, infecting

I feel alive and shovel dirt over lime
Plan it in myself to sit like a seed under
Covers of earth and just be
Sinners, pointing fingers at me

I, I stand
(For nothing)
Not crawling
(By myself)
Not falling down

I, I'll bleed
(For no one)
The demons
(But myself)
That drag me down

I, I stand
(For nothing)
Not crawling
(The center)
Not falling down
(Of calms within the eye)

I, I'll bleed
(For no one)
The demons
(But myself)
That pull me down
(For me and no one else)

Come play kill
(Refuse my body, refuse my shadow)
Stone cold will
(Refuse to lead this, refuse to follow)
Bitter pills
(Refuse to feed this, refuse to swallow)
(I'm fueled godless)
Come play, come play

Just be, just be, just be
Just be, just be, just be

I, I stand
(For nothing)
Not crawling
(By myself)
Not falling down

I, I'll bleed
(For no one)
The demons
(But myself)
That drag me down

I, I stand
(For nothing)
Not crawling
(The center)
Not falling down
(Of calms within the eye)

I, I'll bleed
(For no one)
The demons
(But myself)
That drag me down
(For me and no one else)
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

using namespace std;

long long pw[1<<20],q;
string st;
vector<pair<long, string> >g[1<<19];
string zr;
long long ex;
long long n;
long ans;
vector<long long> sums;

void dfs(long v)
{
 for (int i=0;i<g[v].size();i++)
 {
  string temp=g[v][i].second;
  long vv=g[v][i].first;
  for (int j=0;j<temp.size();j++)
  {
   long long tt=temp[j];
   tt*=pw[sums.size()];
   sums.push_back(sums.back()+tt);
   if (sums.size()>zr.size()){
   tt=sums.back()-sums[sums.size()-zr.size()-1];
   if (tt==ex*pw[sums.size()-zr.size()])++ans;}
  }
  dfs(vv);
  for (int j=0;j<temp.size();j++)
   sums.pop_back();
 }
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pw[0]=1;
for (int i=1;i<=500000;i++)
 pw[i]=pw[i-1]*173;

cin>>n;
for(int i=2;i<=n;i++)
{
 cin>>q>>st;
 g[q].push_back(make_pair(i,st));
}

cin>>zr;

for (int i=0;i<zr.size();i++)
{
 ex=ex+zr[i]*pw[i];
}

sums.push_back(0);
dfs(1);

cout<<ans<<endl;

cin.get();cin.get();
return 0;}