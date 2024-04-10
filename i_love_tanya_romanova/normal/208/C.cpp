/*
You know that it would be untrue 
You know that I would be a liar 
If I was to say to you 
Girl, we couldn't get much higher 

Come on baby, light my fire 
Come on baby, light my fire 
Try to set the night on fire 

The time to hesitate is through 
No time to wallow in the mire 
Try now we can only lose 
And our love become a funeral pyre 

Come on baby, light my fire 
Come on baby, light my fire 
Try to set the night on fire, yeah 

The time to hesitate is through 
No time to wallow in the mire 
Try now we can only lose 
And our love become a funeral pyre 

Come on baby, light my fire 
Come on baby, light my fire 
Try to set the night on fire, yeah 

You know that it would be untrue 
You know that I would be a liar 
If I was to say to you 
Girl, we couldn't get much higher 

Come on baby, light my fire 
Come on baby, light my fire 
Try to set the night on fire 
Try to set the night on fire 
Try to set the night on fire 
Try to set the night on fire
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

long n,m,a,b,t,d[1500][1500]; double ways[1500][1500],mways;

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
d[i][j]=1000;

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 d[a][b]=d[b][a]=1;
 ways[a][b]=ways[b][a]=1;  
}

for (int k=1;k<=n;k++)
 for (int i=1;i<=n;i++)
  for (int j=1;j<=n;j++)
  {
   t=d[i][k]+d[k][j];
   if (t>d[i][j])continue;
   if (t<d[i][j])ways[i][j]=0;
   ways[i][j]+=ways[i][k]*ways[k][j];
   d[i][j]=t;   
  }

mways=ways[1][n];
for (int i=2;i<n;i++)
if (d[1][i]+d[i][n]==d[1][n])
mways=max(mways,2*ways[1][i]*ways[i][n]);

cout.precision(10);
if (n==0&&m==132)cout<<mways<<endl;
else cout<<1.0*mways/ways[1][n]<<endl;

cin.get();cin.get();
return 0;}