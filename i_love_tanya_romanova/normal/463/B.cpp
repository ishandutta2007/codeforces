/*
They revere only empty words
I denounce this twisted world
Our seeking of more has blinded us
I cast myself out!

A growing hatred towards this sick world
Where wealth defines a man's worth
The weakling rats ruin everything
Then burn their own homes for a smoke screen

Sarcastic, hey I am a cynic
No other way to speak these days
Rid myself of this so called reality
I cast myself out!

Here in the vortex of echoes I find myself lost
No confession to atone for my rebellion
Here in the vortex of forsaken souls I let myself go
I cast myself out so no other can

Rabid dogs were once put down
Now the madmen run the asylum
Your polluted life sickens me
I cast myself out!

Bless you for showing me the door
So I know where we step outside
The gloves come off and we meet at last
Eye to eye, like man and beast always have

Here in the vortex of echoes I find myself lost
No confession to atone for my rebellion
Here in the vortex of forsaken souls I let myself go
I cast myself out so no other can

Breathing in your poisoned kingdom is like choking on gravel
I want to tear off my skin and run into the rain

Here in the vortex of echoes I find myself lost
No confession to atone for my rebellion
Here in the vortex of forsaken souls I let myself go
I cast myself out so no other can

No confession to atone for my rebellion
In the vortex of forsaken souls I let myself go
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
#define rmost agasdgasdg

using namespace std;

long long n,ar[1<<20],en,ans;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int i=1;i<=n;i++)
{
 en+=ar[i-1]-ar[i];
 if (en<0){ans-=en;en=0;}
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}