/*
Lately when my demons drag the night across my eyes
I just can't seem to fight it anymore
Yield unto temptation and be ruler of the world
But it seems that I have heard that song before

And the voices begin to sing - Come home

I have seen some evil as I've walked upon the earth
But this is way beyond what eyes can see
Wicked is as wicked does and if I lose control
Is this the way that hell is gonna be

Have I fallen too far to rise
Been burning too long in the fire
Then it all falls down - Tearing the night away

It must be - Fever dreams
Fever dreams
Fever dreams

Now before my demons roll the night across my eyes
I tremble as I wait perhaps to sin
Yield unto temptation and be ruler of the world
And all I do is let the beast come in

Have I fallen too far to rise
I've been standing too long in the fire
Let it all fall down
Tearing the night away

It must be - Fever dreams
From the outside - Fever dreams
Oh, fever dreams
Fever dreams
Ooh-ooh

Fever dreams
Fever dreams
Fever dreams
Fever dreams
Fever dreams
Fever dreams
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,m,a,b,A[500000],B[200000],add[500000];
long ai,aj;
double answ;
long l,r,m1,m2;

double gdist(double x1,double y1,double x2,double y2)
{
 double res=((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
 res=sqrt(res);
 return res;
}

double check(long aa,long bb)
{
 double res=add[aa];
 res+=gdist(0,0,a,A[bb]);
 res+=gdist(a,A[bb],b,B[aa]);
 return res;
}

int main(){
//freopen("experimental.in","r",stdin);
//freopen("experimental.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>a>>b;

for (int i=1;i<=n;i++)
{
 cin>>A[i];
}

for (int i=1;i<=m;i++)
{
 cin>>B[i];
}

for (int i=1;i<=m;i++)
cin>>add[i];

answ=1e15;

for (int i=1;i<=m;i++)
{
 l=1;
 r=n;
 while (l<r-5)
 {
  m1=(r-l)/3;
  m2=2*m1;m1+=l;m2+=l;
  if (check(i,m1)<check(i,m2))
  {
   r=m2;
  }
  else
  {
   l=m1;
  }
 }
 for (int j=l;j<=r;j++)
 {
  if (check(i,j)<answ)
  {
   answ=check(i,j);
   ai=i;aj=j;
  }
 }  
}

cout//<<answ<<" "
<<aj<<" "<<ai<<endl;

cin.get();cin.get();
return 0;}