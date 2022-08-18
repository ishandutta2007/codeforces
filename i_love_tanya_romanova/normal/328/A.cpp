/*
We entered Winter once again
Naked, freezing from my breath
Neath the lid all limbs tucked away
This coffin is your abode from now and onwards

Your body is mine to avail
Such a tragic sight you are
Slave under my creed
Spurring me with those tears

I am beyond death
Midst a dreaming affinity
Saving strength now, faint whispers
Come erotic communion in its splendour

Fever mirrored ghosts
Night time consolation, cross the line
Draw murder into art
Sleep inside through days

In the wake of this relief
Shivering, longing for more
Insanity at it's peak
Love me to my death

Lost are days of Spring
You sighted and let me in
Keep the beast inside
Shackled within my hide
Screaming out too late
Losing to my hate
Grew together with your skin
And paced the trails of sin

Your gaze covered with virgin snow
Rigid features
It's the shallow deeds who is to blame
Deafening shrieks pierced the night

A step from oblivion
Moving into the dim lights
Hiding within a reverie
It was worth it for the wait alone

Your body is mine to avail
Such a tragic sight you are
Slave under my creed
Spurring me with those tears
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
#define bsize 256

using namespace std;

long ar[10];

long solve()
{
 for (int i=-100000;i<=100000;i++)
 {
     ar[5]=i;
     if (ar[2]-ar[1]==ar[3]-ar[2]&&ar[4]-ar[3]==ar[2]-ar[1]&&
     ar[5]-ar[4]==ar[2]-ar[1])return i;
     if (ar[3]*ar[3]==ar[1]*ar[5]&&ar[2]*ar[4]==ar[3]*ar[3])
     return i;
 }
 return 42;
}
int main(){
//freopen("lie.in","r",stdin);
//freopen("lie.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=4;i++)
cin>>ar[i];
cout<<solve()<<endl;

cin.get();cin.get();
return 0;}