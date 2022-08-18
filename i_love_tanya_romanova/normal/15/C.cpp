/*
My mind is razor-sharp
And Im wild-cat-mean
Id like to shred your face
A danger to you
When I feel the urge
Deep down inside
I lose my human touch
Im like a killing machine
I want to resist - but I cant hold
it back
The beast is unleashed - its got
to attack
Again and again the force is too
strong
Its breaching the chains
Ive got the beast inside
Dont you trust in me
Ive got the beast inside
Craving a victim - its telling me
to kill
I look through evil eyes
Prowling in the streets
In the dead of night
Im a man on the hunt
I know my soul is under siege
Cant somebody stop me now
Rcause Im losing control
Ive got the beast inside
Dont you trust in me
I know it must have been
the beast inside
Its driving me to kill
Its gotta be the beast - the beast
- the beast
The beast - the beast - the beast
- deep down inside
But when the deed is done
And the pain is gone
I feel renewed within
Until the voices return
The beast - the beast - the beast
The beast - the beast - the beast
My mind is razor-sharp
And Im wild-cat-mean
Id like to shred your face
Ive told you before
When I feel the urge
Deep down inside
I lose my human touch
Im just a killing machine
I want to resist -
but I cant hold it back
The beast is unleashed -
its got to attack
Again and again the force is too strong
Its breaching the chains
Its gotta be the beast inside
Never ever trust in me
I know there is a beast inside
Inside in all of us
I feel Ive got the beast inside
Im screaming for help from this
monster within
The beast inside - take a look in
the mirror - its staring at you
Even at you - the beast inside
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

using namespace std;

long long tests,l,r,s;

long long solve(long long x)
{
 if (x%4==0)return x;
 if (x%4==1)return 1;
 if (x%4==2)return x+1;
 return 0;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
 cin>>l>>r;
 r=l+r-1;
 s^=solve(r);
 s^=solve(l-1);
}
if (s)cout<<"tolik"<<endl;
else cout<<"bolik"<<endl;

cin.get();cin.get();
return 0;}