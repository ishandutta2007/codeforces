/*
What do you think they would say
If I stood up and I walked away
Nobody here really understands me
And so I'll wave goodbye I'm fine
And I'm fine

Tones of home
Said you don't like the way I'm living
Tones of home
Tones of home
And so I wave goodbye
I'm flyin', and I'm flyin' home, home, home, home

But I always thought this would be
We'll see the land of milk and honey
Oh but I come to find out
That it's all hate and money
And there's a canopy of greed holding me down

Tones of home
Said, you don't like the way I'm living
Tones of home
Tones of home
And so I wave goodbye
And I'm flyin', and I'm flyin', I'm home

See I'm so high to you, but I'll fade away
I said you're on your own

Your mom and daddy said
That your sister said
And your brother's saying
They're saying everybody
They're saying everybody
Is sayin' I, I, I

All my friends patronize me
And they say, "Yo, hey boy
Have you found what you're looking for?"
It seems they don't really know me
'Cause it's here, and it's what they can't see

Tones of home
Said, you don't like the way I'm living
Tones of home
Tones of home
And so I wave goodbye
And I'm flyin', and I'm flyin' home
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
pair<long, long> ps1[10],ps2[10],start;
pair<pair<long, long> ,pair<long, long> > temp;
queue<pair<pair<long, long> ,pair<long, long> > > qu;
long n,m,c1,c2,dp[22][22][1<<8][1<<8];
bool bad[33][33];
long cost[300];
long qx,qy,qmask1,qmask2;

void trymove(long x1,long y1,long x2,long y2)
{
 if (x2<=0||x2>n||y2<=0||y2>m)return;
 if (bad[x2][y2])return;
 
 long tmask1,tmask2;
 tmask1=qmask1;
 tmask2=qmask2;

 for (int i=0;i<c1;i++)
 {
  if (ps1[i].second>=y1)continue;
  if (x1<ps1[i].first&&x2==ps1[i].first)tmask1^=(1<<i);
  if (x1==ps1[i].first&&x2<ps1[i].first)tmask1^=(1<<i);
 }
 for (int i=0;i<c2;i++)
 {
  if (ps2[i].second>=y1)continue;
  if (x1<ps2[i].first&&x2==ps2[i].first)tmask2^=(1<<i);
  if (x1==ps2[i].first&&x2<ps2[i].first)tmask2^=(1<<i);
 }
 
 if (dp[x2][y2][tmask1][tmask2]>1e6)
 {
  dp[x2][y2][tmask1][tmask2]=dp[x1][y1][qmask1][qmask2]+1;
  qu.push(make_pair(make_pair(x2,y2),make_pair(tmask1,tmask2)));
 }
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=m;j++)
 {
  if (st[j-1]=='.')continue;
  if (st[j-1]>='0'&&st[j-1]<='9')
  {
   ++c1;
   ps1[st[j-1]-'1']=make_pair(i,j);
  }
  if (st[j-1]=='B')
  {
   ++c2;
   ps2[c2-1]=make_pair(i,j);
  }
  if (st[j-1]=='S')
  start=make_pair(i,j);
  else bad[i][j]=1;
 }
}

for (int i=0;i<c1;i++)
 cin>>cost[i];

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  for (int mask1=0;mask1<(1<<c1);mask1++)
   for (int mask2=0;mask2<(1<<c2);mask2++)
    dp[i][j][mask1][mask2]=1e9;

dp[start.first][start.second][0][0]=0;

qu.push(make_pair(start,make_pair(0,0)));

while (qu.size())
{
 temp=qu.front();
 qu.pop();
 qx=temp.first.first;
 qy=temp.first.second;
 qmask1=temp.second.first;
 qmask2=temp.second.second;
 //cout<<qx<<" "<<qy<<" "<<qmask1<<"  "<<qmask2<<endl;
 
 trymove(qx,qy,qx+1,qy);
 trymove(qx,qy,qx-1,qy);
 trymove(qx,qy,qx,qy-1);
 trymove(qx,qy,qx,qy+1);
}

long ans=0;
for (int mask=0;mask<(1<<c1);mask++)
{
 //cout<<dp[start.first][start.second][mask][0]<<endl;
 long cc=0;
 for (int i=0;i<c1;i++)
 if (mask&(1<<i))cc+=cost[i];
 cc-=dp[start.first][start.second][mask][0];
 ans=max(ans,cc);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}