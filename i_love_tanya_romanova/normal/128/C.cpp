/*
Fifteen years in the academy
He was like no cadet they'd ever seen
A man so hard, his veins bleed ice
And when he speaks he never says it twice

They call him Judge, his last name is Dredd
So break the law, and you wind up dead
Truth and justice are what he's fightin' for
Judge Dredd the man, he is the law
Drokk it

With gun and bike he rules the streets
And every perp he meets will taste defeat
Not even death can overcome his might
'Cause Dredd and Anderson, they won the fight

When the Sov's started the apocalypse war
Mega-City was bombed to the floor
Dredd resisted, and the judges fought back
Crushed the sov's with their counter-attack
Drokk it

Respect the badge
He earned it with his blood
Fear the gun
Your sentence may be death because

(I am the law)
And you won't fuck around no more
(I am the law)
I judge the rich, I judge the poor
(I am the law)
Commit a crime, I'll lock the door
(I am the law)
Because in Mega-City
(I am the law)

In the cursed earth where mutants dwell
There is no law, just a livin' hell
Anarchy and chaos as the blood runs red
But this would change if it was up to Dredd

The book of law is the Bible to him
And any crime committed is a sin
He keeps the peace with his law-giver
Judge, jury, and executioner

Respect the badge
He earned it with his blood
Fear the gun
Your sentence may be death because

(I am the law)
And you won't fuck around no more
(I am the law)
I judge the rich, I judge the poor
(I am the law)
Commit a crime, I'll lock the door
(I am the law)
Because in Mega-City
(I am the law)

Crime, the ultimate sin
Your I.S.O., cube is waitin' when he brings you in
Law, it's what he stands for
Crime's his only enemy and he's goin' to war

Crime, the ultimate sin
Your I.S.O., cube is waitin' when he brings you in
Law, it's what he stands for
Crime's his only enemy and he's goin' to war

Respect the badge
He earned it with his blood
Fear the gun
Your sentence may be death because

(I am the law)
And you won't fuck around no more
(I am the law)
I judge the rich, I judge the poor
(I am the law)
Commit a crime, I'll lock the door
(I am the law)
Because in Mega-City

(I am the law)
And you won't fuck around no more
(I am the law)
I judge the rich, I judge the poor
(I am the law)
Commit a crime I'll lock the door
(I am the law)
Because in Mega-City
(I am the law)
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

using namespace std;

long long c[2200][2200],n,m,k,res;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;

for (int i=0;i<=2000;i++) 
 for (int j=0;j<=i;j++)
  if (j==0||j==i)
   c[i][j]=1;
   else c[i][j]=
   (c[i-1][j]+c[i-1][j-1])%bs;

res=c[n-1][2*k]*c[m-1][2*k];
res%=bs;
cout<<res<<endl;

cin.get();cin.get();
return 0;}