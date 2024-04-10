/*
I see the world, feel the chill
Which way to go, windowsill
I see the words on a rocking horse of time
I see the birds in the rain

Oh, dear dad, can you see me now
I am myself, like you somehow
I'll ride the wave where it takes me
I'll hold the pain release me

Oh, dear dad, can you see me now
I am myself, like you somehow
I'll wait up in the dark for you to speak to me
I'll open up release me, release me, release me, release me
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

double s,a,b,c;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>s;
for (int i=1;i<=10;i++)
 for (int j=1;j<=20;j++)
 {
  a=i*0.5;
  b=j;
  c=sqrt(a*a+b*b);
  c=a*b/c;
  if (fabs(c-s)<1e-6)
  {
   cout<<i<<" "<<j<<endl;
   return 0;
  }
 }
 
cin.get();cin.get();
return 0;
}