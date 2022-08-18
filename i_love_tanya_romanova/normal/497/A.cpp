/*
The lowest form of life that's crawling in our streets
From seedy dope pushers to the politicians we meet
The sorry religious vomit that infests in our TVs
The weapons that we sell to the trash in the middle east
Murderous drug smugglers pay their way to pass
They look the other way when they take the kickback
We've got to put a stop to this senseless bullshit
Take all these people and throw them in the pit

Let us know - where our tax dollars are spent
Tell us how - how much it costs to repent
Time has come - for us to take a stand
Let us know - when you meet our demands

You can take this all to hell
Shove it up your ass where the sun ain't shining
We know now what it takes to defend
If disaster strikes then they'll be hiding
You can take this all to hell
Shove it up your ass where the sun ain't shining
We know now what it takes to defend
If disaster strikes, then they'll be hiding
Corruption

From laundering money to hookers on the make
There's always a scandal, someone's on the take
They payoff for secrets, sell plans to a spy
They cover their asses and say it's a lie
Society cries when the vermin go free
When they're done, what's left for me?
This social disorder that's causing us pain
Indecent disease, it's they who are to blame
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs1 1000000007ll
#define bs2 1000000009ll
#define P1 173
#define P2 187
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,m;
string st[1<<12];
long bad,done[1<<12];
long ans;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>st[i];
}

for (int j=0;j<m;j++)
{
 bad=0;
 for (int i=2;i<=n;i++) {
  if (done[i]==0&&st[i][j]<st[i-1][j])
   bad=1;
 }
 if (bad)++ans;
 else
 for (int i=2;i<=n;i++)
  if (st[i][j]>st[i-1][j])
   done[i]=1;   
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}