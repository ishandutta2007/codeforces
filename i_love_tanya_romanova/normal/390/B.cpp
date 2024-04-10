/*
Who wants to live forever
Here in a world of shame
Living under pressure
Hearts are filled with pain

It's time, time to break free
Time for a journey through dimensions
A never ending ride
Rays of hope from somewhere
Come from deep inside

Over and over I'm lost in bad dreams
And into the void I stare

Rise up to Heaven where Eden lies
A lost asylum somewhere beyond
Rise up forever out of the dark
Pain and sorrow left in the past

I'll carry on to safe my life
I'll ride on the wings of storm
I'm still alive, free inside
My heart and soul reborn

Over and over I'm counting my tears
I'm alone with all my fears

Rise up to Heaven where Eden lies
A lost asylum somewhere beyond
Rise up forever out of the dark
Pain and sorrow left in the past

Over and over I'm lost in bad dreams
And I'm counting all my tears

Rise up to Heaven where Eden lies
A lost asylum somewhere beyond
Rise up forever out of the dark
Pain and sorrow left in the past
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
 
//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 2048
 
using namespace std;

long long n,a[200000],b[200000];
long long ans;

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a[i];
}
for (int i=1;i<=n;i++)
cin>>b[i];

for (int i=1;i<=n;i++)
{if (b[i]==1||a[i]*2<b[i])--ans;
else ans+=b[i]/2*(b[i]-b[i]/2);}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}