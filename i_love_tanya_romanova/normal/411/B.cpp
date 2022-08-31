/*
Pulled into war to serve a vision
That's supposed to last a thousand years
Part of a machine unstoppable
As merciless as tidal waves

Were they the victims of the time
Or proud parts of lager goals?
Propaganda of the Reich masterful machine

Time and again the battle rages on
Beyond the gates of misery
As casualties rise and millions die around them
Did they see it all?

Crazy mademen on a leash
Or young men who lost their way?
Grand illusions of the Reich
May seem real at times

Panzers on a line
Form the Wehrmacht's spine
Lethal grand design
What about the men executing orders?

Ad victoriam
Ex machina
Non sibi sed patriae [x2]

Pulled into war to serve a vision
That just didn't last a thousand years
Part of a machine
Though stoppable as merciless as tidal waves

Crazy mademen on a leash
Or young men who lost their way?
Grand illusions of the Reich
May seem real at times

Panzers on a line
Form the Wehrmacht's spine
Lethal grand design
What about the men executing orders?
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

long n,m,k,ttl[200000],ar[200][200],bad[200];
long er[2000];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=1000;i++)
 er[i]=1e9;
 
cin>>n>>m>>k;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
cin>>ar[j][i];

for (long i=1;i<=m;i++)
{
 for (int j=1;j<=k;j++)
  ttl[j]=0; 
 for (int j=1;j<=n;j++)
 {
//  cin>>ar[i][j]; 
 if (er[j]>1e7)
  ttl[ar[i][j]]++;
 }
 for (int j=1;j<=k;j++)
  if (ttl[j]>1)bad[j]=1;
 for (long j=1;j<=n;j++)
 {
  if (bad[ar[i][j]])er[j]=min(er[j],i);
 }
}
for (int i=1;i<=n;i++)
 if (er[i]>1e6)er[i]=0;
 
for (int i=1;i<=n;i++)
 cout<<er[i]<<endl;
 
cin.get();cin.get();
return 0;}