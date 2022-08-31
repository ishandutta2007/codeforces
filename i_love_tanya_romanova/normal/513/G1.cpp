/*
At dawn envoy arrives, morning of October 28th
No day proven by deed, descendants of Sparta, Athens and Crete
Look north, ready to fight, enemies charge from the hills
True arms facing defeat, there's no surrender, there's no retreat

Time after time, force their enemies back to the line

Call to arms, banners fly in the wind
For the glory of Hellas
Coat of arms reading Freedom or Death
Blood of King Leonidas

Air raid pounding the land, bombers are flying both day and night
Endure 6 days of rain dropped by invaders, bomb raid in vain
Strike hard, the tables have turned, drive them back over the hills
At arms just like before, soldiers, civilians, Hellas at war

By their own hand, forced their enemy out of their land

Call to arms, banners fly in the wind
For the glory of Hellas
Coat of arms reading Freedom or Death
Blood of King Leonidas

Just like their ancestors ages ago
Fought in the face of defeat
Those 300 men left a pride to uphold
Freedom or death in effect

Then, now again, blood of heroes saving their land

Call to arms, banners fly in the wind
For the glory of Hellas
Coat of arms reading Freedom or Death
Blood of King Leonidas

Call to arms, banners fly in the wind
For the glory of Hellas
Coat of arms reading Freedom or Death
Blood of King Leonidas
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

long n,k;
vector<long> v;
map<vector<long> ,long> mapp;
vector<vector<long> > vert;
long id;
double ways[1000][1000];
long q;
double dp[1000][1000];
double ans;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;

for (int i=1;i<=n;i++)
{
 v.push_back(i);
}

do
{
 vert.push_back(v);
 mapp[v]=vert.size()-1;
}
while (next_permutation(v.begin(),v.end()));

for (int i=0;i<vert.size();i++)
{
 for (int l=0;l<n;l++)
  for (int r=l;r<n;r++)
  {
   vector<long> v=vert[i];
   reverse(v.begin()+l,v.begin()+r+1);
   id=mapp[v];
   ways[i][id]++;
  }
}

v.clear();
for (int i=1;i<=n;i++)
{
 cin>>q;
 v.push_back(q);
}
dp[0][mapp[v]]=1;
/*
for (int i=0;i<vert.size();i++){
 for (int j=0;j<vert.size();j++)
  cout<<ways[i][j]<<" ";
  cout<<endl;}*/
for (int i=0;i<k;i++)
 for (int j=0;j<vert.size();j++)
  for (int q=0;q<vert.size();q++)
   dp[i+1][q]+=dp[i][j]*ways[j][q];

for (int i=0;i<vert.size();i++)
{
 for (int j=0;j<vert[i].size();j++)
  for (int q=j+1;q<vert[j].size();q++)
  {
   ans+=dp[k][i]*(vert[i][j]>vert[i][q]);
  }
}

for (int i=0;i<k;i++)
 ans/=(n*(n+1)/2);
 
 cout.precision(10);
cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}