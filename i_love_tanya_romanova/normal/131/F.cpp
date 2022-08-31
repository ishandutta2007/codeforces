/*
There is a voice without a sound
I'm sure that killers are all around
United fools bewitched by words
These weapons take control

Unjustifiable vindication
Irreparable devastation
Now the seals forever broken
Captured all the miseries
So take my hand I'll be your guide
Bloodstains on the desert ground
One the battlefield of wrath
Who starts the war machine?

Face the fact
The final act
I wanna set your spirit free
Take this pain
Buried by hate
Disguise the evil
Lay down the law

I crawl into your tortured brain
Can't reciprocate your humanity
There is no escape from religious states
No final heal for mordancy

You never will release the wrath
Forever locked behind the walls
I'll leave you where you need to go
Awake the beast under the snow
An endless nightmare can't you see
That buried all humanity
You cannot fight the enemy
Who starts the war machine?

Face the fact
The final act
I wanna set your spirit free
Take this pain
Buried by hate
Disguise the evil
Lay down the law

There is a voice without a sound
I'm sure that killers are all around
United fools bewitched by words
These weapons take control

Unjustifiable vindication
Irreparable devastation
Now the seals forever broken
Captured all the miseries
So take my hand I'll be your guide
Bloodstains on the desert ground
One the battlefield of wrath
Who starts the war machine?

Face the fact
The final act
I wanna set your spirit free
Take this pain
Buried by hate
Disguise the evil
Lay down the law

Retribution
Decadence
Provocation
Ignorance
Machination
Demise
Isolation
Suicide
Lay down the law
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

long n,m,need,s[666][666];long zr[666][666];
string st;
long l;
long long ans;

long gett(long x1,long y1,long x2,long y2)
{
 return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
 
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>need;

for(int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=m;j++)
  zr[i][j]=st[j-1]-48;
}

for(int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(zr[i][j]*zr[i-1][j]*zr[i+1][j]*zr[i][j-1]*zr[i][j+1]==1);

for (int upr=1;upr<=n;upr++)
{
 for (int lwr=upr;lwr<=n;lwr++)
 {
  l=1;
  for (int r=1;r<=m;r++){
  while (gett(upr+1,l+1,lwr-1,r-1)>=need)++l;ans+=l-1;}
 }
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}