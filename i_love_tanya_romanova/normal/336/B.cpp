/*
There's a double standard for the way we live
If there's nothing to have, well then there's nothing to save
I'll break a sweat and I don't regret
What you'd kill to see brings out the god in me.

Come and be with me
Live my twisted dream
Pro devoted pledge
Time for primal concrete sledge

The man of a thousand retirements
Will always be the one to tell you when to quit
I won't take stock in a withered man
I'm reaching into you, I'll make you understand

Come and be with me
Live my twisted dream
Pro devoted pledge
Time for primal concrete sledge
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
#define clone agsdahfaassdg

using namespace std;

long m,r;
double dist;
double solve(double x)
{
 return x*(x+1)+2*sqrt(2.0)*x;
}
int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>m>>r;

for (int i=0;i<m;i++)
{
 dist+=2;
 if (i>0)dist+=2+sqrt(2.0);
 if (i+1<m)dist+=2+sqrt(2.0);
 if (i>1)
 {
  dist+=solve(i-1);
  
 }
 if (i+2<m)
 {
  dist+=solve(m-i-2);
 }
}

cout.precision(9);
cout<<fixed<<dist*r/m/m<<endl;

cin.get();cin.get();
return 0;}