/*
You were born, your brother's keeper
Why can I see blood on your hands?
You became your brother's slayer
Embrace again in death

At the end of all this hatred lies even deeper hate
Their darkness has defeated you
Your lifeline running backwards

Remember sins of our fathers
A requiem for the countless dead
Blood is on your hands, the wages of sin

Future's eyes closing now
Soul eclipse taking place
Laments rise, tears of the dead
From the other side of the grave

You were born your brothers keeper
Why can I see blood on your hands?
Their darkness has defeated you
Your lifeline running backwards

Remember sins of our fathers
A requiem for the countless dead
Blood is on your hands, the wages of sin

Future's eyes closing now
Soul eclipse taking place
Laments rise, tears of the dead
From the other side of the grave
From the other side of the grave

Blood is on your hands
The wages of sin
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
#define nice dhhssgsggsgsgs

using namespace std;

long long n,m,b,x[20000],k[20000],mm[200000],mask[20000],q;
vector<pair<long long, pair<long long, long long> > > v;
long long dp[1<<20];
long long ans,cst,tmask;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m>>b;
for (int i=0;i<n;i++)
{
    cin>>x[i]>>k[i]>>mm[i];
    for (int j=0;j<mm[i];j++)
    {
     cin>>q;
     --q;
     mask[i]|=(1<<q);
    }
    v.push_back(make_pair(k[i],make_pair(x[i],mask[i])));
}

sort(v.begin(),v.end());

for (int i=0;i<(1<<m);i++)
dp[i]=5e18;

dp[0]=0;
ans=5e18;

for (int i=0;i<v.size();i++)
{
 cst=v[i].second.first;
 tmask=v[i].second.second;
 for (int j=0;j<(1<<m);j++)
 {
  if (dp[j]>3e18)continue;
  dp[j|tmask]=min(dp[j|tmask],dp[j]+cst);
 }   
 ans=min(ans,dp[(1<<m)-1]+v[i].first*b);
}
if (ans>4e18)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}