/*
I hear someone calling me.
Where they call from, I can see no light.
Walk through fire!
To me now!
And the fire I can't feel.

Bare bones!
I! have walked through hell.
Now I'm back,
Stripped to the bone!
I! have been to hell,
Now I'm here an' I'm taking all I need!
Bare bones!

Obsticles are in my way.
Just beyond them lies what? I don't know.
Walk through blind!
Know I'm here!
There is nothing I can't see.

Bare bones!
I! have been to hell.
Now I'm back,
Stripped to the bone!
I! have been to hell,

Now I'm back an' I'm taking all I need!
Bare bones!

Open my eyes to what I need to see.
Am I you or am I becoming me?
Life from day to day,
Turn another page.
Christened in the rain,
That turns to rage.

Washed of anomosity.
Naked truth falling black or white.
You are turning!
To the light!
There is nothing I can't be.

An' I'm back an' I'm taking all I want.
Bare bones!
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,ar1[200000],ans,fl1,ar2[2000],fl;

int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>ar1[i];
for (int i=1;i<=m;i++)
cin>>ar2[i];
ans=1000000;
for (int i=1;i<=400;i++)
{
    fl=0;
    fl1=0;
    for (int j=1;j<=n;j++)
    {if (ar1[j]>i)fl=1;if (ar1[j]*2<=i)fl1=1;}
    for (int j=1;j<=m;j++)
    if (ar2[j]<=i)fl=1;
    if (fl==0&&fl1==1)ans=min(ans,ans-ans+i);
}
if (ans>500)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}