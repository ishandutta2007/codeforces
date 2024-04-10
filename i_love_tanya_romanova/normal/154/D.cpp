/*
Gotta get a message through
Cause I think I'm losing you
Am I too late
Drinking habit's a loose sometime
I gotta know if you're still mine
And I can't wait
Last time I saw your face
You tried to hide the tears
But I could see the trace
I'd be there if I could
But it's so far away from home
Lost in Hollywood

In the dark the vultures wait
I can hear them
Knocking at my gate
But I'm not here
The brew was cold
The meat is stale
In the L.A. night the sirens wail
The song you can feel
Pale stars that never shine
Scotch and the whiskey
And the Rainbow local wine
She's done more bad than good
I gotta get away somehow
Lost in Hollywood

On the streets the sun is fine
Don't you feel the advantage hit your mind
Feels all right oh yeah
But I'm a lover
Like a loaded gun
Chasing shadows on the run
Out in the night
I'm gonna lose control
If I been losing you
To pay for rock'n'roll
Get back I know I should
Gotta get back home to you
You don't know what I been through
But there's nothing I can do
Lost in Hollywood
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

long long x1,x2,a,b,d,mov;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x1>>x2>>a>>b;
d=x2-x1;

if (a==0&&b==0)
cout<<"DRAW"<<endl;
else
if (a<=0&&b>0)
{
 if (x1+a<=x2&&x1+b>=x2)cout<<"FIRST"<<endl<<x2<<endl;
 else cout<<"DRAW"<<endl;
}
else
{
 if (x1+a<=x2&&x1+b>=x2)cout<<"FIRST"<<endl<<x2<<endl;else
 if (a>0&&d<0)cout<<"DRAW"<<endl;
 else if (a<0&&d>0)cout<<"DRAW"<<endl;
 else
 {
  d=abs(d);
  a=abs(a);
  b=abs(b);
  if (a>b)swap(a,b);
  if (d%(a+b)==0)cout<<"SECOND"<<endl;
  else if (d%(a+b)<a||d%(a+b)>b)
  cout<<"DRAW"<<endl;
  else
  {
   mov=d%(a+b);
   cout<<"FIRST"<<endl;
   if (x1<x2)cout<<x1+mov<<endl;
   else cout<<x1-mov<<endl;
  }
 }
}

cin.get();cin.get();
return 0;}