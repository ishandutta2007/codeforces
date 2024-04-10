/*
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000009
#define bsize 256
//#define N 120000

using namespace std;

long n,k,m,bad[1000];
double temp[501][501],temp1[501][501];
double g[501][501],deg[501];
double prob[501][501],p1[501][501];
long a,b;
double ans[501];
long ind[600];
long calc;
double answ;

void mult(double v[501][501], long n)
{
 //double temp[501][501],temp1[501][501];
 
 for (int i=0;i<n;i++)
  for (int j=0;j<n;j++)
   temp[i][j]=v[i][j],temp1[j][i]=v[i][j],v[i][j]=0;
 
 for (int i=0;i<n;i++)
  for (int j=0;j<n;j++)
   for (int k=0;k<n;k++)
    v[i][j]+=temp[i][k]*temp1[j][k];
 
for (int i=0;i<n;i++)
  for (int j=0;j<n;j++)
   if (v[i][j]<1e-100)
    v[i][j]=0;
}

void solve(double a[501][501],double b[501],long pw, long n)
{
 double temp[1000];
 
 while (pw>0)
 {
  if (pw&1)
  {
   for (int i=0;i<n;i++)
    temp[i]=0;
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
      temp[j]+=b[i]*a[j][i];
    for (int i=0;i<n;i++)
      b[i]=temp[i];
  }
  mult(a,n);
  pw/=2;
 }
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=0;i<n;i++)
 cin>>bad[i];

for (int i=0;i<m;i++)
{
 cin>>a>>b;
 --a,--b;
 g[a][b]++,g[b][a]++,
 deg[a]++,deg[b]++;
}
 
for (int i=0;i<n;i++)
 for (int j=0;j<n;j++)
  if (bad[i]==0)
   prob[i][j]=g[i][j]*1.0/deg[i];
  else prob[i][j]=(i==j);

for (int iter=1;iter<=16;iter++)
 mult(prob,n); // p nxt bad(i)=j;

/*for (int i=0;i<n;i++)
 {
  for (int j=0;j<n;j++)
   cout<<prob[i][j]<<" ";
  cout<<endl;
 }
*/

for (int i=0;i<n;i++)
 if (bad[i]) ind[i]=calc,++calc; else
 ind[i]=-1;
  
for (int i=0;i<n;i++)
 for (int j=0;j<n;j++)
  if (ind[i]>-1&&ind[j]>-1)
  {
   for (int k=0;k<n;k++)
   {
    if (ind[k]==-1)// intr
     p1[ind[i]][ind[j]]+=g[i][k]/deg[i]*prob[k][j];
   }
   p1[ind[i]][ind[j]]+=g[i][j]*1.0/deg[i];// strt mov
  }
  
for (int i=0;i<calc;i++)
 ans[i]=(i==ind[n-1]); 
/*
for (int i=0;i<calc;i++)
 {
  for (int j=0;j<calc;j++)
   cout<<p1[i][j]<<" ";
  cout<<endl;
 }
cout<<endl;
for (int i=0;i<calc;i++)
 cout<<ans[i]<<" ";
 */
solve(p1,ans,k-2,calc);
 /*
for (int i=0;i<calc;i++)
 cout<<ans[i]<<" ";
cout<<endl;
 */
 
answ=0;
for (int i=0;i<n;i++)
 if (bad[i])
  answ+=prob[0][i]*ans[ind[i]];

cout<<answ<<endl;

cin.get();cin.get();
return 0;}