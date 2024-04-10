/*
  ,    '  ?
      .
      ,
 ,    .

  
    
   .
  
     
  ,
   ...

       
      
   -      
 ,     .

  
    
   .
  
     
  ,
   ...
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n,m,t[1<<18],x[1<<18],cur,ans[1<<18];
vector<pair<long, long> > vec;
long ps,calc;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=0;i<n;i++)
 cin>>t[i]>>x[i];

cur=0;

for (int i=0;i<n;)
{
 vec.clear();
 for (int j=i;j<n;j++)
 {
  if (vec.size()==m)break;
  vec.push_back(make_pair(x[j],j));
 }
 cur=max(cur,t[i+vec.size()-1]);
 sort(vec.begin(),vec.end());
 
 ps=0;
 calc=0;
 for (int j=0;j<vec.size();j++)
 {
  cur+=vec[j].first-ps;
  if(j>0&&vec[j].first==vec[j-1].first)++calc;
  else if (j==0)++calc;
  else {cur+=1+calc/2;calc=1;}
  ans[vec[j].second]=cur;
  ps=vec[j].first;
 }
// cout<<cur<<endl;
 cur+=1+calc/2;
 cur+=vec[vec.size()-1].first;
 i+=vec.size();
}
for (int i=0;i<n;i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}