/*
I'm in a nightmare and it's gonna burn tonight
I don't know why but there's something strange in me
Losing all control if you don't want to stop
Searching the way where I can get the force

This is the beginning of hostility
In the still of the night
I keep a strict eye on you
Somewhere on the hill of immortality
The butcher is running down the land
He's running down the land, oh

Taking your chance, looking for a fight, biting the bullet
Ready you'll catch your death

Rough and tumble life, such and eternal night
We're the die-hards with a nasty mind deep in integrity
Joining our destructions with our domination
You can't resist it's thrashing rage

In the labyrinth I run to see the end
Mirage of death as long as infinity
Living dying in this deep misery
I'm gonna raise hell 'coz I'm over the top

This is the beginning of hostility
In the still of the night
I keep a strict eye on you
Somewhere on the hill of immortality
The butcher is running down the land
He's running down the land, oh

Choose your awful swords and fight until the end
Scream the pain that you have die right here in the hole
Hunt if you wanna live and kill until you win
Lust the blood of your enemy falls or return in a deep sin

Now we are the guards of their thrashing land
Now we are the guards of their thrashing land
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

set<long> c1,c2;
multiset<long> s1,s2;
long w,h,n;
string st;
long val;
long ps1,ps2;
long span;
set<long> ::iterator it;
multiset<long>::iterator it1;
long val1,val2;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>w>>h>>n;

c1.insert(0);
c1.insert(h);
c2.insert(0);
c2.insert(w);
s1.insert(h);
s2.insert(w);
for (int i=1;i<=n;i++)
{
 cin>>st;
 cin>>val;
 if (st=="H")
 {
  it=c1.lower_bound(val);
  --it;
  ps1=(*it);
  ++it;
  ps2=(*it);
  span=ps2-ps1;
  it1=s1.find(span);
  s1.erase(it1);
  s1.insert(val-ps1);
  s1.insert(ps2-val);
  c1.insert(val);
 }
 else
 if (st=="V")
 {
  it=c2.lower_bound(val);
  --it;
  ps1=(*it);
  ++it;
  ps2=(*it);
  span=ps2-ps1;
  it1=s2.find(span);
  s2.erase(it1);
  s2.insert(val-ps1);
  s2.insert(ps2-val);
  c2.insert(val);
 } 
 it1=s1.end();
 --it1;
 val1=(*it1);
 it1=s2.end();
 --it1;
 val2=(*it1);
 cout<<1ll*val1*val2<<endl;
}

cin.get();cin.get();
return 0;}