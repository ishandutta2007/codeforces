/*
Fast as the wind, the invasion has begun
Shaking the ground with the force of thousand guns
First in the line of fire, first into hostile land
Tanks leading the way, leading the way
Charging the lines with the force of a furious storm
Fast as the lighting phantoms swarm
200 miles at nightfall, taken within a day
Thus earning their name, earning the fame
They are the panzer elite, born to compete, never retreat (ghost division)
Living or dead, always ahead, fed by your dread
Always ahead, as the blitzkrieg rages on
Breaking morale the with the sound of blazing guns
First in the line of fire, first into hostile land
Tanks leading the way, leading the way
Living a trail of destruction to a foreign land
(Waging war with conviction)
Massive assault made to serve the Nazi plan
(Wehrmacht's pride, ghost division)
Communication's broken, phantom's are far away
Thus earning their name, earning the fame
They are the panzer elite, born to compete, never retreat (ghost division)
Living or dead, always ahead, fed by your dread
Pushing the frontline forth with a tremendous force
(Far ahead, breaks resistance)
Reaching the way for panzer corps
(Shows no fear, self-subsistent)
First in the line of fire, first into hostile land
Tanks leading the way, claiming the fame
They are the panzer elite, born to compete, never retreat (ghost division)
Living or dead, always ahead, fed by your dread
Panzer elite, born to compete, never retreat (ghost division)
Living or dead, always ahead, fed by your dread
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
#define MAG 10000

using namespace std;

long n;
vector<long> v;
long temp;
vector<vector<long> > ans;

long bt;
long eval(vector<long> v)
{
 long res=0;
 long mn;
 for (int i=0;i<v.size();i++)
 {
  mn=v[i];
  for (int j=i;j<v.size();j++)
  {
   mn=min(mn,v[j]);
   res+=mn;
  }
 }
 return res;
}

long m;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 v.push_back(i);

do
{
 temp=eval(v);
 if (temp>bt)
 {
  ans.clear();
  ans.push_back(v);
  bt=temp;
 }
 else
 if (temp==bt)
  ans.push_back(v);
}
while (next_permutation(v.begin(),v.end()));

for (int i=m-1;i<m;i++)
{
 for (int j=0;j<ans[i].size();j++)
  cout<<ans[i][j]<<" ";
 cout<<endl;
}

cin.get();cin.get();
return 0;}