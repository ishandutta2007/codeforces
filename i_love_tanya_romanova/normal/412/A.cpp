/*
Dying swans, twisted wings, beauty not needed here
Lost my love, lost my life, in this garden of fear
I have seen many things, in a lifetime alone
Mother love is no more, bring this savage back home

Wilderness, house of pain, makes no sense of it all
Close this mind, dull this brain, Messiah before his fall
What you see, is not real, those who know will not tell
All is lost, sold your souls, to this brave new world

A brave new world, in a brave new world
A brave new world, in a brave new world
In a brave new world, a brave new world
In a brave new world, a brave new world

Dragon kings, dying queens, where is salvation now?
Lost my life, lost my dreams, rip the bones from my flesh
Silent screams laughing here, dying to tell you the truth
You are planned and you are damned in this brave new world

A brave new world, a brave new world
A brave new world, a brave new world
In a brave new world, a brave new world
In a brave new world, a brave new world

A brave new world, a brave new world
A brave new world, a brave new world
In a brave new world, a brave new world
In a brave new world, a brave new world

Dying swans, twisted wings, bring this savage back home
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
#define bsize 256

using namespace std;

string st;
long n,k,ps;

void solve(long x)
{
 cout<<"PRINT "<<st[x-1]<<endl;
}
void move(long d)
{
 k+=d;
 if (d<0)cout<<"LEFT"<<endl;
 else cout<<"RIGHT"<<endl;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>k;
cin>>st;

if (k==1)
{
 solve(1);
 for (int i=2;i<=n;i++)
 {move(1);solve(k);}
}
else if (k==n)
{
 solve(n);
 for (int i=n-1;i>=1;--i)
 {
  move(-1);solve(k);
 }
}
else if (k-1<n-k)
{
 ps=k+1;
 solve(k);
 for (int i=k-1;i>=1;--i)
 {
  move(-1);solve(k);
 }
 for (int i=2;i<ps;i++)
 {
  move(1);
 }
 for (int i=ps;i<=n;i++)
 {
  move(1);solve(k);
 }
}
else 
{
 ps=k-1;
 solve(k);
 for (int i=k+1;i<=n;++i)
 {
  move(1);solve(k);
 }
 for (int i=n-1;i>ps;i--)
 {
  move(-1);
 }
 for (int i=ps;i>=1;i--)
 {
  move(-1);solve(k);
 }
}
cin.get();cin.get();
return 0;}