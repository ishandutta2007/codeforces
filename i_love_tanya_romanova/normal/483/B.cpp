/*
Every fucking day the world falls on me
I'm closer to suicide
The last light of my life will stop shining, I want to die
I'm dreaming of an underworld
Where I can sleep forever
I hope that demons answer to my call

You whip my mind to believe in dark forces
It's the only way to survive

I don't know who I am, what to believe
I have no guts to take my life

All this suffering between death and misery
Where I can find myself going deeper and deeper
Through my sinful past

You whip my mind to believe in dark forces
It's the only way to survive

I'm dreaming of an underworld
I hope that demons answer to my call

I'm dreaming of an underworld
Where I can sleep forever
I hope that demons answer to my call

You whip my mind to believe in dark forces
It's the only way to survive
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long long a,b,x,y,l,r,mid;

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b>>x>>y;
l=a+b-1;
r=1e15;
while (l<r)
{
 mid=l+r;
 mid/=2;
 if (a<=mid-mid/x&&b<=mid-mid/y&&a+b<=mid-mid/(x*y))
  r=mid;
 else l=mid+1;
}

cout<<l<<endl;

cin.get();cin.get();
return 0;}