/*
I'm watching as the morning sun rises
before my very eyes
Revealing all this beauty
Questions fill my mind once again
clearing my thoughs have I been blind
Now I see

The hole is getting bigger in the sky
do you know the reason why nobody seems to care
Everything is so well in your life
did you ever give a dime
to things that you really believed
The future will show
what happens to our world

We hold the key to the door
of salvation eternally
We hold the key to minds
to the future of mankind

It's time to wake up from you dreams
to reality this can't go on believe me
If you just turn your head away
will tomorrow be the same
try to foresee
The future will show
what happens to our world

We hold the key to the door
of salvation eternally
We hold the key to minds
to the future of mankind

What will we find
mountains to climb
more destruction
and hatred we'll discover
Suddenly sounds awake me
birds singing beautifully
Maybe there is hope still left
in this world
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
vector<long> v;
void showw(long x)
{
     if (x<5)cout<<"O-|";else {x-=5;cout<<"-O|";}
     for (int i=0;i<x;i++)
     cout<<"O";
     cout<<"-";
     for (int i=x+1;i<5;i++)
     cout<<"O";
     cout<<endl;
}

int main(){
//freopen("gnu.in","r",stdin);
//freopen("gnu.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
while (n){v.push_back(n%10);n/=10;}
if (v.size()==0)v.push_back(0);

for (int i=0;i<v.size();i++)
showw(v[i]);

cin.get();cin.get();
return 0;}