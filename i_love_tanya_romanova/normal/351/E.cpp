/*
I saw you
Inside yeah
My darkness
Alive
You don't sleep 
You don't cry
You don't smile unless someone dies
Wanna see thr horns rise up and down
Wanna creepy-crawl across your town
Wanna see the shadows come to life

You don't dream
You don't feel
You don't fear what lies underneath
Wanna see the horns rise up and down
Wanna creepy crawl across your town
Wanna send a chill into the night
Wanna see the shadows come to life
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,ar[4000],s,ans;
vector<long> v;
long tans,bmask;

void showw(long mask)
{
 for (int i=0;i<14;i++)
 if (mask&(1<<i)){ar[i+1]=-ar[i+1];cout<<1;}else cout<<0;
}
int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
/*
for (int iter=1;iter<=1000;iter++)
{
 v.clear();
 for (int i=1;i<=14;i++)
 v.push_back(i);
 random_shuffle(v.begin(),v.end());
 for (int i=1;i<=14;i++)
 ar[i]=v[i-1];
 
n=14;
s=0;
for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
  if (ar[j]<ar[i])++s;

ans=s;

for (int cp=1;cp<=n;cp++)
{
 for (int i=1;i<cp;i++)
 if (ar[i]<=ar[cp]&&ar[i]>-ar[cp])++s;
 for (int i=cp+1;i<=n;i++)
 {
     if (ar[i]<ar[cp]&&ar[i]>=-ar[cp])--s;
 }
 ar[cp]=-ar[cp];
 ans=min(ans,s);
}
*/
cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
for (int i=1;i<=n;i++)
ar[i]=abs(ar[i]);
ans=10000000;
for (int cp=1;cp<=n;cp++)
{
 long 
 tdif=0;for (int i=1;i<cp;i++)
 if (ar[i]<=ar[cp]&&ar[i]>-ar[cp])++tdif;
 for (int i=cp+1;i<=n;i++)
 {
     if (ar[i]<ar[cp]&&ar[i]>=-ar[cp])--tdif;
 }
 if (tdif<0)ar[cp]=-ar[cp];
}

s=0;
for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
  if (ar[j]<ar[i])++s;
if (s<ans)ans=s;
cout<<ans<<endl;
//cout<<ans<<endl;
/*
tans=1000000;
bmask=0;
for (int mask=0;mask<(1<<14);++mask)
{
    for (int i=0;i<14;i++)
    ar[i+1]=abs(ar[i+1]);
    for (int i=0;i<14;i++)
    if (mask&(1<<i))ar[i+1]=-ar[i+1];
    s=0;
    for (int j=1;j<=14;j++)
     for (int q=j+1;q<=14;q++) if (ar[q]<ar[j])++s;
     if (s<tans){tans=s;bmask=mask;}
}
for (int i=1;i<=n;i++)
ar[i]=abs(ar[i]);
if (tans!=ans)
{cout<<tans<<" "<<ans<<endl;
showw(bmask);cout<<endl;//cin.get();
for (int i=1;i<=n;i++)
cout<<ar[i]<<" ";
cout<<endl;cin.get();
}}
//cout<<ans<<endl;
*/
cin.get();cin.get();
return 0;}