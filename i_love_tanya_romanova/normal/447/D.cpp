/*
While I lie here burning, you're encased in ice
With tainted eyes upon your tainted soul
It's no wonder I'm so cold
A terrible thing I'm learning as tears are turned to ice
These four walls will be my dreaded foes
As I rot here in this hole

Do you conspire to hold me down?
Do you conspire to hold?
Do you conspire to hold me down?
Have I wasted a dream?

Restless seas will murder me tonight
As you appease effortlessly the open mouths of hungry thieves
There'll be no silent empathy inside
No colour or shades of hope
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long n,m,ar[1100][1100];
long si[12000],sj[120000];
multiset<long long> sett;
multiset<long long>::iterator it;
long long k,p;
vector<long long> v1,v2;
long long s1[1200000],s2[1200000];
long long val,ans;
long bst;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k>>p;
for (int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
{  cin>>ar[i][j];
si[i]+=ar[i][j];
 sj[j]+=ar[i][j];}

for (int i=1;i<=1000000;i++)
{
 bst=1;
 for (int j=1;j<=n;j++)
  if (si[j]>si[bst])bst=j;
 v1.push_back(si[bst]);
 si[bst]-=p*m;
}

for (int i=1;i<=1000000;i++)
{
 bst=1;
 for (int j=1;j<=m;j++)
  if (sj[j]>sj[bst])bst=j;
 v2.push_back(sj[bst]);
 sj[bst]-=p*n;
}

for (int i=1;i<=1000000;i++)
s1[i]=s1[i-1]+v1[i-1],
s2[i]=s2[i-1]+v2[i-1];

ans=-1e18;

for (int i=0;i<=k;i++)
 ans=max(ans,s1[i]+s2[k-i]-1ll*p*i*(k-i));

cout<<ans<<endl;

cin.get();cin.get();
return 0;}