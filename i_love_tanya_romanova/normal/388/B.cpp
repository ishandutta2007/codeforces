/*
Terminal, what disease?
Told me too late
What's this cough and wheeze?
Fatal? You're shittin' me!
A second opinion
Is what I need
Laughin' in a windstorm
Blowin' all the cornstalks down
Cryin' in a funeral home
Forward my mail, six feet underground

Contagious? Say, why not?
Not just me
Waitin' to rot
Painful? Yeah, I know
It couldnt be easy
When I had to go
I'm yankin' on my plug
And I can't seem to get it loose
Pullin' all the stops
Your ideals change when you got nothin to lose

Elimination
Elimination
Elimination
Elimination

Eliminate the right
Eliminate the wrong
Eliminate the weak
Eliminate the strong
Eliminate your feelings
Eliminate too late
Eliminate the hope
Eliminate, eliminate!

If I had just one more day
I'd turn it all around
I'd make a play of good, clean livin'
And dig me out of the ground
And if I had just one more day
I'd say it to your face
Pull the plug on everyone
Eliminate this race.
We want to cure
And we want it now.
Reissue hope
We don't care how
You're makin' a mess
Diseasin' a nation
Runaway train to elimination

Hopeless? There's no doubt
Set on a slow burn
From the inside out
Careful? Say, what for?
Last one out
Closes the coffin door
Spendin' all you saved
And wishin' for a little more
If I'm lookin' at the ceilin'
Then I must be layin' on the floor.

Terminal, what disease?
Told me too late
What's this cough and wheeze?
Fatal? You're shittin' me!
A second opinion
There's gotta be
Laughin' at the epidemic
Something is going around
Crying at the epidemic
Pullin' on nails, six feet underground

Elimination
Elimination
Elimination
Elimination

Eliminate the right
Eliminate the wrong
Eliminate the weak
Eliminate the strong
Eliminate your feelings
Eliminate too late
Eliminate the hope
Eliminate, eliminate!
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
long ways[2000];
vector<long> lev[100];
long calc;
long ar[1100][1100];

void add_edge(long a,long b)
{ways[b]+=ways[a];
ar[a][b]=ar[b][a]=1;
}

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
ways[1]=1;
lev[0].push_back(1);
lev[1].push_back(3);
lev[1].push_back(4);
add_edge(1,3);
add_edge(1,4);
calc=4;
for (int lvl=2;lvl<=32;lvl++)
{
 for (int j=1;j<=30;j++)
 {
  calc++;
  lev[lvl].push_back(calc);
 }
}

for (int lvl=2;lvl<=30;lvl++)
{
 for (int i=0;i<30;i++)
 {
  //add_edge(lev[lvl-1][0],lev[lvl][i]);
  if (i+lvl<=30)
  {add_edge(lev[lvl-1][1],lev[lvl][i]);add_edge(lev[lvl-1][0],lev[lvl][i]);}
  else
  {
   if (lvl==2)add_edge(lev[lvl-1][0],lev[lvl][i]);
   else add_edge(lev[lvl-1][i],lev[lvl][i]);
  }
 }
}

for (int i=0;i<30;i++)
if (n&(1<<i))
add_edge(lev[30][30-i-1],2);

cout<<calc<<endl;
for (int i=1;i<=calc;i++)
{
 for (int j=1;j<=calc;j++)
 {
  if (ar[i][j])cout<<"Y";else cout<<"N";
 }
 cout<<endl;
}


//cout<<ways[2]<<endl;

/*for (int i=1;i<=30;i++)
{for (int j=0;j<lev[i].size();j++)cout<<ways[lev[i][j]]<<" ";
cout<<endl;}
*/

cin.get();cin.get();
return 0;}