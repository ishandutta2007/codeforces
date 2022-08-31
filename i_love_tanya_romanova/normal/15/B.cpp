/*
Always been the prophets who make the world evolve.
Always been the average breaking it down.
Majority, the unknown, giving us the rule.
It`s more than luck to get the standard.
You`ll never find me like I hope that I am.
You`ll never treat me like you think you can.
Be always independent, surrendering no way.
I won`t deal with crimes of society.
Now, if you hate it, you gotta fight it back.
You gotta fight it back.
Just try to change it.
Fight, fight it back.
Find myself in crisis, get near to collapse.
Am I forced to live that boring life?
God, I hate the average! Go and nuke it out.
Go piss the accepted; screw them all.
Now, if you hate it...
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

using namespace std;

long long n,m,x1,y1,x2,y2,tests,dx,dy,blind;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
 cin>>n>>m;
 cin>>x1>>y1>>x2>>y2;
 dx=abs(x1-x2);
 dx=n-dx;
 dy=abs(y1-y2);
 dy=m-dy;
 blind=dx*dy*2;
 if (2*dx>n&&2*dy>m)blind-=(2*dx-n)*(2*dy-m);
 cout<<n*m-blind<<endl;
}

cin.get();cin.get();
return 0;}