/*
She keeps the world at bay
With walls built to stand come-what-may
And with that coldness on display, they held until today
She would hold her own
Running all alone
Ridding her road of every grain
To stay in control

But now
She cries
Alive

Suddenly she is down on all four
And the walls will support her no more
Cries her eyes out like never before
Onto this linoleum
The bottled up and stored

She's won every war
And when she's out that door
She will push ahead of you, frowning at the poor
She would move so fast not to end up last
Aiming for the finish line
To smile at those she'd passed

But now
She cries
Alive

Suddenly she is down on all four
And the walls will support her no more
Cries her eyes out like never before
Onto this linoleum
The bottled up.
And stored -

And sometimes
Oh, just sometimes
That's really all it takes:
A hand on her shoulder
Then she breaks

Sometimes that's really all it takes:
(Yes then)
A word of kindness and she breaks
(She breaks)
And then the sum of damage done
(Well she breaks)
Spills out on stale linoleum
(She breaks)

Sometimes that's really all it takes:
(She breaks)
A gentle touch and then she breaks
(She breaks)
To see the sum of damage done
(She breaks)
Stain this linoleum
(Oh, she breaks)

Sometimes that's really all it takes:
(Oh, she breaks)
A word or touch and then we break
(Oh, she breaks)
And all this world's linoleum
(She breaks)
Can't hold the sum of damage done -

(She's becoming her last casualty)
Itsy bitsy Spider
Climbed the water spout
(If she breaks then at last she'll be free)
Down Came the Rain
And washed the spider out
(But she keeps it together once more)
Now she stays on the ground
So she'll never fall
(And runs another day to fight another war)
See she would rather drown
Than lose control
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

long ar[200],ps1,ps2;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<4;i++)
 cin>>ar[i];
long iters=0;

while (true)
{
 ++iters;
if (ar[0]+ar[1]+ar[2]+ar[3]==4)break;
ps1=rand()%4;
ps2=ps1+1;
ps2%=4;

if (ar[ps1]%2==0&&ar[ps2]%2==0)
{
 ar[ps1]/=2;ar[ps2]/=2;
 cout<<"/"<<ps1+1<<endl;
}
else
{
 ar[ps1]++;
 ar[ps2]++;
 cout<<"+"<<ps1+1<<endl;
}
}

//cout<<iters<<endl;

cin.get();cin.get();
return 0;}