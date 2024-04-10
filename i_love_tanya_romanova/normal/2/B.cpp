/*
My cry echoes on a naked wall
Cold like a crystal
Numbered hours creeping
Insanity strangles reality

Weakened, crushed, formed
New dimensions arise
My mind becomes a fortress
Impregnable, shut

The walls between us make the public safe
Read my scars, see why I'm like that
Read my scars and don't ask me why

Whisper turns into a scream
Light would burn my skin
My legs, useless instruments
My eyes are almost blind

See the sunny world outside
Ignorant of the fact
Faking shock, forgetting fast
Freedom is a gift

Cry echoes on a naked wall
Cold like a crystal
Numbered hours creeping
Insanity strangles reality

The walls between us make the public safe
Read my scars, see why I'm like that
Read my scars and don't ask me why

The walls between us make the public safe
Read my scars, see why I'm like that
Read my scars and don't ask me why
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

long ar[1010][1010],par2[1010][1010],par5[1010][1010],dp2[1010][1010],dp5[1010][1010];
long n,m,a2[1010][1010],a5[1010][1010];

bool checkzero()
{
 long z=0;
 for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
   if (ar[i][j]==0)z=i;
 if (z==0)return false;
 cout<<1<<endl;
 for (int i=1;i<z;i++)
  cout<<"D";
 for (int i=1;i<n;i++)
  cout<<"R";
 for (int i=z;i<n;i++)
  cout<<"D";
  cout<<endl;
  return 1;
}

long qx,qy;
vector<string> ans;
void solve2()
{
 qx=n;
 qy=m;
 while (qx>1||qy>1)
 {
  if (par2[qx][qy]==1){ans.push_back("D");--qx;}
  else{
       ans.push_back("R");--qy;
       }
 }
 reverse(ans.begin(),ans.end());
 cout<<dp2[n][m]<<endl;
 for (int i=0;i<ans.size();i++)
  cout<<ans[i];
  cout<<endl;
}

void solve5()
{
 qx=n;
 qy=m;
 while (qx>1||qy>1)
 {
  if (par5[qx][qy]==1){ans.push_back("D");--qx;}
  else{
       ans.push_back("R");--qy;
       }
 }
 reverse(ans.begin(),ans.end());
 cout<<dp5[n][m]<<endl;
 for (int i=0;i<ans.size();i++)
  cout<<ans[i];
  cout<<endl;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
m=n;

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  cin>>ar[i][j];

for (int i=1;i<=n;i++)
{
 for (int j=1;j<=m;j++)
 {
  if (ar[i][j]==0)a2[i][j]=1;
  else
  {
   long q=ar[i][j];
   while (q%2==0){a2[i][j]++;q/=2;}
  }
  if (ar[i][j]==0)a5[i][j]=1;
  else
  {
   long q=ar[i][j];
   while (q%5==0){a5[i][j]++;q/=5;}
  }
 }
}

// 2's
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  dp2[i][j]=1e9;

dp2[1][1]=a2[1][1];
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  if (i+j==2)continue;
  if (i>1&&dp2[i-1][j]<dp2[i][j])
   dp2[i][j]=dp2[i-1][j],par2[i][j]=1;
  if (j>1&&dp2[i][j-1]<dp2[i][j])
   dp2[i][j]=dp2[i][j-1],par2[i][j]=2;
  dp2[i][j]+=a2[i][j];
 }

//5's
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  dp5[i][j]=1e9;
dp5[1][1]=a5[1][1];

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  if (i+j==2)continue;
  if (i>1&&dp5[i-1][j]<dp5[i][j])
   dp5[i][j]=dp5[i-1][j],par5[i][j]=1;
  if (j>1&&dp5[i][j-1]<dp5[i][j])
   dp5[i][j]=dp5[i][j-1],par5[i][j]=2;
  dp5[i][j]+=a5[i][j];
 }

if (dp2[n][m]>1&&dp5[n][m]>1)
{
 if (checkzero())return 0;
}

//cout<<dp5[n][m]<<endl;

if (dp2[n][m]<dp5[n][m])
solve2();
else
solve5();

cin.get();cin.get();
return 0;}