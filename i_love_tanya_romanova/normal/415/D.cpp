/*
The glued-on sheet of self control
The pity of sense of sanity
Cracking at the seams
Torn from my reality

The motion of thoughts subdued
Overcome, suppressed by terror
The mouth of fear overfed
By dread beyond measure

Pounding waves of overload
Running through my every nerve
Will reduced to nothingness

My system overturned
My mind resigns to defeat
Internal razors activated
Slashing through unprocessed thought
The severance of self complete

Heartbeats hammering at the sight
A revelation to wrap my soul in fear
Blinded by the never light
As I stare into my organic shadow

The bin of repressed emotions crammed
Limits of pain by far exceeded
I stare into the blank
The mantra of dead silence repeated

Hear me, find me
Save me, the dead me

Shallow breathing
Eyes not shut, not open
By fear silenced
Incantations never spoken

This hell of vacuum abound
With the chanting whispers of the mute
Exposed to the wrath of never sound
The words of my organic shadow
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

long n,k,answ;
long dp[2100][2100];
void ad(long&a,long &b)
{
 a+=b;
 while(a>=bs)a-=bs;

}

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
dp[1][i]=1;
for (int i=1;i<k;i++)
{
 for (int j=1;j<=n;j++)
  for (int q=j;q<=n;q+=j)
   ad(dp[i+1][q],dp[i][j]);
}

answ=0;
for (int i=1;i<=n;i++)
ad(answ,dp[k][i]);
cout<<answ<<endl;

cin.get();cin.get();
return 0;}