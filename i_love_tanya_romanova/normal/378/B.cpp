/*
A cloud of eider down
Draws around me softening the sound
Sleepy time when I lie
With my love by my side
And she's breathing low
And the candle dies.
When night comes down you lock the door
The boot falls to the floor
As darkness falls the waves roll by
The seasons change
The wind is warm.
Now wakes the owl, now sleeps the swan
Behold a dream, the dream is gone
Green fields
A cold rain is falling
Near the golden dawn.
And deep beneath the ground
The early morning sounds and I go down
Sleepy time in my life
With my love by my side
And she's breathing low
And I rise like a bird
In the haze and the first rays touch the sky
And the night winds die.
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,l,r,ar1[200000],ar2[200000],ok1[200000],ok2[200000];

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar1[i]>>ar2[i];

l=0;
r=0;
//ok1[1]=ok2[1]=1;

for (int i=1;i<=n;i++)
{
 if (l==n)++r;
 else if (r==n)++l;
 else if (ar1[l+1]>ar2[r+1])++r;
 else ++l;
 ok1[l]=ok2[r]=1;
}

for (int i=1;i<=n;i++)
if (i<=n/2||ok1[i])cout<<1;else cout<<0;
cout<<endl;
for (int i=1;i<=n;i++)
if (i<=n/2||ok2[i])cout<<1;else cout<<0;
cout<<endl;

cin.get();cin.get();
return 0;}