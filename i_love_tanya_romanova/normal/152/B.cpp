/*
Every little baby comes into the world
Reaching for an anchor, fingers tightly curled
Grasping for a reason without knowing why
We will cling to anything till the day we die

We can hold on to sorrow, hold on to pain
We can hold on to anger when there is nothing to be gained
We can hold to a thread at the end of a rope
But if we hold on to Jesus we are holding on to hope

Hold on, hold on

This is human nature, this is what He planned
When He put our hearts inside, when He made these hands
We are here to reach for Him, never letting go
This is all we need to have, all we need to know

We can hold on to money, hold on to fame
We can hold on to glory and the honor of a name
We can hold to a thread at the end of a rope
But if we hold on to Jesus we are holding on to

Hold on to hearts
Hold on to wisdom and grace
Hold on to mercy and love
Hold on

We can hold on to sorrow, hold on to pain
We can hold on to anger when there is nothing to be gained

We can hold on to money, hold on to fame
We can hold on to glory and the honor of a name
We can hold to a thread at the end of a rope
But if we hold on to Jesus, if we hold on to Jesus
If we hold on to Jesus we are holding on to hope

Hold on, hold on
Go on, hold on, hold on
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

using namespace std;

long long n,m,x1,y1,tests,dx,dy,l,r,mid,ans;
long long tx,ty;

bool cmove(long iters)
{
 tx=x1+iters*dx;
 ty=y1+iters*dy;
 return (tx>0&&ty>0&&tx<=n&&ty<=m);
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
cin>>x1>>y1;

cin>>tests;
for (;tests;--tests)
{
 cin>>dx>>dy;
 l=0;
 r=1e9;
 while (l<r)
 {
  mid=l+r+1;
  mid/=2;
  if (cmove(mid))l=mid;
  else r=mid-1;
 }
// cout<<"%"<<l<<endl;
 ans+=l;
 x1+=dx*l;
 y1+=dy*l;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}