/*
Into the motherland
The German army march

In the Soviet Union summer 1943
Tanks line up in thousands as far the eye can see
Ready for the onslaught
Ready for the fight
Waiting for the axis to march into the trap
Mines are placed in darkness
In the cover of the night
Waiting to be triggered
When the time is right
Imminent invasion, imminent attack

Once the battle started
There's no turning back

The end of the third Reich draws near
It's time has come to an end
The end of an era is here
It's time to attack!

[Chorus:]
Into the motherland the German army march
Comrades stand side by side to stop the Nazi charge
Panzers on Russian soil a thunder in the east
One million men at war
Soviet wrath unleashed!

Fields of Prokhorovka
Where the heat of battle burned
Suffered heavy losses
And the tide of war was turned
Driving back the Germans
Fighting on four fronts
Hunt them out of Russia
Out of Soviet land
Reinforce the front line
Force the axis to retreat
Send in all the reserves
Securing their defeat
Soldiers of the Union
Broke the citadel
Ruins of an army
Axis rest in hell

The end of the third Reich draws near
Its time has come to an end
The end of an era is here
Its time to attack

[Chorus]

Onward comrades! Onwards for the Soviet Union! Charge!

Ow mother Russia!
Union of lands
Will of the people
Strong in command
Ow mother Russia!
Union of lands
Once more victorious the red army stands!

The end of the third Reich is here
Its time has come to an end
The end of an era is here
Its time to attack!

[Chorus]
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

long n,a,calc1[1000],calc2[200];
long ans;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a;
 calc1[a]++;
 cin>>a;
 calc2[a]++;
}
ans=min(n-calc1[0],calc1[0])+min(n-calc2[0],calc2[0]);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}