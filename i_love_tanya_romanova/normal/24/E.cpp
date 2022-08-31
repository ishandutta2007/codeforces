/*
Mama, they try and break me

The window burns
To light the way back home
A light that warms
No matter where they've gone now

They're off to find
The hero of the day
Oh, but what if they should fall
By someone's wicked way

Still the window burns, time so slowly turns
And someone there is sighin'
Keepers of the flames, do you feel your names?
Can't you hear your baby's crying?

Mama, they try and break me
Still they try and break me

S'cuse me
While I tend to how I feel
These things return to me
That still seem real

Now deservingly
This easy chair
But the rocking stopped
By wheels of despair, yeah

Don't want your aid but the fist I've made
For years, won't hold or feel
No, I'm not all me, so please excuse me
While I tend to how I feel

But now the dreams and waking screams
That ever last the night
So build a wall, behind it crawl
And hide until it's light
So can't you hear your baby's crying now?

Still the window burns, time so slowly turns
Someone there is sighin'
Keepers of the flames, can't you hear your names?
Can't you hear your baby's crying?

But now the dreams and waking screams
That everlast the night
So build a wall, behind it crawl
And hide until it's light
So can't hear your baby's crying now?

Mama, they try and break me
Mama, they try and break me
Mama, they try and break me
Mama, they try, mama, they try

Mama, they try and break me
Mama, they try and break me
Mama, they try and break me
Mama, they try, mama, they try
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n,x[600000],y[600000];
double l,r,mid;
long ri,le;
long v[600000];
double mr,tx;

bool solve(double t)
{
 mr=-1e18;
 for (int i=1;i<=n;i++)
 {
  if (v[i]<0){tx=x[i]+t*v[i];if (tx<mr)return true;}
  else{tx=x[i]+t*v[i];mr=max(mr,tx);}
 }
 return false;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;

ri=n;
le=1;
for (long i=1;i<=n;i++)
{
 cin>>x[i]>>v[i];
 if (v[i]<0)le=i;
 if (v[i]>0)ri=min(ri,i);
}

if (le<=ri)
{
 cout<<-1<<endl;
 return 0;
}

l=0;
r=1e9;
for (int iter=1;iter<=100;iter++)
{
 mid=l+r;
 mid/=2;
 if (solve(mid))r=mid;
 else l=mid;
}
cout.precision(12);

cout<<fixed<<l<<endl;

cin.get();cin.get();
return 0;}