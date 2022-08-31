/*
Wings of fire burn the night
Slumbering eyes their flares shall greet
Let the past cling on its futile self
And may the present rush for the future's glare

Grave to cradle
Cradle to grave
So infinity clash
Grave to cradle
Cradle to grave
In twofold matter

Two forces gone full circle
Never shall one of the other grow fond
Join me, the time is upon us
He spoke and in fury we flew

Far beyond the limits of time
Disown the borders of life itself
Crafted and moulded all in one form
Split up and scattered in the world that we own

Grow towards me
Beknight the strength of the symbiosis
Backwards striving
Counterparts with different eyes have observed
Of time unconditional

Grave to cradle
Cradle to grave
So infinity clash
Grave to cradle
Cradle to grave
In twofold matter

Tell of days to come
Tomorrow remembered
Your yesterday, my future

Recollection of the day
Delusions cast where dead trees sway

The sabre that separates
Is the candle that burns both ends

Born from death you now confront me
Back to death with my life I take you
Die more with each movement of mine
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

long n,ar[200000],ps,ans;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

ps=1;
while (ps+1<=n&&ar[ps]<=ar[ps+1])++ps;

if (ps==n)
cout<<0<<endl;
else
{
 ++ps;
 ar[n+1]=ar[1];
 while (ps+1<=n+1&&ar[ps]<=ar[ps+1])++ans,++ps;
 if (ps<=n)cout<<-1<<endl;
 else cout<<ans<<endl;
}
cin.get();cin.get();
return 0;}