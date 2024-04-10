/*
And you may tremble before hell's gates
You may watch as the heavens fall
And you may slight the hands of fate
You may heed the siren's call

And you may reach every golden shore
Witness repent in the heathen
And you may dance in the sands of the war
You may sleep in the cradle of Eden

Betrayed your prophets
Dead seeds buried deep
An army of none
We'll prey on the weak

And you may walk through the river run dry
You may strike down the giant with stone
And you may never again speak a lie
Confess every sin and atone

And you may drink from the infidel's blood
As their civilization collapses
You may rejoice in the cleanse of the flood
And stare into the face of apocalypse

Betrayed your prophets
Dead seeds buried deep
An army of none
We'll prey on the weak

You will not comprehend
Or find words that will describe
The will of God and man
Until you watch someone die

Betrayed your prophets
Dead seeds buried deep
An army of none
We'll prey on the weak
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long afl,x,y,ar[200][200],usd[200200],ans[200][200];
long n,m;

void solve(long x,long y)
{
 if (afl)return;
 if(x==n+1)
 {
  afl=1;
  for (int i=1;i<=n;i++)
  {
      for (int j=1;j<=m;j++)
      {if(j>1)cout<<" ";cout<<ar[i][j];}
      cout<<endl;
  }
  return;
 }
 for (int i=1;i<=n*m;i++)
 if (usd[i]==0)
 {
  if (abs(i-ar[x-1][y])!=1&&abs(i-ar[x][y-1])!=1)
  {
   usd[i]=1;
   ar[x][y]=i;
   if (y==m)solve(x+1,1);
   else solve(x,y+1);
   ar[x][y]=-1;
   usd[i]=0;
  }
 }
}

int main(){
//freopen("police.in","r",stdin);
//freopen("police.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=0;i<=n+1;i++)
for (int j=0;j<=m+1;j++)
ar[i][j]=-1;

solve(1,1);

if (afl==0)
cout<<-1<<endl;

cin.get();cin.get();
return 0;}