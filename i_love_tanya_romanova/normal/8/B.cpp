/*
I see the hill
scattered to horizons
They've haunted my dreams
for a long time

The bones of ancestors
lay unrestful
They're calling me
to their shrine

And I struggle
With the season before the snow
The ground is hard with ice
the road beckons, I'll follow

Home must be left
to know the longing
The toes will grow numb
from the frost

I used to know
where I was heading for
Somewhere, somehow
it just got lost

I'd give anything
for the signs in the sky
Wheels of fire wild at play
spinning, ascending

To learn that there's more than
just to live and die
Some love would be sweet
before the final ending

I will dream myself alive
awaiting light
The pilgrim will arrive
to the state of grace

Where the starved souls will revive
awaiting light
This pilgrim will arrive
to the state of grace

I'd give anything
for the signs in the sky
To know there's more
than just to live and die

I will dream myself alive
awaiting light
This pilgrim will arrive
to the state of grace

Where the starved souls will revive
awaiting light
This pilgrim will arrive
to the state of grace

I will dream myself alive
awaiting light
This pilgrim will arrive
to the state of grace

Where the starved souls will revive
awaiting light
This pilgrim will arrive
to the state of grace

To the state of grace
To the state of grace
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

string st;
long was[500][500],qx,qy;
long er;
long tx,ty;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

qx=qy=100;
cin>>st;
was[qx][qy]=1;
for (int i=0;i<st.size();i++)
{ 
 if (st[i]=='L')--qx;
 if (st[i]=='R')++qx;
 if (st[i]=='U')--qy;
 if (st[i]=='D')++qy;
 if (was[qx][qy]>0)er=1;
 was[qx][qy]=i+2;
 for (int q=-1;q<=1;q++)
  for (int w=-1;w<=1;w++)
   if (abs(q)+abs(w)==1)
    {
     tx=qx+q;
     ty=qy+w;
     if (was[tx][ty]>0&&was[tx][ty]!=i+1)er=1;
    }
}

if (er)cout<<"BUG"<<endl;
else cout<<"OK"<<endl;

cin.get();cin.get();
return 0;}