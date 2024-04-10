/*
Hunter
Seeker
A liar and deceiver
Hiding behind my sight

What Is that sound
Somewhere out there in the night
The darkness creeping in
It's watching from all sides

Cybernetic talons
Are reaching into my mind

Nowhere to hide

Hunter
Seeker

I rise another day
I awaken as a slave
The eye is watching me
For my own security

I feel the wind
Across my back
I hear as the blade
Is drawn

Programmed to asssasinate
A silent o0blivion

Hunter
Seeker

You are being watched
They are always watching
Watching, waiting
The eye never sleeps

Never

You are being watched

I rise another day
I awaken as a slave
Operation prism
Turn the world to gray

I feel the wind
Across my back
I hear as the blade
Is drawn

The knife is closing in
A silent Oblivion
Hunter
Seeker
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define count adsgasdgasdg

using namespace std;

long n,t;
double c,ans[1<<20];
long ar[1<<20];
double re;
double s[1<<20];
long tests,x;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>t>>c;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}
for (int i=1;i<=n;i++)
{
 ans[i]=(ans[i-1]+1.0*ar[i]/t)/c;
}
s[0]=0;
for (int i=1;i<=n;i++)
s[i]=s[i-1]+ar[i];

cin>>tests;
for (;tests;--tests)
{
 cin>>x;
 re=s[x]-s[x-t];
 re/=t;
 cout.precision(7);
 cout<<fixed<<re<<" "<<ans[x]<<" "<<fabs(ans[x]-re)/re<<"\n";
}
 
cin.get();cin.get();
return 0;}