/*
Take my life cause its already over

Were one year closer to the end of it all

Everyday I grow weaker
Wrapped up in the arms of fear
All this pains taking its toll
Not even gravity can keep me here

Take my life cause its already over
Just bury me just bury me
Take my life cause its already over
Just bury me put me six feet under ground

Were one year closer to the end of it all

Every second feels longer
Every minute feels lethal
Every hour screams death
Every day I die slowly

Take my life cause its already over
In my mind in my mind
Take my life cause its already over
My mind is running the thoughts are the same
Take my life cause its already over
Just bury me just bury me
Take my life cause its already over
Just bury me put me six feet under ground

Ground

One foot in the grave
Dont torture me this way
There is no escape

Were one year closer

Take my life cause its already over
In my mind in my mind
Take my life cause its already over
My mind is running the thoughts are the same
Take my life cause its already over
Just bury me just bury me
Take my life cause its already over
Just bury me put me six feet under ground

Were one year closer to the end of it all
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
#define eps 1e-17
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

struct state
{
 long x;long y;long a; long b;
};
state t;
long n,m,x,y,z,p,a,b;

state clc(state s)
{
 long a,b;
 a=s.b;
 b=s.x-s.a+1;
 swap(s.x,s.y);
 s.a=a;s.b=b;return s;
}

state rott(state s)
{
 s.b=s.y-s.b+1;
 return s;
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
   
cin>>n>>m>>x>>y>>z>>p;

for (int i=1;i<=p;i++)
{
 cin>>a>>b;
 t.x=n;t.y=m;t.a=a;t.b=b;
 for (int j=1;j<=x%4;j++)
  t=clc(t);
 for (int j=1;j<=y%2;j++)
  t=rott(t);
 for (int j=1;j<=4-(z%4);j++)
  t=clc(t);
  cout<<t.a<<" "<<t.b<<endl;
}
cin.get();cin.get();
return 0;}