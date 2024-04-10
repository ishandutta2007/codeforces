/*
I see the tracers it leaves in the sky
A racing stripe canopy for your eye
I see it dying fast right through the floor
An aftershock of filth and gore

We try our best to just keep control
Just to keep breathing
Is reaching a goal

I can see now how fast it really grows
I see God's face with a bloody nose
Unbelievable to you and me
Yet easier all the time to see

We try our best to not lose our minds
Just to keep breathing is wasting our time
We try our best to gain control
Just to keep living is taking it's toll

It doesn't take a scientist
To really comprehend the gist
That everyday we all decide
To slowly commit suicide
And there is no hotline to call
No saviour coming to get us all
I can't fathom how it happened so fast
How bad we were beaten
Floored and harassed

One does move the floor,
Two can make the walls take a breath,
Three will let the ceiling cry,
Four the pictures all bleed to death,
I have taken five,
It's a wonder I'm still alive,
Then I'm popping ten,
To see if I can die and come back again!
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n;
long ar[200][200];
long res[200];

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
    cin>>ar[i][j];
    if (i==j)continue;
    res[i]|=ar[i][j];
    res[j]|=ar[i][j];
}
for (int i=1;i<=n;i++)
{
 if (i>1)cout<<" ";
 cout<<res[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}