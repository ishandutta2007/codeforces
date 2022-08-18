/*
In the skies above the isle
Aces In Exile prevail!

From near and far they arrived join the force
Ready to serve the Allied command
Sent in the training, though they already earned their wings
They were ready to fly they were fit for the fight
Once in the air the battle began
They had proven their worth now they fight for revenge

Fighter pilots in exile fly for foreign land
Let the story be heard tell of 303
Fighter pilots of Poland in the battle of Britain
Guarding the skies of the isle

Even at night shadows cover the ground
Fighting goes on from dusk till dawn
We fall on the Reich with the claws of the eagle!
They were Ready to fight, they were ready to die
Up in the air, the battle goes on
They had proven their worth now they have their revenge

Fighter pilots in exile fly for foreign land
Tell the story again to the 310
Men of Czechoslovakia in the battle of Britain
Guarding the skies of the isle

Over the battlefield brave man long way from home
You are the chosen ones sent to the sky to die
Over the battlefield brave man long way from home
You are the chosen ones sent to the sky to die

Oh fly - it echoes in history
Turning the tides in the heavens above

Fighter pilots in exile fly for foreign land
When the battle's been won trouble 401
Fighter pilots of Canada in the battle of Britain
Guarding the skies of the isle

On wings of history they turn from home
To live eternally sky bound they roam
In all of history, never before
Was more owed to so few

Fighter pilot in exile!
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

double y1,y2,yw,xb,yb,r;

double gdist(double x,double y,double x1,double y1,double x2,double y2)
{
double s=(x-x1)*(y-y2)-(x-x2)*(y-y1);
s=fabs(s);
double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
return s/d;
}

double dy,td;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cout.precision(12);

cin>>y1>>y2>>yw>>xb>>yb>>r;
yw-=r;
yb=yw+(yw-yb);
y1+=r;
if (gdist(0,y2,0,y1,xb,yb)<r)
cout<<-1<<endl;
else
{
 dy=yb-y1;
 td=yb-yw;
 cout<<fixed<<xb*((dy-td)/dy)<<endl;
    
}

cin.get();cin.get();
return 0;}