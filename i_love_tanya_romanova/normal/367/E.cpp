/*
Suffer

Extreme pain is what they need to feel for the rest of their lives
Misery and despair leaves their souls when infinity ends

Let them taste the wrath as the agony consumes them
Swallowed by the darkest light a blackened state of dismay
Survival is the only thing left for them
This grievous revelation is a new beginning
Led to the solution against their will

Deprivation thrives as the therapy continues
Sullen mastery is an answer uncontested
Denial is the only thing left for them
Life as they knew it is a distant memory
Scores of victims lust for apathy

Make them suffer
While they plead for cessation
Entirely demoralized and close to mass extinction
Damned to please supremacy
The reason for their martyrdom they will never know

Make them suffer
While they bleed through damnation
Begged for retribution before meeting with demise
Cursed by animosity
Once chosen for this mad ordeal there is no escape

Domination reigns supreme the evil has no end
Spent of all their energy now worthless and degraded
Slow death is the only thing left for them
Physically and mentally devoid of dignity
Languished immortality

Make them suffer

While they plead for cessation
Entirely demoralized and close to mass extinction
Damned to please supremacy
The reason for their martyrdom they will never know

Make them suffer
While they bleed through damnation
Begged for retribution before meeting with demise
Cursed by animosity
Once chosen for this mad ordeal there is no escape

Make them suffer
Forever
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000

using namespace std;

long long ans;
long long dp[400][400],dp1[400][400];
long long n,m,x;

long solve(long ps,long op, long cl)
{
 if (op==n&&cl==n&&ps>x)return 1;
 if (ps==m)return 0;
 long ans=0;
 
 if (ps!=x)
 ans=(ans+dp[op][cl])%bs;
 if (cl<op&&ps!=x)
 ans=(ans+dp[op][cl+1])%bs;
 if (op<n)
 ans=(0ll+ans+dp[op+1][cl]+dp[op+1][cl+1])%bs;
 return ans;
}

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>x;
--x;
if (n>m){cout<<0<<endl;return 0;}

for (int i=m;i+1;i--)
{
 for (int op=0;op<=n;op++)
  for (int cl=0;cl<=op;cl++)
  {
   dp1[op][cl]=solve(i,op,cl);
  }
 for (int op=0;op<=n;op++)
  for (int cl=0;cl<=op;cl++)
  {
   dp[op][cl]=dp1[op][cl];
  }
}

ans=dp[0][0];
for (int i=2;i<=n;i++)
ans=(ans*i)%bs;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}