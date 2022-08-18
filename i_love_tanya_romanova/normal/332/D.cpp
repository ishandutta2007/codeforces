/*  
In a time of chaos.
Ruined dreams. A wasted land.
Cities of pipe and steel. Gone now,
swept away.

Thundering machines has stopped
Nothing could stem the avalanche.

The whole world crumble. Cities exploded.
A firestorm of fear.
Men feeding on men. Fear is an ally.
Living to Survive.

Thundering machines has stopped
Nothing could stem the avalanche.

Dawn of the decadence
The Dead shall take the Earth
Hear the screams of this grave new world
After Nuclear Devastation!

Horizon is a big explosion. No flash of light
Can pass eternal darkness
Unleashed dogs of war
Living off the corpse of the old world.

On the roads it is a white line nightmare.
A maelstrom of decay
Only those brutal enough to pillage will survive.
The gangs took over the highways,
Ready to wage war.
Ordinary men are battered and smashed with no mercy
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,k,q,deg[3000];

long double c[2100][2100];
long double edsum[2100];
long double add,avedge,subs;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=0;i<=2000;i++)
for (int j=0;j<=2000;j++)
if (j==0||j==i)
c[i][j]=1;
else c[i][j]=c[i-1][j-1]+c[i-1][j];


cin>>n>>k;
for (int i=1;i<=n;i++)
for (int j=i+1;j<=n;j++)
{
    cin>>q;
    if (q==-1)continue;
    deg[i]++;
    deg[j]++;
    edsum[i]+=q;
    edsum[j]+=q;
}

for (int i=1;i<=n;i++)
{
 if (deg[i]<k)continue;
 
 avedge=edsum[i]/deg[i];
 add+=c[deg[i]][k]*avedge;
 subs+=c[deg[i]][k];
}
long long res=add/subs*k+0.0005;
cout<<res<<endl;

cin.get();cin.get();
return 0;}