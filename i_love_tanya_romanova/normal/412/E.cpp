/*
There goes the siren that warns of the air raid
Then comes the sound of the guns sending flak
Out for the scramble we've got to get airborne
Got to get up for the coming attack

Jump in the cockpit and start up the engine
Remove all the wheel blocks there's no time to waste
Gathering speed as we head down the runway
Gotta get airborne before it's too late

Running, scrambling, flying
Rolling, turning, diving, going in again
Running, scrambling, flying
Rolling, turning, diving
Run, live to fly, fly to live, do or die
Won't you run? Live to fly, fly to live
Aces high

Move into fire at the mainstream of bombers
Let off a sharp burst and then turn away
Roll over, spin round and come in behind them
Move to their blindsides and firing again

Bandits at eight o'clock move in behind us
Ten M E one o nines out of the sun
Ascending and turning our Spitfires to face them
Heading straight for them I press down my guns

Rolling, turning, diving
Rolling, turning, diving, going in again
Rolling, turning, diving
Rolling, turning, diving
Run, live to fly, fly to live, do or die
Won't you run? Live to fly, fly to live
Aces high
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
#define bs 1000000009
#define bsize 256

using namespace std;

string st;
long q,calc;
long ways[1200000];
long long ans;
long tways;
long n;
long er;

bool let(char c)
{
 return (c>='a'&&c<='z');
}
bool dig(char c)
{
 return (c>='0'&&c<='9');
}
bool pref(char c)
{
 if (c=='_')return true;
 return (dig(c)||let(c));
}
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>st;
n=st.size();

for (int i=0;i<st.size();i++)
{
 if (st[i]=='@')
 {
  q=i-1;
  calc=0;
  while (q>=0&&pref(st[q]))
   { 
   if (let(st[q]))
   ++calc;--q;}
  ways[i]=calc;
 } 
 if (st[i]=='.')
 {
  q=i-1;
  er=0;
  tways=0;
  while (true)
  {
   if (q<0){er=1;break;}
   if (st[q]=='@'){if (q==i-1)er=1;break;}
   if (!dig(st[q]))
    if (!let(st[q])){er=1;break;}
    --q;
  }
  if (er==0)
  tways=ways[q];
  q=i+1;
  while (true)
  {
   if (q>=n)break;
   if (let(st[q]))ans+=tways;else break;
   ++q;
  }
 }
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}