/*
Teenage angst has paid off well
Now I'm bored and old
Self-appointed judges judge
More than they have sold

If she floats then she is not
A witch like we had thought
A down payment on another one
At Salem's lot

Serve the servants, oh no
Serve the servants, oh no
Serve the servants, oh no
Serve the servants
That legendary divorce is such a bore

As my bones grew they did hurt
They hurt really bad
I tried hard to have a father
But instead I had a Dad

I just want you to know that
I don't hate you anymore
There is nothing I could say
That I haven't thought before

Serve the servants, oh no
Serve the servants, oh no
Serve the servants, oh no
Serve the servants
That legendary divorce is such a bore

Serve the servants, oh no
Serve the servants, oh no
Serve the servants, oh no
Serve the servants, oh no
Serve the servants, oh no
Serve the servants, oh no
Serve the servants
That legendary divorce is such a bore
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long long n,ar[300000],dp[300000][5][4],ans;

long odd[300000],even[300000];

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);


cin>>n;
for (int i=1;i<n;i++){
 cin>>ar[i];
 odd[i]=ar[i]-(ar[i]%2==0);
 even[i]=ar[i]-(ar[i]%2==1);}
 
for (int i=1;i<=n;i++)
 for (int seg=0;seg<=2;seg++)
  for (int used=0;used<=1;used++)
   dp[i][seg][used]=-1e9;

for (int i=1;i<=n;i++)
 dp[i][1][1]=0,
 dp[i][2][1]=0,
 dp[i][0][0]=0;
 
for (int i=1;i<n;i++)
{
 dp[i][1][1]=max(dp[i][1][1],dp[i][1][0]);
 dp[i][0][1]=max(dp[i][0][1],dp[i][0][0]);

 if (even[i])
  dp[i+1][0][0]=max(dp[i+1][0][0],dp[i][0][0]+even[i]);
 if (even[i])
  dp[i+1][2][0]=max(dp[i+1][2][0],dp[i][2][0]+even[i]);
 if (odd[i])
  dp[i+1][1][0]=max(dp[i+1][1][0],dp[i][1][0]+odd[i]);
  
 dp[i+1][1][0]=max(dp[i+1][1][0],dp[i][0][1]+odd[i]);
 dp[i+1][2][0]=max(dp[i+1][2][0],dp[i][1][1]+even[i]);
 
 for (int j=0;j<3;j++)
  for (int q=0;q<2;q++)
   ans=max(ans,dp[i][j][q]);
   
 for (int j=0;j<3;j++)
  for (int q=0;q<2;q++)
   ans=max(ans,dp[i+1][j][q]);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}