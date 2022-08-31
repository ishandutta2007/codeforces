/*
Hiding again behind your wall
Decay decline a downfall
A failure forgotten out of time
Collapse so long ago

Drifting on
Lost on the way
A past beyond memory

Gone past the point of no return
Lead to a place so far gone
The dark embraces all your fears
Someday you'll rise again

Drifting on
Lost on the way
A past beyond memory

Drifting on
Lost the way
A past beyond memory
Minutes seems to pass away
Lost upon my way
A past beyond memory
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
 
 long n,k,x,ar[2000];
 vector<long> v;
 long ans;
 
 long solve()
 {
  long ans=0;
  while (true)
  {
   long cp=-1;
   for (int i=0;i+2<v.size();i++)
    if (v[i]==v[i+1]&&v[i+1]==v[i+2]&&cp==-1)cp=i;
   if (cp==-1)return ans;
   long q=v[cp];
   while (v.size()>cp&&v[cp]==q){++ans;v.erase(v.begin()+cp);}
  }
  return ans;
 }
 
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>n>>k>>x;
for (int i=1;i<=n;i++)
cin>>ar[i];
for (int cp=0;cp<=n;cp++)
{
 v.clear();
 for (int i=1;i<=cp;i++)
 v.push_back(ar[i]);
 v.push_back(x);
 for (int i=cp+1;i<=n;i++)
  v.push_back(ar[i]);
 ans=max(ans,solve());
}
if (ans>0)--ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}