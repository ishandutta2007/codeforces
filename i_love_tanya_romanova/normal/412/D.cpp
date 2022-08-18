/*
When I stand before you shining
In the early morning Sun
When I feel the engines roar
And I think of what we've done

Oh the bittersweet reflection
As we kiss the earth goodbye
As the waves and echoes of the
Towns become the ghosts of time

Over borders that divide the
Earthbound tribes
No creed and no religion
Just a hundred winged souls

We will ride this thunderbird
Silver shadows on the earth
A thousand leagues away
Our land of birth

To Albion's land
Coming home
When I see the runway lights
In the misty dawn
The night is fading fast

Coming home far away
As the vapor trails alight
Where I've been tonight
You know I will not stay

Curving on the edge of daylight
Till it slips into the void
Waited in the long night dreaming
Till the Sun is born again

Stretch the fingers of my hand
Cover countries with my span
Just a lonely satellite
A speck of dust in cosmic sand

Over borders that divide the
Earthbound tribes
Flown the dark Atlantic
Over mariners' stormy graves

We will ride this thunderbird
Silver shadows on the earth
A thousand leagues away
Our land of birth

To Albion's land
Coming home
When I see the runway lights
In the misty dawn
The night is fading fast

Coming home far away
As the vapor trails alight
Where I've been tonight
You know I will not stay

To Albion's land
Coming home
When I see the runway lights
In the misty dawn
The night is fading fast

Coming home far away
As the vapor trails alight
Where I've been tonight
You know I will not stay

Coming home far away
When I see the runway lights
In the misty dawn
The night is fading fast

Coming home far away
As the vapor trails alight
Where I've been tonight
You know I will not stay
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

long n,m,a,b;
vector<long> g[200000];
long arp[200000];
vector<long> ans;

void dfs (long v)
{
 arp[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (arp[q])continue;
  dfs(q);
 }
 ans.push_back(v);
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
}
for (int i=1;i<=n;i++)
if (arp[i]==0){
               dfs(i);
               }
for (int i=0;i<ans.size();i++)
{
 if (i)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}