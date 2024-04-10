/*
Why do you stare at me?
It's hard to please when you're
feeling ill at ease
Hey let it go
You have feelings inside let them show

Grim craven mind
Timid all the time
Can't come out of your shell
It's hell

Shame on you
There are so many things that you could do
Hey can't you see?
Love is a stream that endlessly flows in me

Grim craven mind
Timid all the time
Can't come out of your shell
It's hell

It's time to break the ice
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

double x1,y1,x2,y2,r1,r2,d;

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>x1>>y1>>r1;
cin>>x2>>y2>>r2;
d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
d=sqrt(d);
/*d-=r1;d-=r2;
if (d<0)d=0;
cout.precision(9);
cout<<fixed<<d/2<<endl;
*/
if (d<r1+r2&&d>fabs(r1-r2))d=0;
else if (d<fabs(r1-r2))d=fabs(r1-r2)-d;
else d=d-r1-r2;
cout<<fixed<<d/2<<endl;
cin.get();cin.get();
return 0;}