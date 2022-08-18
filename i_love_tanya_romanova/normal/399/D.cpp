/*
I lie here paraletic inside this soul
screaming for you 'til my throat is numb
I wanna break out
I need a way out
I dont believe that its gotta be this way
The worst is the waiting
In this womb Im suffocating

Feel your presence filling up my lungs with oxygen
I take you in
Ive died

Rebirthing now
I wanna live for love wanna live for you and me
Breathe for the first time now
I come alive somehow
Rebirthing now
I wanna live my life wanna give you everything
Breathe for the first time now
I come alive somehow

Right now
Right now

I lie here lifeless in this cocoon
Shedding my skin cause Im ready to
I wanna break out
I found a way out
I dont believe that its gotta be this way
The worst is the waiting
In this womb Im suffocating

Feel your presence filling up my lungs with oxygen
I take you in
Ive died

Rebirthing now
I wanna live for love wanna live for you and me
Breathe for the first time now
I come alive somehow
Rebirthing now
I wanna live my life wanna give you everything
Breathe for the first time now
I come alive somehow

Tell me when Im gonna live again
Tell me when Im gonna breathe you in
Tell me when Im gonna feel inside
Tell me when Im gonna feel alive

Tell me when Im gonna live again
Tell me when this fear will end
Tell me when Im gonna feel inside
Tell me when Ill feel alive

Rebirthing now
I wanna live for love wanna live for you and me
Breathe for the first time now
I come alive somehow
Rebirthing now
I wanna live my life wanna give you everything
Breathe for the first time now
I come alive somehow

Right now
I come alive somehow
Right now
I come alive somehow
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
//#define bs 1000000007
#define bsize 256

using namespace std;

long n,m,a,b;
set<long> s1,s2;
long c1,c2;
double ev;
double dp[2500][2500];

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 s1.insert(a);
 s2.insert(b);
}

c1=n-s1.size();
c2=n-s2.size();

dp[0][0]=0;
for (int i=0;i<=c1;i++)
 for (int j=0;j<=c2;j++)
 {
  ev=n*n;
  if (i+j==0)continue;
  if (i>0)ev+=dp[i-1][j]*i*(n-j);
  if (j>0)ev+=dp[i][j-1]*j*(n-i);
  if (i>0&&j>0)ev+=dp[i-1][j-1]*i*j;
  dp[i][j]=ev*1.0/n/n;
  dp[i][j]/=(1.0-(n-i)*(n-j)*1.0/n/n);
 }
/*
for (int i=0;i<=c1;i++)
{
 for (int j=0;j<=c2;j++)
 cout<<dp[i][j]<<" ";
 cout<<endl;
}
*/
cout.precision(12);

cout<<fixed<<dp[c1][c2]<<endl;

cin.get();cin.get();
return 0;}