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
#define nice dhhssgsggsgsgs

using namespace std;

long n,k,li;
long a,b;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>k;
li=n*(n-1)/2;

if (k*n>li)
{
 cout<<-1<<endl;
}
else
{
 cout<<n*k<<endl;
 for (int i=1;i<=k;i++)
 {
  for (int j=0;j<n;j++)
  {
      a=j;
      b=j+i;
      b%=n;
      cout<<a+1<<" "<<b+1<<"\n";
  }
 }
}

cin.get();cin.get();
return 0;}