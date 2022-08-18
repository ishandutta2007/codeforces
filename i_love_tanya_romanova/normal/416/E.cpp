/*
I'm selling records
What is it that you do?
Sitting in your mama's basement with a shiatsu
Peanut butter on your dick
Right hand going click
With your left hand giving you a rim job
So now you wanna talk about me
Who's name is on the marque
You hate everything that you can't be
I've heard enough and scream!

You're just a sell-out, turn-coat rockstar!
Pussy, poser pornstar!

Because you're nothing but a wannabe
You're so easy when you're faceless
Why don't you focus on your misery?
Instead of focusing on me

So number two, that's right
What is it you're rolling?
Now that your mama's ford focus got stolen
Well, it don't matter because you got nowhere to go
So back to the hating, frantic masturbating
So now you wanna talk about me
You know the songs that you download for free
You hate everything that you can't be
I've heard enough and scream!
You're just a sell-out, turn-coat popstar!
Pussy, poser rockstar!

Because you're nothing but a wannabe
You're so easy when you're faceless
Why don't you focus on your misery?
Instead of focusing on me

So number two that's right
What is it you're rolling?
Now that your mama's ford focus got stolen
But, it don't matter because you got nowhere to go
So back to the hating, frantic masturbating
So now you wanna talk about me
So now you wanna talk about me

Because you're nothing but a wannabe
It's so easy when you're faceless
Why don't you focus on your misery?
Instead of focusing on me

Nothing but a wannabe
It's so easy when you're faceless
Why don't you focus on your misery?
Instead of focusing on me

I'm selling records
What is it that you do?
Sitting in your mama's basement
I'm selling records
What is it that you do?
Selling records.
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
#define bs 1000000007
#define bsize 256

using namespace std;

long n,m,dist[666][666],c[666][666],a[500000],b[500000],v[500000];
long ans[666][666],answ;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  dist[i][j]=c[i][j]=1e9;

for (int i=1;i<=m;i++)
{
 cin>>a[i]>>b[i]>>v[i];
 c[a[i]][b[i]]=min(c[a[i]][b[i]],v[i]);
 c[b[i]][a[i]]=min(c[b[i]][a[i]],v[i]);
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  dist[i][j]=c[i][j];
 
for (int i=1;i<=n;i++)
dist[i][i]=0;

for (int k=1;k<=n;k++)
 for (int i=1;i<=n;i++)
  for (int j=1;j<=n;j++)
   dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

for (int i=1;i<=n;i++)
 for (int k=1;k<=n;k++)
  for (int j=1;j<=n;j++)
   if (dist[i][j]<1e9&&dist[i][k]+c[k][j]==dist[i][j])
    ans[i][j]++;

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
 {
  if (j<=i)continue;
  answ=0;
  for (int k=1;k<=n;k++)
   if (dist[i][k]+dist[k][j]==dist[i][j])answ+=ans[i][k];
 if (i+j>3)cout<<" ";
 cout<<answ;}
 cout<<endl;
 
cin.get();cin.get();
return 0;}