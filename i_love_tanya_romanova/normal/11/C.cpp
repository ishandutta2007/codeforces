/*
Rise my Clandestine, thy secrecies invoked
Streams of Argentine across eyelids are drawn
Rise upon the tide, my castaway's outworn
Fall from distant worlds and red-eyed skies above

Rise my clandestine, thy secrecies invoked
Streams of Argentine, across eyelids are drawn

Gesture of an Argentine moisture
Like snow upon the riverine
Gesture of an Argentine moisture
So sore upon congeal skin

Ardency of life forsakened
Time will gather the source of thy secrecies
Ardency of life forsakened
In swarthy hours thou ponder still

Invoke thy aeons in a dream
Entrancing sleep, profound and prolix
Estranged to life's utility
Bequest thy endurance in the times of lethargic

Gesture of an Argentine moisture
Like snow upon the riverine
Gesture of an Argentine moisture
So sore upon congeal skin

Lead me down in wailing hours to the riverside
Reveal to me thy secrecies
Hidden in the wan deep of thy infinite mourning
Lethean River carry me beneath thy riverine
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
#define bsize 512

using namespace std;

long n,m;
string st;
long used[1<<8][1<<8],ans;
vector<pair<long, long> > v;
long tests;
long ar[1<<8][1<<8];

void dfs(long a,long b)
{
 if (used[a][b])return ;
 if (a<=0||a>n||b<=0||b>m)return;
 if (ar[a][b]==0)return;
 used[a][b]=1;
 v.push_back(make_pair(a,b));
 dfs(a+1,b);
 dfs(a-1,b);
 dfs(a,b-1);
 dfs(a,b+1);
 dfs(a-1,b-1);
 dfs(a-1,b+1);
 dfs(a+1,b-1);
 dfs(a+1,b+1);
}

bool is1(vector<pair<long, long> > v)
{
     if (v.size()%4)return 0;
     long l=v.size()/4+1;
     for (int i=0;i<l;i++)
      if (v[i].first!=v[0].first)return 0;
     
     for (int i=0;i<l-2;i++)
     {
      if (v[l+i*2].first!=v[0].first+i+1||v[l+i*2].second!=v[0].second||v[l+i*2+1].first!=v[0].first+i+1||v[l+i*2+1].second!=v[l-1].second)return 0;
     }
     for (int i=0;i<l;i++)
     {
      if (v[v.size()-l+i].first!=v[i].first+l-1||v[v.size()-l+i].second!=v[i].second)return 0;
     }
     return 1;
}

bool is2(vector<pair<long, long> > v)
{
     if (v.size()%4)return 0;
     long l=v.size()/4+1;
     
     for (int i=1;i<l;i++)
     {
      if (v[i*2].first!=v[0].first+i||v[i*2-1].first!=v[0].first+i||v[i*2].second!=v[0].second+i||v[i*2-1].second!=v[0].second-i)return 0;
     }
     reverse(v.begin(),v.end());
     for (int i=1;i<l;i++)
     {
      if (v[i*2].first!=v[0].first-i||v[i*2-1].first!=v[0].first-i||v[i*2].second!=v[0].second-i||v[i*2-1].second!=v[0].second+i)return 0;
     }
     return 1;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
 cin>>n>>m;
 for (int i=1;i<=n;i++)
 {
  cin>>st;
  for (int j=1;j<=st.size();j++)
  {
   if (st[j-1]=='0')ar[i][j]=0;else ar[i][j]=1;
  }
 }
 for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
   used[i][j]=0;
  
  ans=0;
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
   {
       if (used[i][j])continue;
       if (ar[i][j]==0)continue;
       v.clear();
       dfs(i,j);
       sort(v.begin(),v.end());
       if (is1(v)||is2(v))++ans;
   }
   cout<<ans<<endl;
   
}

cin.get();cin.get();
return 0;}