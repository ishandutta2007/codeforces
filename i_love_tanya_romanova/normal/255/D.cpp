/*
Bring them down, take it back
Bring them down, take it back

This moment, one moment
The time to face the horror
A clash, great clash
The two worlds collide

The power, vast power
Each side drives its armies
The solace, no solace
This is what we've become

The past thou shalt never cross
Things here will never be the same
All bear witness to the gathering of the march

The past thou shalt never cross
Things here will never be the same
All bear witness to the gathering of the march

This is what we've become
This is what we've become
No solace, no solace, no solace

This truth, one truth
The underlying reason
One hope, all hope
The strength of mankind risen

Our kind, their kind
Once one, now shattered
Unite, unite
We hold the key to tomorrow

The past thou shalt never cross
Things here will never be the same
All bear witness to the gathering of the march

The past thou shalt never cross
Things here will never be the same
All bear witness to the gathering of the march

Bring them down, take it back
Bring them down, take it back
Bring them down
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

long long n,x,y,c,l,r,mid;

long long gi(long long g)
{
 if (g<=0)return 0;
 return g*g;
}

long long gj(long long g)
{
 if (g<=0)return 0;
 return (g*g-g)/2+g;
}

long long gett(long long t)
{
 long long ss=(2*t+1)*(t*2+1);
 ss=ss/2+1;
 // sides
 ss-=gi(t-(x-1));
 ss-=gi(t-(n-x));
 ss-=gi(t-(y-1));
 ss-=gi(t-(n-y));
 ss+=gj(t-(x-1)-(y-1)-1);
 ss+=gj(t-(n-x)-(n-y)-1);
 ss+=gj(t-(n-x)-(y-1)-1);
 ss+=gj(t-(x-1)-(n-y)-1);
 return ss;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>x>>y>>c;
l=0;
r=1e6;
while (l<r)
{
 mid=l+r;
 mid/=2;
 if (gett(mid)>=c)r=mid;
 else l=mid+1;
}

cout<<l<<endl;

cin.get();cin.get();
return 0;}