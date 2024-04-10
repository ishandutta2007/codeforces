/*
I saw the mountain crumble down
I saw colossus in flames.
I heard the ocean draining
Nothing that I could ever tame.

Off with my head, come down the line
I have the right to deicide.
I'll bring this light, as is the sky
Altered minds they criticize.

Unrest within your flesh
How can we stop this pollution?

Altering trouble, you cannot fix
Envy of others never makes me rich.
All my heroes, they're all dead
As I remain here inside my

We have heard the chimes at midnight.
Into the void I go.
Will I ever see your face again
Or will black be all I know

Arriving inside
Our hearts alive

And the darkness here is grim
But it found us, surrounded.
Lead me deep into the canyon
You put your guidance in the wrong hands.

Feet ungrounded, giving your best
Now take your gold into silence.
You take a stand, bracing yourself
For this cold is never ending.

We have heard the chimes at midnight.
Into the void I go.
Will I ever see your face again
Or will black be all I know

Arriving inside
Our hearts alive
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

long p,n,ans,q,used[1000];

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>p>>n;
ans=-1;
for (int i=1;i<=n;i++)
{
 cin>>q;
 if (used[q%p])
  if (ans<0)ans=i;
 used[q%p]=1;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}