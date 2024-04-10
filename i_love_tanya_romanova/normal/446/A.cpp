/*
Sentenced to work a dead end 9 to 5
Trapped in a dingy corporate cubicle hell
Then go to work in the darkness on the midnight shift
Any chance you get, selling gas at the corner Shell

Three letters groups listening in on you
Under surveillance courtesy of Big Brother in your car
Drones monitor each and every move you make
It doesn't matter who you know or who you think you are

You'll never see a ray of daylight
So far in debt you're struggling to survive
But you will break your back fighting and they'll help
Before you let them break your pride

"Powers that be" will never win; a storm is coming, get ready
You better learn to dance in the rain, instead of wait for the sun
Learn to dance in the rain, the sun will never come

Down on your luck, you had your hand out once or twice
But all you wanted was just a hand, they say
"You have the right to remain silent", so shut your mouth
Don't mention the broken promises and lies of hope and change

"Powers that be" will never win; a storm is coming, get ready
You better learn to dance in the rain, instead of wait for the sun
Learn to dance in the rain, the sun will never come

Never come, dance in the rain, it ain't gonna come

Enslave and impoverish the middle class
Make them dependent then strip it all away
Al-CIA-da, destruction, and democide
Addiction, corruption, every word's a lie

Races, classes, sexes, religious wars
Destroy the family, and what love is for

The Fed and the Bankers own all the politicians
May I introduce you to the sons of perdition?
Replace the dictators Washington appointed
The Devil Messiahs and the dangerously disappointed

They lie to themselves, pleased with what they've done
Soon they all will be repaid and there's nowhere to run
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

long n,l[200000],r[200000],ar[200000],ans;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int i=1;i<=n;i++)
{
 l[i]=l[i-1]+1;
 if (ar[i]<=ar[i-1])l[i]=1;
}

for (int i=n;i;--i)
{
 r[i]=r[i+1]+1;
 if (ar[i]>=ar[i+1])r[i]=1;
}

for (int i=1;i<=n;i++)
 ans=max(ans,l[i]);
for (int i=1;i<=n;i++)
 ans=max(ans,r[i]);

for (int i=1;i<=n;i++)
 ans=max(ans,l[i-1]+1);
for (int i=1;i<=n;i++)
 ans=max(ans,r[i+1]+1);
/*
for (int i=1;i<=n;i++)
 cout<<l[i]<<" ";
 cout<<endl;
for (int i=1;i<=n;i++)
 cout<<r[i]<<" ";
 cout<<endl;
 */
  
for (int i=2;i<n;i++)
{
 if (ar[i-1]+1<ar[i+1])
 ans=max(ans,l[i-1]+r[i+1]+1);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}