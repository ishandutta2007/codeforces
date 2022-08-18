/*
  ,       
     
     
       
   ,    
     
           
     

:
     , 
      , 
   ,  , 
 , ,    
 ,       
   ,    
    , 

,       : "How much?"
,        
 ,   ,   
 ,    ,  ,    
     ,      
       
 : "  ,    "
   ,   



     , 
      , 
   ,  , 
 , ,     (x2)


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

long n,m;
long ar[200][200],obad[200],bad[200][200],acol,aval,qcol;

bool check(long x,long y,long cl)
{
 for (int p=1;p<cl;p++)
  if (ar[x-1][y]!=p&&ar[x][y-1]!=p)return false;
  return true;
}
 
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (long i=1;i<=n;i++) 
 for (long j=1;j<=m;j++)
 {
  if (ar[i][j])continue;
  
   for (int span=0;span<=100;span++)
    for (int col=1;col<=26;col++)
     bad[span][col]=0;
     
   for (int col=1;col<=26;col++)
    bad[min(n-i+2,m-j+2)][col]=1; // out
   for (int span=1;span<=100;span++)
    obad[span]=0;
    
  for (int p=i;p<=n;p++)
   for (int q=j;q<=m;q++)
   {
    if (ar[p][q]==0)continue;
    obad[max(p-i+1,q-j+1)]=1;// cvrd
    bad[max(p-i,q-j)][ar[p][q]]=1;//ld brd
   }
  
  for (int p=i;p<=n;p++)
   bad[p-i+1][ar[p][j-1]]=1;// lb
  for (int p=j;p<=m;p++)
   bad[p-j+1][ar[i-1][p]]=1;// ubpq
  acol=0;aval=0;
  qcol=1;
  while (true)
  {
   if (bad[1][qcol]==1){++qcol;continue;}
   acol=qcol;
   aval=1;
   
   while (true)
   {
   if (check(i,j+aval,acol)==1&&bad[aval+1][qcol]==0&&obad[aval+1]==0)++aval;
   else break;
   }

   break;
  }
//  cout<<i<<" "<<j<<" "<<acol<<" "<<aval<<endl;
  for (int p=i;p<i+aval;p++)
   for (int q=j;q<j+aval;q++)
    ar[p][q]=acol;
 }

for (int i=1;i<=n;i++)
{
 for (int j=1;j<=m;j++)
  cout<<char('A'-1+ar[i][j]);
  cout<<endl;
}

cin.get();cin.get();
return 0;}