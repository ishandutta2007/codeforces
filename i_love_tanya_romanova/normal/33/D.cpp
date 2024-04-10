/*
    
  -    
     
    
   -  
  
  
  
 ...

  
  
  
  
   
  
  
  
     
   
  
  
  ...

     
    
   
    
      
      
       
      
   
  
  
 ...

  
   
  
 
  
   
    
   
  
   
  
  
  ...

  
  
  
  
...
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
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long n,m,k,x[1<<20],y[1<<20],cx[1<<20],cy[1<<20],r[1<<20],d;
long ar[1<<10][1<<10];
long a,b,ans;

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
 cin>>x[i]>>y[i];

for (int i=1;i<=m;i++)
 cin>>r[i]>>cx[i]>>cy[i];//>>r[i];

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  d=(x[i]-cx[j])*(x[i]-cx[j])+(y[i]-cy[j])*(y[i]-cy[j]);
  if (d>r[j]*r[j])
   ar[i][j]=1;
   else 
   ar[i][j]=0;
 }

for (;k;--k)
{
 cin>>a>>b;
 ans=0;
 for (int i=1;i<=m;i++)
  ans+=(ar[a][i]^ar[b][i]);
 cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}