/*
A chill went through my spine
Something had changed
A steep passage appeared
A reoccurring event
That no one could prevent
Internally burning
No one could understand
The way things were turning
Man made experiment
To punish all and none
Selfinflicted suffering
A selective device
That ensures our demise
Internally bleeding
Falling apart
A reaper with no regrets
A soulless entity
Kissed by the angel of death
A soulless entity
A silent world
That brings out the voices within
The unsolved enigma
Out of control
Internally burning
No one could understand
Internally bleeding
Falling apart
A reaper with no regrets
A soulless entity
Kissed by the angel of death
A soulless entity
Crimson touch of the plague
Plague angel
Crimson touch of the plague
Plague angel
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,k,ar[1<<20],mx,mn;
vector<pair<long, long> > ans;

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int iter=1;iter<=k;iter++)
{
 mn=mx=1;
 for (int i=1;i<=n;i++)
 {
     if (ar[i]>ar[mx])mx=i;
     if (ar[i]<ar[mn])mn=i;
 }
 if (ar[mx]==ar[mn])break;
 ar[mx]--;
 ar[mn]++;
 ans.push_back(make_pair(mx,mn));
}
mn=mx=1;
 for (int i=1;i<=n;i++)
 {
     if (ar[i]>ar[mx])mx=i;
     if (ar[i]<ar[mn])mn=i;
 }
 cout<<ar[mx]-ar[mn]<<" "<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
 
cin.get();cin.get();
return 0;}