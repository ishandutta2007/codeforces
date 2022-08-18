//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 201004
//#define szz 400
//#define pb push_back
using namespace std;
long n,q,ar[200000],ara[100][100],fl;
vector< long> v;

 void showw()
 {
      long ts=0;
      for (int i=0;i<n;i++)
      ts+=ara[0][i];
      cout<<ts<<endl;
      for (int i=0;i<n;i++)
{      for (int j=0;j<n;j++){
if (j)cout<<" ";cout<<ara[i][j];}
cout<<endl;}
}


bool check ()
{
     //showw();
     if (fl)return false;
     long ts,s;
   ts=0;  for (int i=0;i<n;i++)
     ts+=ara[0][i];
     
     for (int i=0;i<n;i++)
     {s=0;
      for (int j=0;j<n;j++)s+=ara[i][j];
       if (s!=ts)return false;}
     for (int i=0;i<n;i++)
     {s=0;
      for (int j=0;j<n;j++)s+=ara[j][i];
       if (s!=ts)return false;}
     s=0;
     for (int i=0;i<n;i++)
     s+=ara[i][i];
     if (s!=ts)return false;
     s=0;
     for (int i=0;i<n;i++)
     s+=ara[n-i-1][i];
     if (s!=ts)return false;
   fl=1;  return true;
 }

int main(){
//freopen("input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n;

for (int i=0;i<n*n;i++)
{cin>>q;v.push_back(q);
}
for (int i=0;i<n*n;i++)
{
    ar[i]=i+1;
    }

for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
ara[i][j]=v[ar[(i*n)+j]-1];

if (check())
{showw();}

while(next_permutation(ar,ar+n*n))
{
for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
ara[i][j]=v[ar[(i*n)+j]-1];
if (check())
{showw();}
                                         
                                         }
cin.get();cin.get();
return 0;}