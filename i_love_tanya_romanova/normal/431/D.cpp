/*
Mama take a look at your boy
Face a man without a soul
He is standing in the doorway
I'll be gone, before the night is over
I have to go, I have to run to the border

Lost my way I run in desperation
Lost the words I lost communication

All I see is death beneath my window
All I need is to heal my broken mind
I will catch my own wounded shadow
Just before we leave it all behind

Mama keep the faith it's alright
Your boy's a mercenary man
A soldier made of steel
A shotgun rings; the wind is calling my name
Fields of gold beneath a blood red sky

Lost my way I run in desperation
Lost the words I lost communication

All I see is death beneath my window
All I need is to heal my broken mind
I will catch my own wounded shadow
Just before we leave it all behind

Just before we leave it all behind
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

long calc[100];
long cb(long x)
{
 long r=0;
 while (x){r+=x%2;x/=2;}
 return r;
}

long long l,r,m,k,mid;
long long dp[200][200][20];

long long gett(long long x)
{
long long n;
 vector<long> v;
 while (x){v.push_back(x%2);x/=2;}
 reverse(v.begin(),v.end());
 n=v.size();
/* for (int i=0;i<v.size();i++)
 cout<<v[i];
 cout<<endl;
 */
 for (int i=0;i<=n;i++)
  for (int j=0;j<=k;j++) 
   dp[i][j][0]=dp[i][j][1]=0;
 dp[0][0][0]=1;
 for (int i=0;i<n;i++)
  for (int j=0;j<=k;j++)
   for (int les=0;les<=1;les++)
    for (int adig=0;adig<=1;adig++)
    {
     if (les==0&&adig==1&&v[i]==0)continue;
     dp[i+1][j+adig][les|(adig<v[i])]+=dp[i][j][les];
     }
 return dp[n][k][0]+dp[n][k][1];
}

long long solve(long long x)
{
 long long a=gett(x*2);
 long long b=gett(x);
// cout<<x<<" "<<a<<" "<<b<<endl;
 return a-b;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

/*
for (int i=1;i<=100;i++)
{
 for (int j=1;j<=10;j++)
  calc[j]=0;
 for (int p=i;p<i*2;p++)
  calc[cb(p)]++;
 cout<<"  "<<i<<"  "<<cb(i)<<"%% ";
 for (int p=1;p<=10;p++)
  cout<<" "<<calc[p];
 cout<<endl;
}*/

cin>>m>>k;
l=1;
r=1e18;
while (l<r)
{
 mid=l+r;
 mid/=2;
 if (solve(mid)<m)l=mid+1;
 else r=mid;
}
cout<<l<<endl;

cin.get();cin.get();
return 0;}