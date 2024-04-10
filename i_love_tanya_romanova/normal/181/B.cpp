/*
Vacate is a word
Vengeance has no place so near to her
Cannot find a comfort
In this world

Artificial tears
The vessel's stabbed
Next up, volunteers
Vulnerable, wisdom can't adhere

A truant finds home
And a will to hold on
There's a trapdoor in the sun
It's immortality

As privileged as a whore
Victims in demand for public show
Swept out through the cracks
Beneath the door

Holier than thou, how?
Surrendered, executed anyhow
Scrawls dissolved
Cigar box on the floor

A truant finds home
And a will to hold on to
There's a trapdoor in the sun

It's immortality

I cannot stop the thought
Running out the door
Coming up a which way sign
And all good truants must decide

Oh, stripped and sold, mom
And an auctioned forearm
And whiskers in the sink

A truant finds home
And a will to hold on to
Some die just to live, oh
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long ans;
bool have[5050][5050];
long x[1<<20],y[1<<20],mx,my;
long n;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>x[i]>>y[i];
 x[i]=x[i]*2+2000;
 y[i]=y[i]*2+2000;
 have[x[i]][y[i]]=1;
}

for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
 {
  mx=x[i]+x[j];
  my=y[i]+y[j];
  mx/=2;
  my/=2;
  if (have[mx][my])
   ++ans;
 }

cout<<ans<<endl;

cin.get();cin.get();
return 0;}