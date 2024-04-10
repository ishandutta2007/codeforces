/*
For the first time in my life
I've seen the fire within your eyes
My mind, it screams for shelter now
I know I've got to resist some how

My religion, my certain death
My salvation, my sacrilege
My inner sanctum, my prophecy
You've become everything and more to me

So our souls will be one
A new era has begun
Fantasies will come true
Not only for the chosen few

For freedom is a two edged sword
And life is only a gift for gods
Straight from the heart of the serpent's kiss
To see something as it really is

My precious kingdom, my empire
My tragedy and my desire
My life's blood, my shining light
Feels like I am finally alive

So our souls will be one
A new era has begun
Fantasies will come true
Not only for the chosen few

My religion, my certain death
My salvation, my sacrilege
My inner sanctum, my prophecy
You've become everything and more to me

So our souls will be one
A new era has begun
Fantasies will come true
Not only for the chosen few

So our souls will be one
A new era has begun
Fantasies will come true
Not only for the chosen few

So our souls will be one
A new era has begun
Fantasies will come true
Not only for the chosen few
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
#define free adsgasdg

using namespace std;

long long n,x,y,maxy,miny,maxx,minx;

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
minx=1e9;
maxx=-1e9;
miny=1e9;
maxy=-1e9;
for (;n;--n)
{
 cin>>x>>y;
 maxx=max(maxx,x);
 maxy=max(maxy,y);
 minx=min(minx,x);
 miny=min(miny,y);
}
x=maxx-minx;
x=max(x,maxy-miny);
cout<<x*x<<endl;

cin.get();cin.get();
return 0;}