/*
Why you deny, criticize
You deny, criticize
Don't feed me with your lies

Why you deny, crucified
You deny, crucified
Out of this world demise

Realize, realize
In this time, realize
My soul will rise

Realize, realize
In this time, realize
You can't fuck with the tribe

I and I, see the signs
I and I, in the sky
I and I, see the signs
I and I, in the sky

I and I, see the signs
I and I, in the sky
I and I, see the signs
I and I, in the sky, sky, sky
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

long n,m,sz[2000],ar[2000],s[2000],tsz,bst[105][105],
dp[105][10500];
long sum;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
{
 cin>>sz[i];
 for (int j=1;j<=sz[i];j++)
 {
  cin>>ar[j];
  s[j]=s[j-1]+ar[j];
 }
 for (int pref=0;pref<=sz[i];pref++)
  for (long suf=pref;suf<=sz[i];suf++)
  {
   tsz=pref+(sz[i]-suf);
   sum=s[pref]+s[sz[i]]-s[suf];
   bst[i][tsz]=max(bst[i][tsz],sum);
  }
}


for (int i=0;i<=n;i++)
 for (int j=0;j<=m;j++)
  dp[i][j]=-1e9;

dp[0][0]=0;
for (int i=0;i<n;i++)
 for (int j=0;j<=m;j++)
  for (int q=0;q<=sz[i+1];q++)
   dp[i+1][j+q]=max(dp[i+1][j+q],dp[i][j]+bst[i+1][q]);

cout<<dp[n][m]<<endl;

cin.get();cin.get();
return 0;}