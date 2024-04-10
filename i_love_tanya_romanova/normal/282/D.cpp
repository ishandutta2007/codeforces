/*
I am a man who walks alone
And when I'm walking a dark road
At night or strolling through the park

When the light begins to change
I sometimes feel a little strange
A little anxious when it's dark.

Fear of the dark,fear of the dark
I have constant fear that something's always near
Fear of the dark,fear of the dark
I have a phobia that someone's always there

Have you run your fingers down the wall
And have you felt your neck skin crawl
When you're searching for the light ?
Sometimes when you're scared to take a look
At the corner of the room
You've sensed that something's watching you.

Have you ever been alone at night
Thought you heard footsteps behind
And turned around and no-one's there ?
And as you quicken up your pace
You find it hard to look again
Because you're sure there's someone there

Watching horror films the night before
Debating witches and folklore
The unknown troubles on your mind
Maybe your mind is playing tricks
You sense,and suddenly eyes fix
On dancing shadows from behind.

Fear of the dark, fear of the dark
I have a constant fear, thought you heard
Fear of the dark, fear of the dark
I have a phobia that someone's always there.

When I'm walking a dark road
I am a man who walks alone
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

double g;
long n,ar[100];
set<pair<long, long> > bad;
long aa,bb;

int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
    cin>>ar[i];
}
g=1.0+sqrt(5.0);
g/=2;

for (int i=0;i<=300;i++)
{
    aa=g*i;
    bb=g*g*i;
    
    bad.insert(make_pair(aa,bb));
    bad.insert(make_pair(bb,aa));
    
}

if (n==1)
{
         if (ar[0]!=0)cout<<"BitLGM"<<endl;
         else cout<<"BitAryo"<<endl;
}
else if (n==3)
{
     if ((ar[0]^ar[1]^ar[2])==0)cout<<"BitAryo"<<endl;
     else cout<<"BitLGM"<<endl;
}
else
{
    if (bad.find(make_pair(ar[0],ar[1]))!=bad.end())
    cout<<"BitAryo"<<endl;
    else cout<<"BitLGM"<<endl;
}

cin.get();cin.get();
return 0;}