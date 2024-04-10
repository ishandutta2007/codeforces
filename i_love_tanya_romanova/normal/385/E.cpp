/*
    
  ,
 ,     
   ...
    
  ,
  ,     
  ,    ...

:
       
 ! ,  !
       
 ...

    
  ,
 ,     
   !
    
  ,
  ,    ,
  ,    !

 (2)

   
  ...
   
  ...
     
  !
  ,
      ...
!



 !     
   ... ,  ...
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long long n;
long long sx,sy,dx,dy;
vector<vector<long long> > mtr;
long long t;
vector<long long> vec;

vector<vector<long long> > mult(vector<vector<long long > > a, vector<vector<long long> > b)
{
 vector<vector<long long> > res;
 res=a;
 for (int i=0;i<6;i++)
  for (int j=0;j<6;j++)
  res[i][j]=0;
  
 for (int k=0;k<6;k++)
  for (int i=0;i<6;i++)
   for (int j=0;j<6;j++)
   res[i][j]+=a[i][k]*b[k][j];
 
 for (int i=0;i<6;i++) 
  for (int j=0;j<6;j++)
   res[i][j]%=n;
  return res;
}

vector<vector<long long> > one()
{
 vector<vector<long long> > res;
 res.resize(6);
 for (int i=0;i<6;i++)
 res[i].resize(6);
 for (int i=0;i<6;i++)
  for (int j=0;j<6;j++)
   res[i][j]=(i==j?1:0);
   return res;
}

vector<vector<long long> > pw(vector<vector<long long> > a,long long b)
{
 if (b==0)return one();
 if (b%2)return mult(a,pw(a,b-1));
 return pw(mult(a,a),b/2);
}

long long res[20];

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

mtr.resize(6);
for (int i=0;i<6;i++)
mtr[i].resize(6);
for (int i=0;i<6;i++)
 for (int j=0;j<6;j++)
  mtr[i][j]=0;
  
mtr[0][0]=mtr[1][1]=2;
mtr[0][1]=mtr[0][2]=mtr[0][4]=mtr[1][0]=mtr[1][3]=mtr[1][4]=mtr[2][0]=mtr[2][1]=mtr[2][2]=
mtr[2][4]=mtr[3][0]=mtr[3][1]=mtr[3][3]=mtr[3][4]=mtr[4][4]=mtr[4][5]=mtr[5][5]=1;
/*
for (int i=0;i<6;i++)
{
    for (int j=0;j<6;j++)
    cout<<mtr[i][j]<<" ";
    cout<<endl;
}*/
cin>>n>>sx>>sy>>dx>>dy>>t;
mtr=pw(mtr,t);

vec.push_back(sx);vec.push_back(sy);
vec.push_back(dx);vec.push_back(dy);
vec.push_back(0);vec.push_back(1);

for (int k=0;k<6;k++)
for (int j=0;j<6;j++)
res[j]+=vec[k]*mtr[j][k];
/*for (int i=0;i<6;i++)
cout<<res[i]<<" ";
cout<<endl;
*/
res[0]%=n;
res[1]%=n;
if (res[0]<=0)res[0]+=n;
if (res[1]<=0)res[1]+=n;
cout<<res[0]<<" "<<res[1]<<endl;

cin.get();cin.get();
return 0;}