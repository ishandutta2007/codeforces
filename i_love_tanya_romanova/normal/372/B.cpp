/*
Awoke in a fever, a feeling that's never been here before
Staring at these walls knowing you're right outside the door
See through me, point your words and make me shiver
This time I know we will go down trying to reconcile 

Waiting here for you to save me
Stranded here with my vague illusions and broken dreams
One more time around so degraded
Running in circles these days of endless guilt

There were reasons
There were moments
Reach to me and lead me astray 

As the night breathes out the harsh and cold morning
A smoke screen has surrounded the funeral mourners
They march in the wake of broken promises
This time they know we all fall into the rhythm so slow
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256
#define double long double

using namespace std;

long n,m,ar[200][200];
string st;
long s[50][50];
long ts;
long ok[45][45][45][45];
long ans[45][45][45][45];
long tests,a,b,c,d;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>tests;

for (int i=1;i<=n;i++)
{
    cin>>st;
    for (int j=1;j<=m;j++)
    {
        if (st[j-1]=='1')ar[i][j]=1;
        else ar[i][j]=0;
    }
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+ar[i][j]; // tq oF

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  for (int q=i;q<=n;q++)
   for (int w=j;w<=m;w++)
   {
    ts=s[q][w]-s[i-1][w]-s[q][j-1]+s[i-1][j-1];
    if (ts==0)
    ok[i][j][q][w]=1; // aD+
   }

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  for (int q=i;q<=n;q++)
   for (int w=j;w<=m;w++)
   {
       ans[i][j][q][w]=ans[i][j][q-1][w]+ans[i][j][q][w-1]-ans[i][j][q-1][w-1]+ok[i][j][q][w];
       // sp 1 +Qd
   }

for (int q=n;q;--q)
 for (int w=m;w;--w)
  for (int i=q;i;--i)
   for (int j=w;j;--j)
    ans[i][j][q][w]=ans[i][j][q][w]+ans[i+1][j][q][w]+ans[i][j+1][q][w]-ans[i+1][j+1][q][w];// tdq
    
for (;tests;--tests)
{
    cin>>a>>b>>c>>d;
    cout<<ans[a][b][c][d]<<endl;
}
cin.get();cin.get();
return 0;}