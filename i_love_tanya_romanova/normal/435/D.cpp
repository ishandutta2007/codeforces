/*
I can't hide
Myself from this terrible
Feeling of
Frustration that finally
Led me out
Of reality, leaving
Me without strength
How can I face myself?
It's growing
Inside my mind
A threat I can not define
This strange feeling screams
Deafening as a Horn
Since the day I was born
Shall I stop
And try to face it
Burning in stifling heat?
I'm on my knees
What the hell is that thing?
It is unrelenting
This is the sad story
Of a boy in love with apathy
But feel no mercy my friends
The boy will ask for help until the end of time
I'm feeling sad
I'm feeling sick
I'm feeling bad
But I'm too weak to face this decline
It is always by my side
This feeling's driving me mad
And now I can only implore
But they don't want to give me the love
I'm begging for
In their eyes
I can see
The spite and the growing anger toward me
But what else can I do for them?
I do my best, it's true
I'm not able to live on my own
So please just leave me alone.
What the hell can I do for them
If I don't feel ashamed?
This is the sad story
Of a boy in love with apathy
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

long s[10][500][500],ans,n,m;
string st;
long ar[500][500];
vector<pair<long, long> > dir;
long dx,dy;
long tx,ty;
long p;
bool out(long a,long b)
{
 if (a<1||a>n)return true;
 if (b<1||b>m)return true;
 return false;
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

dir.push_back(make_pair(-1,0));
dir.push_back(make_pair(-1,1));
dir.push_back(make_pair(0,1));
dir.push_back(make_pair(1,1));
dir.push_back(make_pair(1,0));
dir.push_back(make_pair(1,-1));
dir.push_back(make_pair(0,-1));
dir.push_back(make_pair(-1,-1));

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=m;j++)
  ar[i][j]=st[j-1]-'0';
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  s[6][i][j]=s[6][i][j-1]+1;
  s[0][i][j]=s[0][i-1][j]+1;
  s[7][i][j]=s[7][i-1][j-1]+1;
  if (ar[i][j]==1)s[6][i][j]=s[7][i][j]=s[0][i][j]=0;
 }

for (int i=1;i<=n;i++)
 for (int j=m;j;--j)
 {
  s[1][i][j]=s[1][i-1][j+1]+1;
  s[2][i][j]=s[2][i][j+1]+1;
  if (ar[i][j]==1)s[1][i][j]=s[2][i][j]=0;
 }

for (int i=n;i;--i)
 for (int j=1;j<=m;j++)
 {
  s[5][i][j]=s[5][i+1][j-1]+1;
  s[4][i][j]=s[4][i+1][j]+1;
  if (ar[i][j]==1)s[4][i][j]=s[5][i][j]=0;
 }

for (int i=n;i;--i)
 for (int j=m;j;--j)
 {
  s[3][i][j]=s[3][i+1][j+1]+1;
  if (ar[i][j]==1)s[3][i][j]=0;
 }

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  for (int dd=0;dd<8;dd++)
  {
   dx=dir[dd].first;
   dy=dir[dd].second;
   p=1;
   while (true)
   {
    tx=i+dx*p;
    ty=j+dy*p;
    if (out(tx,ty))break;
    
    if (s[dd][i][j]<=p)break;
    if (s[(dd+2)%8][i][j]<=p)break;
    if (s[(dd+3)%8][tx][ty]>p+p*(dd%2))++ans;
//    cout<<i<<" "<<j<<" "<<tx<<" "<<ty<<endl;
//    ++ans;
    ++p;
   }
  }
  //cout<<i<<"   "<<j<<" "<<ans<<endl;
 }

cout<<ans<<endl;
cin.get();cin.get();
return 0;}