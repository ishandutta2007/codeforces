/*
Every second's soaked in sadness
Every weekend is a war
And I'm drowning in the deja vu
We've seen it all before

I don't wanna do this by myself
I don't wanna live like a broken record
I've heard these lines a thousand times
And I've seen it all before

Are we close enough?
There is something I must confide
I think we've lost our touch
There's no sparkle in those eyes

What an awful mess I've made
There's nothing left to save

Every second's soaked in sadness
Every weekend is a war
And I'm drowning in the deja vu
We've seen it all before

I don't wanna do this by myself
I don't wanna live like a broken record
I've heard these lines a thousand times
And I've seen it all before

(There's nothing in the air tonight...)

Every second's soaked in sadness
Every weekend is a war
And I'm drowning in the deja vu
We've seen it all before

I don't wanna do this by myself
I don't wanna live like a broken record
I've heard these lines a thousand times
And I've seen it all before

I'm sorry, no... it's not enough
We shouldn't feel a love so painfully
It hurts right to the touch
I know it stings, I know this cuts
And I wish I could agree with you
But fuck this love, it's not enough

It's not enough...
It's not enough...
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000

using namespace std;

long x[2000],y[2000],can[2000],r[2000],ans;

bool inter(long a,long b)
{
 double dd=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
 dd=sqrt(dd);
// cout<<r[a]<<" "<<r[b]<<" "<<dd<<endl;
 
 if (r[a]+r[b+1]<=dd)
 return false;
 if (r[a]+dd<=r[b])return false;
 if (r[b+1]+dd<=r[a])return false;
 return true;
}

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=4;i+=2){
cin>>x[i]>>y[i]>>r[i];
x[i+1]=x[i];y[i+1]=y[i];cin>>r[i+1];}

for (int i=1;i<=4;i++)
can[i]=1;

for (int i=1;i<=4;i++)
 for (int j=1;j<=3;j+=2)
  if (inter(i,j)==1&&i!=j)
   {//cout<<i<<" "<<j<<endl;
   can[i]=0;}

for (int i=1;i<=4;i++)
ans+=can[i];
cout<<ans<<endl;

cin.get();cin.get();
return 0;}