/*
Infiltrate them
Disintegrate them
Terminate my fire
Create your own desire

Don't let them drag you under
Towards their paradise
I am the fallen angel
The only one am I

Be my dream this night
Hide me from daylight
Shelter me all times
Hide me from the light

Help me free you
Save yourselves from their eyes
See what holds you
And controls you

Infiltrate them
Disintegrate them
Terminate my fire
Create your own desire

And now the stage is falling
Towards their own demise
Don't look to me for answers
To questions I despise

Be my dream this night
Hide me from daylight
Shelter me all times
Hide me from the lines

Falling down
Crawling down

Deeper into the surreal landscape
Interlocking this dream reality
Remind me to remember to forget
My vast collection of memories

But they will paralyze you
To hide the things they do
The scene is set for freedom
So slip away from me

Be my dream this night
Hide me from daylight
Shelter me all times
Hide me from the lines

Falling down
I'm crawling down
Falling down
I'm crawling down
Falling down
I'm crawling down
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

string st;
long n,m,dp[525][30][30];
pair<long, long> par[525][30][30];
pair<long, long> bp;
long bst;
long calc[525][10][30];
long tc;
pair<long,long> ans[200];

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=0;j<st.size();j++)
 {
  calc[i][j%2][st[j]-'a']++;
 }
}

for (int i=1;i<=n;i++)
 for (int l1=0;l1<=26;l1++)
  for (int l2=0;l2<=26;l2++)
   dp[i][l1][l2]=1e9;

for (int i=0;i<n;i++)
 for (int c1=0;c1<26;c1++)
  for (int c2=0;c2<26;c2++)
   for (int n1=0;n1<26;n1++)
    for (int n2=0;n2<26;n2++)
    {
     if (n1==n2)continue;
     if (n1==c1)continue;
     if (n2==c2)continue;
     tc=dp[i][c1][c2]+m-calc[i+1][0][n1]-calc[i+1][1][n2];
     if (dp[i+1][n1][n2]>tc)
     {
      dp[i+1][n1][n2]=tc;
      par[i+1][n1][n2]=make_pair(c1,c2);
     }
    }

bst=1e9;

for (int i=0;i<26;i++)
 for (int j=0;j<26;j++)
  if (dp[n][i][j]<bst)
  {
   bst=dp[n][i][j];
   bp=make_pair(i,j);
  }
  
cout<<bst<<endl;

for (int i=n;i;--i)
{
 ans[i]=bp;
 bp=par[i][bp.first][bp.second];
}

for (int i=1;i<=n;i++)
{
 for (int j=0;j<m;j++)
 {
  if (j%2==0)cout<<char(ans[i].first+'a');
  else cout<<char(ans[i].second+'a');
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}