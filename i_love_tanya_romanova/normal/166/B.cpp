/*
Out of your door
There i a stair made of gems
Each one of them
Is a dream to believe in

Future is written
Written for every on of us
Maybe I'll change it
Now that you're not the same I knew

The days have passed now
Many years are passing by my side
They leave me here alone
So all I can see is sand in the wind

Before my eyes
There are many choices
Some may be easier
This ways to walk on

Future is written
Written for every on of us
Maybe I'll change it
Now that you're not the same I knew

The days have passed now
Many years are passing by my side
They leave me here alone
So all I can see is sand in the wind

Looking the future
With sorrow in the eyes
Shaking with terror
We know we must fight

Future is written
Written for every on of us
Maybe I'll change it
Now that you're not the same I knew

The dreams are goin' away
Many tears have fallen from my eyes
They leave me here again
So all I can see is sand in the wind
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
 
using namespace std;

long long n,x[1<<20],y[1<<20],er,m,tx,ty,l,r;
long long mid;
long long s1,s2;

long long get(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
 long long s=(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
// if (s==0)er=1;
 return fabs(s);
}

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>x[i]>>y[i];
}

er=0;
cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>tx>>ty;
 l=2;
 r=n;
 while (l<r)
 {
  mid=l+r+1;
  mid/=2;
  if ((tx-x[1])*(y[mid]-y[1])-(ty-y[1])*(x[mid]-x[1])>0)
   l=mid;
   else r=mid-1;
 }
 if (l==n)er=1;
 s1=get(x[1],y[1],x[l],y[l],x[l+1],y[l+1]);
 s2=get(x[1],y[1],x[l],y[l],tx,ty)+get(x[l],y[l],tx,ty,x[l+1],y[l+1])+
 get(x[1],y[1],x[l+1],y[l+1],tx,ty);
 if (get(x[l],y[l],tx,ty,x[l+1],y[l+1])==0)er=1;
 if (l==2&&get(x[1],y[1],tx,ty,x[l],y[l])==0)er=1;
 if (l==n-1&&get(x[1],y[1],tx,ty,x[l+1],y[l+1])==0)er=1;
 if (s1!=s2)er=1;
// cout<<s1<<"  "<<s2<<endl;
}

if (er)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}