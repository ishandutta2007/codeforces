/*
    
    ,
     ,
    .
   ,
    ,
    ,
 .

  ,
  ,
     ,
  .
  ,
   ,
    
  .

    ,
    ,
     ,
   .
    ,
    ,
    ,
 .

  ,
  ,
     ,
  .
  ,
   ,
    
  .

    -
  ,
    ,
     .

    - 
  ,
   ,
     .

    -
  ,
    ,
     .

    - 
  ,
   ,
     .

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
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,a,b,c,ans,s[20000];

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b>>c;
 s[a]-=c;s[b]+=c;   
}

for (int i=1;i<=n;i++)
ans+=abs(s[i]);
cout<<ans/2<<endl;

cin.get();cin.get();
return 0;}