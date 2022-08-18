/*
You know the day destroys the night
Night divides the day
Tried to run
Tried to hide

Break on through to the other side
Break on through to the other side
Break on through to the other side, yeah

We chased our pleasures here
Dug our treasures there
But can you still recall
The time we cried?

Break on through to the other side
Break on through to the other side

Everybody loves my baby
Everybody loves my baby
She get, she get
She get, she get high

I found an island in your arms
Country in your eyes
Arms that chain
Eyes that lie

Break on through to the other side
Break on through to the other side
Break on through, auh, oh, yeah

Made the scene, week to week
Day to day, hour to hour
The gate is straight
Deep and wide

Break on through to the other side
Break on through to the other side
Break on through, break on through
Break on through, break on through
Hey hey hey hey
Hey hey hey hey hey
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

long n;
string st1[1<<18],st2[1<<18];
long q;
string cur,temp;
long have;
long er;

int main(){
//freopen("army.in","r",stdin);
//freopen("army.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>st1[i]>>st2[i];

cur="";
for (int i=1;i<=n;i++)
{
 cin>>q;
 have=0;
 temp="";
 if (st1[q]>cur)
 have=1,temp=st1[q];
 if (st2[q]>cur)
  if (have==0||st2[q]<st1[q])
   have=1,temp=st2[q];
 if (have==0)
 er=1;
 else cur=temp;
}

if (er)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}