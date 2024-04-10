/*
   
  ,
  
 .
    :
    
   ,
  .

,  
  !
    ,
  .
  , !
  ,
  ,
   .

    
    :
    ,
   ?
   
    ,
   
   .

   ,
    ,
  
   .
  ,
   ,
  ,
   .

   
  
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
#define bs 1000000009
#define bsize 256

using namespace std;

long n,a,b;
map<pair<long, long> ,long> have;
vector<long> x[200000],y[200000];
long ans;
long p1,p2,pos[200000];

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
 x[a].push_back(b);
 y[b].push_back(a);
 have[make_pair(a,b)]=1;
}
for (int i=0;i<=100000;i++)
sort(x[i].begin(),x[i].end()),sort(y[i].begin(),y[i].end());

for (int tx=0;tx<=100000;tx++)
{
 for (int i=0;i<x[tx].size();i++)
 {
  long ty=x[tx][i];
  p1=i+1;
  p2=pos[ty]+1;
  while (p1<x[tx].size()&&p2<y[ty].size())
  {
   if (x[tx][p1]-ty==y[ty][p2]-tx&&have[make_pair(y[ty][p2],x[tx][p1])]==1)++ans;
   if (x[tx][p1]-ty<y[ty][p2]-tx)++p1;
   else ++p2;
  }
  ++pos[ty];
 }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}