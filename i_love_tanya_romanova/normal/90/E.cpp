/*
I'm always gonna be one life behind
It's why I'm all alone
What's it gonna take to make you see
That we are falling apart?
I wondered can we throw away the past
So we can stop the screaming match?
I'm not gonna break down anymore
I've found my way to the door

I can see through all of the loss
It's an issue of our trust
It's killing me
It's killing me to watch you leave me
Leave me
Leave me

I tried to talk about what's really wrong
I see that look of discontent
The volume starts to rise and then it's on
That's why I have to go
Dealing with the pain is all that's left
Because we cannot get along
You want to put the blame on me again
I think that we have reached the end

I can see through all of the loss
It's an issue of our trust
It's killing me
It's killing me to watch you leave
I can see through all of the loss
It's an issue of our trust
You keep blaming me
Blaming me for what you do to me

It's your turn to
Watch me leave you
It's your turn to
Watch me leave you
It's your turn to
Watch me leave you

I can see through all of the loss
It's an issue of our trust
It's killing me
It's killing me to watch you leave
I can see through all of the loss
It's an issue of our trust
You keep blaming me
Blaming me for what you do to me
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

long n,m;
string st;
long bst,bc,ans;
long qi,qj,ti,tj;
vector<vector<long> > u,l,r,d,ar;

void dodel(long a,long b)
{
 if (l[a][b]!=-1)
 {
  r[a][l[a][b]]=r[a][b];
 }
 if (r[a][b]!=-1)
 {
  l[a][r[a][b]]=l[a][b];
 }
 if (u[a][b]!=-1)
 {
  d[u[a][b]][b]=d[a][b];
 }
 if (d[a][b]!=-1)
 {
  u[d[a][b]][b]=u[a][b];
 }
}

bool outside(long a,long b)
{
 return (a==-1||b==-1);
}

long gi(long a,long b)
{
 if (ar[a][b]=='L'||ar[a][b]=='R')return a;
 if (ar[a][b]=='U')return u[a][b];
 return d[a][b];
}

long gj(long a,long b)
{
 if (ar[a][b]=='D'||ar[a][b]=='U')return b;
 if (ar[a][b]=='L')return l[a][b];
 return r[a][b];
}

void recalc()
{
 long ls=-1;
 for (int i=1;i<=n;i++){
     ls=-1;
  for (int j=1;j<=m;j++)
  {
   l[i][j]=ls;
   if (ar[i][j])ls=j;
  }
}
 for (int i=1;i<=n;i++){ls=-1;
  for (int j=m;j>=1;j--)
  {
   r[i][j]=ls;
   if (ar[i][j])ls=j;
  }}
  
 for (int j=1;j<=m;j++)
 {
  ls=-1;
  for (int i=1;i<=n;i++)
  {
   u[i][j]=ls;
   if (ar[i][j])ls=i;
  }
 }
// ls=-1;
 for (int j=1;j<=m;j++)
 {
  ls=-1;
  for (int i=n;i;i--)
  {
   d[i][j]=ls;
   if (ar[i][j])ls=i;
  }
 }
 
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

ar.resize(n+5);
for (int i=0;i<ar.size();i++)
 ar[i].resize(m+5);

l.resize(n+5);
for (int i=0;i<l.size();i++)
 l[i].resize(m+5);
 
r.resize(n+5);
for (int i=0;i<r.size();i++)
 r[i].resize(m+5);

u.resize(n+5);
for (int i=0;i<u.size();i++)
 u[i].resize(m+5);
d.resize(n+5);
for (int i=0;i<d.size();i++)
 d[i].resize(m+5);
 
for (int i=1;i<=n;i++)
 {
  cin>>st;
 for (int j=1;j<=m;j++)
 {
  if (st[j-1]!='.')ar[i][j]=st[j-1];
  else ar[i][j]=0;
 }
}

bst=-1;
bc=-1;

for (int ri=1;ri<=n;ri++)
 for (int rj=1;rj<=m;rj++)
 {
  if (ar[ri][rj]==0)continue;
  recalc();
/*
 for (int i=1;i<=n;i++)
 {
  for (int j=1;j<=m;j++)
   cout<<u[i][j];
  cout<<endl;
 }
 cout<<endl;
 for (int i=1;i<=n;i++)
 {
  for (int j=1;j<=m;j++)
   cout<<d[i][j];
  cout<<endl;
 }
 cout<<endl;
 */
 
  qi=ri;
  qj=rj;
  ans=1;
  while (true)
  {
   ti=gi(qi,qj);
   tj=gj(qi,qj);
   dodel(qi,qj);
   if (outside(ti,tj))break;
   qi=ti;
   qj=tj;
//   cout<<qi<<"   "<<qj<<" "<<u[qi][qj]<<" "<<" "<<u[3][3]<<endl;
//   cin.get();
   ++ans;
  }
  if (ans>=bst)
  {
   if (ans==bst)bc++;else bc=1;
   bst=ans;
  }
 }
cout<<bst<<" "<<bc<<endl;

cin.get();cin.get();
return 0;}