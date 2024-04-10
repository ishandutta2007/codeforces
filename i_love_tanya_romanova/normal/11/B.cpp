/*
When in pain I try to find
A different plain to on which to set my mind
To distract it from this downward vibe
And thereby avoid the tide
The rushing tide has no remorse
It might hold me if I cross it's course
But the suction of it's waves
Has taken many a mind to the grave

Last shred of hope
I cling to as I float
Through the lightless night
And here comes the tide

Grave and dark - a dual pact
Overpowering the ones who lacked
The energy to pull out of such mire
Their very souls tortured by the fire

High tide - in my soul
No more darksome thoughts uproll
Past are days when I was feeling numb
Till the turn of tide will come

When the tide is in I run
Wash away my sins I come undone
Trying to ignore the Siren's call
And into the void I fall
The rushing tide has no remorse
It might hold me if I cross it's course
But the suction of it's waves
Has taken many a mind to the grave

All panic's banned
Inhale and take a stand
Walk with me tonight
But here comes the tide...

Grave and dark - a dual pact
Overpowering the ones who lacked
The energy to pull out of such mire
Their very souls tortured by the fire

High tide - in my soul
No more darksome thoughts uproll
Past are days when I was feeling numb
Till the turn of tide will come

Grave and dark - a dual pact
Overpowering the ones who lacked
The energy to pull out of such mire
Their very souls tortured by the fire

High tide - in my soul
No more darksome thoughts uproll
Past are days when I was feeling numb
Till the turn of tide will come

Daylight returns - but nevermore
Returns the wanderer to the shore
One last time allures the Siren's calls
And eternal darkness falls...
*/

#pragma comment(linker, "/STACK:16777216")
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

long x,m,ans;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x;
x=abs(x);

for (int i=0;i<=1000000;i++)
{
 m=i*(i+1)/2;
 if (m>=x&&m%2==x%2){ans=i;break;}
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}