/*
I'm addicted
So Infected
You reel me in now please never release me
I'd only feel alive when I'm with you

And I will never get enough
Your love is just another drug

And I can't get enough

I'm dependent
So damn helpless
I never thought I would dig my own grave
I only feel alive inside of you

And I will never get enough
Your love is just another drug
And I will never get enough
Your love is always on my mind

If there was one thing I could change
It be the way I feel for you

If there was one thing I could change
It be the way I feel for you
I only feel alive whem I'm with you

And I will never get enough
Your love is just another drug
And I will never get enough
Your love is always on my mind
And nothing sees that I'm stuck this way
I don't know how I make it through each day

Your love is just another drug
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
#define eps 1e-17
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256
#define ends agashaah

using namespace std;

long n,m,q,ar[200000][22];
long calc;
long a,b,t1,t2;
set<long> ends[20000];
long l[200000][22],r[200000][22];
long long ans;
set<long>::iterator it;
long q1,q2;

void add_intr(long a,long b,long lev)
{
     if (a>b)return;
 ends[lev].insert(b);
 l[b][lev]=a;
 r[a][lev]=b;
 long long span=b-a+1;
 ans+=span*(span+1)/2*(1<<lev);
}

void del_intr(long a,long b,long lev)
{
     if (a>b)return;
     long long span=b-a+1;
     ans-=span*(span+1)/2*(1<<lev);
     ends[lev].erase(b);
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
   
cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>q;
 for (int lev=0;lev<=20;lev++)
 {
  if (q&(1<<lev))ar[i][lev]=1;else ar[i][lev]=0;
 }
}

for (int lev=0;lev<=20;lev++)
{
 calc=0;
 
 for (int i=1;i<=n;i++)
 {
  if (ar[i][lev])calc++;
  else
  {
   add_intr(i-calc,i-1,lev);
   calc=0;
  }
 }
 if (calc)add_intr(n-calc+1,n,lev);
}

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 for (int j=0;j<=20;j++)
 {
  if (b&(1<<j))
  {
   if (ar[a][j])continue;
   if (ar[a-1][j]){t1=l[a-1][j];del_intr(t1,a-1,j);}else t1=a;
   if (ar[a+1][j]){t2=r[a+1][j];del_intr(a+1,t2,j);}else t2=a;
   add_intr(t1,t2,j);
   ar[a][j]=1;
  }
  else
  {
   if (ar[a][j]==0)continue;
   it=ends[j].lower_bound(a);
   q2=(*it);
   q1=l[q2][j];
   del_intr(q1,q2,j);
   add_intr(q1,a-1,j);
   add_intr(a+1,q2,j);
   ar[a][j]=0;
  }
 }
 cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}