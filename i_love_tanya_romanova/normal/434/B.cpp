/*
Dear Mother, dear Father
What is this hell you have put me through?
Believer, deceiver
Day in, day out, live my life through you
Pushed onto me what's wrong or right
Hidden from this thing that they call life

Dear Mother, dear Father
Every thought I'd think you'd disapprove
Curator, dictator
Always censoring my every move
Children are seen but are not heard
Tear out everything inspired

Innocence, torn from me without your shelter
Barred reality, I'm living blindly

Dear Mother, dear Father
Time has frozen still, what's left to be
Hear nothing, say nothing
Cannot face the fact I think for me
No guarantee, it's life as is
But damn you for not giving me my chance

Dear Mother, dear Father
You clipped my wings before I learnt to fly
Unspoiled, unspoken
I've outgrown that fucking lullaby
Same thing I've always heard from you
Do as I say, not as I do

Innocence, torn from me without your shelter
Barred reality, I'm living blindly

I'm in hell without you
Cannot cope without you too
Shocked at the world that I see
Innocent victim please rescue me

Dear Mother, dear Father
Hidden in your world you've made for me
I'm seething, I'm bleeding
Ripping wounds in me that never heal
Undying spite, I feel for you
Living out this hell you always knew
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

long n,m,tests,ar[1200][1200],l[1200][1200],r[1200][1200],u[1200][1200],
d[1200][1200];
long tp,x,y;
long ans;
stack<pair<long, long> > v,emp;
long uu;
long lp;
long op;

void update(long x,long y)
{
 ar[x][y]=1-ar[x][y];
 
 
for (int i=x;i<=x;i++)
 for (int j=1;j<=m;j++)
 {
  l[i][j]=l[i][j-1]+1;
  if (ar[i][j]==0)l[i][j]=0;
 }
 
for (int i=x;i<=x;i++)
 for (int j=m;j;--j){
 r[i][j]=r[i][j+1]+1;
 if (ar[i][j]==0)r[i][j]=0;
}

for (int i=1;i<=n;i++)
 for (int j=y;j<=y;j++)
{
 u[i][j]=u[i-1][j]+1;
 if (ar[i][j]==0)u[i][j]=0;
}
for (int i=n;i;--i)
 for (int j=y;j<=y;j++)
 {
  d[i][j]=d[i+1][j]+1;
  if (ar[i][j]==0)d[i][j]=0;
 }
}

long solve(long x,long y)
{
 ans=0;
 v=emp;
 
/* for (int i=1;i<=n;i++)
 {
  for (int j=1;j<=m;j++)
   cout<<r[i][j]<<" ";
   cout<<endl;
 }
 */
 // l
 for (int i=1;i<=n+1;i++)
 {
  lp=i;
  while (v.size()>0&&l[i][y]<v.top().first)
  {
   uu=v.top().first;
   op=v.top().second;
   if (i>x&&op<=x)ans=max(ans,(i-v.top().second)*uu);
   lp=v.top().second;
   v.pop();
  }
//  if (i>x&&v.size()==0)break;
  if (v.size()==0)uu=0;else uu=v.top().first;
  if (l[i][y]>uu)v.push(make_pair(l[i][y],lp));
  if (i==x&&v.size()==0)break;
 // cout<<i<<" ^"<<v.size()<<" "<<ans<<endl;
 }
 v=emp;
// cout<<ans<<endl;
 //r
 for (int i=1;i<=n+1;i++)
 {
  lp=i;
  while (v.size()>0&&r[i][y]<v.top().first)
  {
   uu=v.top().first;
   op=v.top().second;
   if (i>x&&op<=x)ans=max(ans,(i-v.top().second)*uu);
   lp=v.top().second;
   v.pop();
  }
//  if (i>x&&v.size()==0)break;
  if (v.size()==0)uu=0;else uu=v.top().first;
  if (r[i][y]>uu)v.push(make_pair(r[i][y],lp));
  if (i==x&&v.size()==0)break;
 }
 //u
  v=emp;
 for (int i=1;i<=m+1;i++)
 {
  lp=i;
  while (v.size()>0&&u[x][i]<v.top().first)
  {
   uu=v.top().first;
   op=v.top().second;
   if (i>y&&op<=y)ans=max(ans,(i-v.top().second)*uu);
   lp=v.top().second;
   v.pop();
  }
//  if (i>y&&v.size()==0)break;
  if (v.size()==0)uu=0;else uu=v.top().first;
  if (u[x][i]>uu)v.push(make_pair(u[x][i],lp));
  if (i==y&&v.size()==0)break;
 }
 //d
  v=emp;
 for (int i=1;i<=m+1;i++)
 {
  lp=i;
  while (v.size()>0&&d[x][i]<v.top().first)
  {
   uu=v.top().first;
   op=v.top().second;
   if (i>y&&op<=y)ans=max(ans,(i-v.top().second)*uu);
   lp=v.top().second;
   v.pop();
  }
//  if (i>y&&v.size()==0)break;
  if (v.size()==0)uu=0;else uu=v.top().first;
  if (d[x][i]>uu)v.push(make_pair(d[x][i],lp));
  if (i==y&&v.size()==0)break;
 }
 return ans;
}

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>tests;
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=m;j++)
  cin>>ar[i][j];
}


// pref cls t!

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  l[i][j]=l[i][j-1]+1;
  if (ar[i][j]==0)l[i][j]=0;
 }

for (int i=1;i<=n;i++)
 for (int j=m;j;--j){
 r[i][j]=r[i][j+1]+1;
 if (ar[i][j]==0)r[i][j]=0;
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
{
 u[i][j]=u[i-1][j]+1;
 if (ar[i][j]==0)u[i][j]=0;
}

for (int i=n;i;--i)
 for (int j=1;j<=m;j++)
 {
  d[i][j]=d[i+1][j]+1;
  if (ar[i][j]==0)d[i][j]=0;
 }

// e pref t!

for (;tests;--tests)
{
 cin>>tp>>x>>y;
 if (tp==1)
 {
  update(x,y);continue;
 }
 if (tp==2)
 {
  cout<<solve(x,y)<<endl;continue;
 }
}

cin.get();cin.get();
return 0;}