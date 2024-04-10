/*
Sodom precise, burn the man
A promise of scorching
We hold a torch to the sun
Flame to the surface
We hold a torch to the sun
Flame to the surface

Cruddy crud epidermis
Skin melt fashion
Burning man passion
Seek a sense of shelter
Within an oasis of deprivated clowns
We'll take a trip through the devil's heat
Heat

Meander through the meadowless fields
Carnival bizarre
Black rock dryness
Lures chaos mongers
Banishment of all that is taught
Complete flesh rot

Agonized, the smoldering circus
Summon the desert deity
"Take these and feel us"
Psychedelia, hallucinate

Sift the embers
You'll find me
Buried alive
With drums of thunder
Solar god arise

He'll rise, arise
He'll rise, arise
He'll rise, arise
He's risen

Bow down, hands raised
Blistered, half crazed
Drifting alone
Ignite my soul
Reborn to be
A perpetual
Flame to the surface
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
#define rmost agasdgasdg

using namespace std;

long long n,ar[500000],ans;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
 cin>>ar[i];

sort(ar,ar+n);
for (int i=0;i<n;i++)
{
 ans+=1ll*ar[i]*(i+1);
 if (i!=n-1)ans+=ar[i];
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}