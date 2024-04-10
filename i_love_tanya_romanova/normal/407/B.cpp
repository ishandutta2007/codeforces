/*
I am a man who walks alone
And when I'm walking a dark road
At night or strolling through the park

When the light begins to change
I sometimes feel a little strange
A little anxious when it's dark

Fear of the dark, fear of the dark
I have a constant fear that somethings always near
Fear of the dark, fear of the dark
I have a phobia that someone's always there

Have you run your fingers down the wall
And have you felt your neck skin crawl
When you're searching for the light?

Sometimes when you're scared to take a look
At the corner of the room
You've sensed that somethings watching you

Fear of the dark, fear of the dark
I have a constant fear that somethings always near
Fear of the dark, fear of the dark
I have a phobia that someone's always there

Have you ever been alone at night
Thought you heard footsteps behind
And turned around and no one's there?

And as you quicken up your pace
You find it hard to look again
Because you're sure there's someone there

Fear of the dark, fear of the dark
I have a constant fear that somethings always near
Fear of the dark, fear of the dark
I have a phobia that someone's always there

Fear of the dark, fear of the dark
Fear of the dark, fear of the dark
Fear of the dark, fear of the dark
Fear of the dark, fear of the dark

Watching horror films the night before
Debating witches and folklores
The unknown troubles on your mind

Maybe your mind is playing tricks
You sense, and suddenly eyes fix
On dancing shadows from behind

Fear of the dark, fear of the dark
I have a constant fear that somethings always near
Fear of the dark, fear of the dark
I have a phobia that someone's always there

Fear of the dark, fear of the dark
I have a constant fear that somethings always near
Fear of the dark, fear of the dark
I have a phobia that someone's always there

When I'm walking a dark road
I am a man who walks alone
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

long long n,p[200000],tosolve[20000];
long long moves[20000];

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>p[i];
tosolve[1]=2;
moves[1]=2;
for (int i=2;i<=n;i++)
{
 for (int j=p[i];j<i;j++)
 tosolve[i]+=tosolve[j];
 tosolve[i]+=2;
 tosolve[i]%=bs;
 moves[i]=moves[i-1]+tosolve[i];
 moves[i]%=bs;
}

cout<<moves[n]<<endl;

cin.get();cin.get();
return 0;}