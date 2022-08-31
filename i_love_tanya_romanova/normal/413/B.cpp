/*
Let me hear - it loud and clear
A sound of steel that pierce my ears
This is my Achilles heal
I want an Overdose of steel

A lasting first impression
Right there I was crushed
By the sledge of rock (rock!)
By the sledge of rock (rock!)
I just can't seem to get enough
Of the sledge of rock (rock!)
Of the sledge of rock
Hit me! With the sledge of rock

It hit me right between the eyes
Addicted till the day I die
It's something i can't live without
Beyond the shadow of a doubt

A lasting first impression
Right there I was crushed
By the sledge of rock (rock!)
By the sledge of rock (rock!)
I just can't seem to get enough
Of the sledge of rock (rock!)
By the sledge of rock
Hit me!

May happen to heavy metal
But rock never rust. No!
Like a ton of bricks now are you
Ready to be crushed
By the sledge of rock...

By the sledge of rock (rock!)
I just can't seem to get enough
Of the sledge of rock
Hit me! With the sledge of rock
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

long n,m,k,t,sz[200000];
long a,b;
long long ans;
long moves[200000],tsub[200000];
vector<long> v[200000];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  cin>>t;
  sz[i]+=t;
  if (t)v[i].push_back(j);
 }

for (int i=1;i<=k;i++)
{
 cin>>a>>b;
 tsub[b]++;
 moves[a]++;
}

for (int i=1;i<=n;i++)
{
 a=-moves[i];
 for (int j=0;j<v[i].size();j++)
  {b=v[i][j];
  a+=tsub[b];
          }
  if (i-1)cout<<" ";
  cout<<a;
}
cout<<endl;

cin.get();cin.get();
return 0;}