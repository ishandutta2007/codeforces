/*
Bringing Satan's wine high on divine weed
A little bit religion is what everybody needs
Go away sad soul your lack of energy can be infectous
Hiding in the dark crawling on the knees
Is no life for a proud man and for sure no life for me

Try to have a laugh until the world goes down
Isn't it pathetic that the world is round
And nobody can push you off it easily
Not even your most wicked enemy
We could burn with never ending energy
Just cheer up a little if you will burn with me
And go away goddamn cellar soul
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

vector<long> v;
vector<long>::iterator it;
long n,ar[1<<20];
long long dp[1<<20];
long p[1<<20];
long val;

void check(long val,long ps)
{
 if (val>ps)return;
 if (val<1)return ;
 dp[ps]=max(dp[ps],dp[val-1]+abs(ar[ps]-ar[val]));
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int i=1;i<=n;i++)
{
 if (ar[i]>ar[i-1]&&ar[i]>ar[i+1])p[i]=1;
 if (ar[i]<ar[i-1]&&ar[i]<ar[i+1])p[i]=1;
 if (i==1)p[i]=1;
}

for (int i=1;i<=n;i++)
 if (p[i]==1)
  v.push_back(i);

for (int i=1;i<=n;i++)
 dp[i]=-1e9;

dp[0]=0;

for (int i=1;i<=n;i++)
{
 for (int j=i-1;j>=i-5&&j>0;j--)
  dp[i]=max(dp[i],dp[j-1]+abs(ar[i]-ar[j]));
 it=lower_bound(v.begin(),v.end(),i+1);
 for (int itr=1;itr<=5;itr++)
 {
  if (it==v.begin())break;
  --it;
  val=(*it);
  check(val,i);
  check(val-1,i);
  check(val+1,i);
//
  
 }
}

cout<<dp[n]<<endl;

cin.get();cin.get();
return 0;}