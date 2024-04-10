/*
Am I mentally weak?
as the masses, acting like rats
And now killing eachother
and it feels like they deserve it
Denied all the lies so far
begging for the fall
The smiling plague that we are
don't think it doesn't suite you, just follow...

And now they all walk through the flames
and still they follow them blindly

Let's give in to the madness
as so many times before
History repeats itself
what a happy ending
Denied all the lies so far
begging for the fall
The smiling plague that we are
don't think it doesn't suite you, just follow...
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
 
 long n,a,b,ar1[200000],ar2[200000];
 vector<long> g[200000];
 vector<long> ans;
 long used[200000];
 
void solve (long v,long cur, long prev)
{
 used[v]=1;
 long temp=ar1[v];
 temp^=cur;
 if (temp!=ar2[v])
 {
  ans.push_back(v);
  cur^=1;
 }
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
   solve(q,prev,cur);
 }
}
 
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>n;
for (int i=1;i<n;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);   
}
for (int i=1;i<=n;i++)
cin>>ar1[i];
for (int i=1;i<=n;i++)
cin>>ar2[i];
solve(1,0,0);

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
cout<<ans[i]<<endl;

cin.get();cin.get();
return 0;}