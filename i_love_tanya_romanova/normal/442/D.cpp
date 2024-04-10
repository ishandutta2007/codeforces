/*
Now, is your time to die
We've gathered here to say goodbye
No, more, you'll cry
No reason left for you to fight

Feel, pain, no more
Emotions never felt before
Where, do, we go
We go, she'll never know

Holding on to you, to keep from falling
Your eyes are closing now
Another chapter's ending

Hard, times, we always saw
There's nothing left of you no more
Fear, has, no place, no place
Cover her face

Holding on to you, to keep from falling
Your eyes are closing now
Another chapter's ending

This is our last goodbye (goodbye!)
This is our time tonight

Holding on to you!

Cover up her face!

Holding on to you... To keep from falling!

Holding on to you, to keep from falling
Your eyes are closing now
Another chapter's ending

This is our last goodbye (goodbye!)
This is our time tonight (goodbye!)

This is our last goodbye!
*/

#pragma comment(linker, "/STACK:16777216")
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

long n,most[1200000][2],dp[1200000],v;
long p[1200000],temp;
vector<long> ans;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n+1;i++)
{
 most[i][0]=most[i][1]=1e6+1e4;
}

for (int i=2;i<=n+1;i++)
{
 cin>>p[i];
}

for (int i=2;i<=n+1;i++)
{
 dp[i]=1;
 v=i;
 while (v>1)
 {
  if (dp[v]>dp[most[p[v]][0]])
  most[p[v]][1]=most[p[v]][0],most[p[v]][0]=v;
  else if (v!=most[p[v]][0]&&dp[v]>dp[most[p[v]][1]])
   most[p[v]][1]=v;
  
  v=p[v];
  temp=dp[v];
  if (v>1)dp[v]=max(dp[most[v][0]],dp[most[v][1]]+1);
  else // root
       dp[v]=dp[most[v][0]];
  if (dp[v]==temp)break;// e upd
 }
 ans.push_back(dp[1]);
}

for (int i=0;i<ans.size();i++)
{
 if (i)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}