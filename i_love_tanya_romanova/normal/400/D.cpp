/*
There is nothing left
For me to see
The thought of end
Is killing me
I guess it's time
For my demise
There's no more time
I'm left aside

There's no more pain
There's no more tears
There's no more feeling
No more fear
The darkness creeps upon my skin
These wounds won't heal
This is my sin!

This is the black abyss
My life's apocalypse
Eternal suffering
No future for me to see
This is the black abyss
Executor of my soul
This darkness fills my eyes
And I'm now, left behind!

As my life rots away
I long the day of my decay
I'll soon be there, in death's grasp
It won't let go, now I'm dead!
This paranoia, I can't last
These days are now my last
The sense of evil is closing in
It is a phobia that kills within!

This is the black abyss
My life's apocalypse
Eternal suffering
No future for me to see
This is the black abyss
Executor of my soul
This darkness fills my eyes
And I'm now, left behind!
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

using namespace std;

long n,m,k,w[500000],d[500000],q,ar[1200][1200];
long ttl,clr[500000],a,b;
long c,er;

void merge(long a,long b)
{
 while (a!=w[a])a=w[a];
 while (b!=w[b])b=w[b];
 if (a==b)return;
 if (d[a]>d[b])
 {
  w[b]=a;
 }
 else
 {
     w[a]=b;if (d[a]==d[b])++d[b];
 }
}

long gett(long x)
{
 while (x!=w[x])x=w[x];
 return x;
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;

for (int i=1;i<=n;i++)
w[i]=i,d[i]=1;

for (int i=1;i<=k;i++)
 for (int j=1;j<=k;j++)
  if (i!=j)ar[i][j]=1e9+100500;
  
for (int i=1;i<=k;i++)
{
 cin>>q;
 for (int j=ttl+1;j<=ttl+q;j++)
 clr[j]=i;
 ttl+=q;
}

for (int i=1;i<=m;i++)
{
 cin>>a>>b>>c;
 if (c==0)merge(a,b);
 ar[clr[a]][clr[b]]=min(ar[clr[a]][clr[b]],c);
 ar[clr[b]][clr[a]]=min(ar[clr[b]][clr[a]],c);
}

er=0;

for (int i=1;i<=n;i++)
if (clr[i+1]==clr[i]&&gett(i+1)!=gett(i))
er=1;
if (er){cout<<"No"<<endl;return 0;}


for (int kk=1;kk<=k;kk++)
 for (int i=1;i<=k;i++)
  for (int j=1;j<=k;j++)
  ar[i][j]=min(ar[i][j],ar[i][kk]+ar[kk][j]);

for (int i=1;i<=k;i++)
 for (int j=1;j<=k;j++)
  if (ar[i][j]>1e9+5)ar[i][j]=-1;
  
  cout<<"Yes"<<endl;
  for (int i=1;i<=k;i++)
  {
   for (int j=1;j<=k;j++)
   {
    if (j>1)cout<<" ";
    cout<<ar[i][j];
   }cout<<endl;}
   
cin.get();cin.get();
return 0;}