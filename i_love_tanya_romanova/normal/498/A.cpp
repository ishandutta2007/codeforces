/*
High gear rider
Take me to the top
Get me to the summit
I'm never gonna stop
Feel my body pumping
Carrying my load
Taking the incline
Getting ready to explode

Takin' the hill
Just for the thrill
Honin' my skill
Up and down on Killer Hill
Killer Hill
Take me where I wanna go
In for the thrill
Take me where I wanna go

Rock shock and cattle head
Take the terrain
Sopping in sweat
My breath to regain
Feel the breaking calipers
Squeezing on the rim
Super power riding
Keeps me hard and fit for trim

Killer Hill
Killer Hill

Take me where I wanna go
In for the thrill
Take me where I wanna go
Killer Hill
Take me where I wanna go
In for the thrill
Take me where I wanna go
Killer Hill
Take me where I wanna go
In for the thrill
Take me where I wanna go
Killer Hill
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
#define bs 1000000009
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long x1,y1,x2,y2,n;
long long a,b,c,v1,v2;
long long ans;

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x1>>y1;
cin>>x2>>y2;
cin>>n;
for (int i=0;i<n;i++)
{
 cin>>a>>b>>c;
 v1=a*x1+b*y1+c;
 v2=a*x2+b*y2+c;
 if (v1>0&&v2<0)++ans;
 if (v1<0&&v2>0)++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}