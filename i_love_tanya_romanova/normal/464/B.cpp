/*
Free at last
Finally tasting happiness
Five years of hell for nothing
Trapped inside the minds of failures

A wise man once said
"That which does not kill us makes us stronger"
But we were dead
So are we now invincible?

Determination, perseverance
Resolution, resurrection
Determination, perseverance
Resolution, resurrection

Final straw underlining ignorance
Consumed by greed and hate
Nothing swept under the veil of silence

Reality can't hear
Ways to get stopped just to start all over
Treated like shit
Pushed aside and expect to pull

Determination, perseverance
Resolution, resurrection
Determination, perseverance
Resolution, resurrection

We have become so goddamn powerful
We have become so goddamn powerful
We have become so goddamn powerful
We have become so goddamn powerful
We have become so goddamn powerful
We have become so goddamn powerful

All the beatings you gave us
We will use them against you
All the beatings you gave us
We will use them against you

Determination, perseverance
Resolution, resurrection
Determination, perseverance
Resolution, resurrection

Free at last
Finally tasting happiness
The resurrection, resurrection
Resurrection, resurrection
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
#define bsize 512

using namespace std;

long long ar[10][4];
vector<long> vec[10];
long ans;
long long crd[20][10];
long long anss[20][10];

long long gd(long a,long b)
{
 long long s=0;
 for (int i=0;i<3;i++)
 {
  s+=(crd[a][i]-crd[b][i])*(crd[a][i]-crd[b][i]);
 }
 return s;
}

bool bad(long long x)
{
 if (x==0)return 1;
 long long temp=sqrt(x+0.5);
 
 for (long long i=temp-1;i<=temp+1;i++)
 if (i*i==x)return false;
 return true;
}

bool check()
{
 vector<long long> edges;
 for (int i=0;i<8;i++)
  for (int j=i+1;j<8;j++)
   edges.push_back(gd(i,j));
 sort(edges.begin(),edges.end());
 if (bad(edges[0]))return false;
 for (int i=0;i<12;i++)
  if (edges[i]!=edges[0])return false;
 for (int i=12;i<24;i++)
  if (edges[i]!=edges[0]*2)return false;
 for (int i=24;i<28;i++)
  if (edges[i]!=edges[0]*3)return false;
 return true; 
}

void solve(long dep)
{
 if (dep<8)
 {
  do
  {
   if (ans)break;
   solve(dep+1);
  }while (next_permutation(vec[dep].begin(),vec[dep].end()));
  return;
 }
 for (int i=0;i<8;i++)
 {
  for (int j=0;j<3;j++)
   crd[i][j]=ar[i][vec[i][j]];
 }
 if (check())
 {
  ans=1;
  for (int i=0;i<8;i++)
   for (int j=0;j<3;j++)
    anss[i][j]=crd[i][j];
 }
 return;
}

int main(){
//freopen("highway.in","r",stdin);
//freopen("highway.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<8;i++)
{
 for (int j=0;j<3;j++)
  cin>>ar[i][j];
}

for (int i=0;i<8;i++)
 for (int j=0;j<3;j++)
  vec[i].push_back(j);

solve(1);

if (ans){cout<<"YES"<<endl;
for (int i=0;i<8;i++)
cout<<anss[i][0]<<" "<<anss[i][1]<<" "<<anss[i][2]<<endl;
}
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}