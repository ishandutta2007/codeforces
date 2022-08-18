/*
Is this the place that I want to be?
Is it you who I want to see?
Holdin' on, hold it high, show me everything

And you're leavin' me
Yeah, you're leavin' me
You're leavin' me with a hated identity

But I keep on a comin' here and standin' in this state
Oh, and I'm never really sure
If you'll take what I'm sayin' the right way

But I'm not appalled or afraid verbal pocket play
Is as discreet as I can muster up to be
Because the Cadillac that's sittin' in the back
It isn't me, oh, no, no, no, it isn't me
I'm more at home in my galaxie, oh yeah

Can I do the things I wanna do
That I don't do because of you
And I'll take a left and I'll second guess into a total mess

And you're leavin' me
Yeah you're leavin' me
You're leavin' me with a hated identity

But I keep on a coming here and standin' in this state
Oh, and I'm always really sure
The situations get carried away

But I'm not appalled or afraid verbal pocket play
Is as discreet as I can muster up to be
Because the Cadillac that's sittin' in the back
It isn't me, oh, no, no, no, it isn't me
Oh, no, no, no it isn't me

No it isn't me, no it isn't me
No it isn't me, oh, no it isn't me
No it isn't me in the galaxie
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