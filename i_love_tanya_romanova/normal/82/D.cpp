/*
Have you ever felt what means to long for night to come?
Have you felt the energy is burning hot?
Tell me just one better thing than people screaming
Tell me what is better that this stage

Notes fly free, sweat, savage bodies push eachothers and
Music turns into pure instinct
Too many times we have wondered and cried
We've been fighting while dreaming this stage
With our eyes shut
Now we are here there is not only
One little thing that is less precious
That the one in our dream...

You can never know the place
But we will always find
Sounds and lights on, as in dreams
You can only feel

Every word or note is made for all of you
For what you give to us during these years nad the ones to come

Heart and anger, fire burning
Heart and anger, power rising

"Every nomad got a home where every night his heart goes to sleep"
Tonight we're on stage, tonight on this stage
Just for this night you can be with us for real
Just for this night this can be your home with us
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long n,N,ar[1<<10],dp[1<<10][1<<10];
pair<pair<long, long> ,pair<long, long> > par[1<<10][1<<10];
long qx,qy;
pair<long, long> tp1,tp2;
vector<pair<long, long> > ans;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
N=n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

if (n%2==1)n++;

for (int i=0;i<=n+2;i++)
 for (int j=0;j<=n+2;j++)
  dp[i][j]=1e15;

dp[1][2]=0;

for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
 {
  if (dp[i][j+2]>dp[i][j]+max(ar[j],ar[j+1]))
  {
   dp[i][j+2]=dp[i][j]+max(ar[j],ar[j+1]);
   par[i][j+2]=make_pair(make_pair(i,j),make_pair(j,j+1));
  }
  if (dp[j][j+2]>dp[i][j]+max(ar[i],ar[j+1]))
  {
   dp[j][j+2]=dp[i][j]+max(ar[i],ar[j+1]);
   par[j][j+2]=make_pair(make_pair(i,j),make_pair(i,j+1));
  }
  if (dp[j+1][j+2]>dp[i][j]+max(ar[i],ar[j]))
  {
   dp[j+1][j+2]=dp[i][j]+max(ar[i],ar[j]);
   par[j+1][j+2]=make_pair(make_pair(i,j),make_pair(i,j));
  }
 }

cout<<dp[n+1][n+2]<<endl;

qx=n+1;
qy=n+2;
while (qx!=1||qy!=2)
{
 tp1=par[qx][qy].first;
 tp2=par[qx][qy].second;
 ans.push_back(tp2);
 qx=tp1.first;
 qy=tp1.second;
}

reverse(ans.begin(),ans.end());
for (int i=0;i<ans.size();i++)
{
 if (ans[i].first<=N)
 cout<<ans[i].first;
 if (ans[i].second<=N)
  cout<<" "<<ans[i].second;
  cout<<endl;   
}
cin.get();cin.get();
return 0;}