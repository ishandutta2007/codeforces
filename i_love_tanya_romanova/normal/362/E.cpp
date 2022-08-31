/*
I am the world that hides
The universal secret of all time
Destruction of the empty spaces
Is my one and only crime
I've lived a thousand times
I found out what it means to be believed
The thoughts and images
The unborn child that never was conceived
When little worlds collide
I'm trapped inside my embryonic cell
And flashing memories
Are cast into the never ending well
The name that scorns the face
The child that never sees the cause of man
The deathly darkness that
Belies the fate of those who never ran
Well I know its hard for you
To know the reason why
And I know you'll understand
More when it's time to die
Don't believe the life you have
Will be the only one
You have to let your body sleep
To let your soul live on
Love has given life to you
And now it's your concern
Unseen eyes of inner life
Will make your soul return
Still I look but not to touch
The seeds of life are sown
Curtain of the future falls
The secret stays unknown
Just remember love is life
And hate is living death
Treat your life for what it's worth
And live for every breath
Looking back I've lived and learned
But now I'm wondering
Here I wait and only guess
What this next life will bring
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

struct rib
{
 long b,u,c,f;
 long back;
};
vector<rib> g[20000];
long flow,cost;
long k,n,qh,qt,s,t;

void add_rib(long a,long b,long u,long c)
{
 rib r1={b,u,c,0,g[b].size()};
 rib r2={a,0,-c,0,g[a].size()};
 g[a].push_back(r1);
 g[b].push_back(r2);
}

long a,b,kk,temp,d[200000],qq,q[200000],p[200000],id[200000],p_rib[200000];
long addflow,ar[200][200];

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=n;j++)
 {
     cin>>ar[i][j];
     if (i==j)continue;
     if (ar[i][j]==0)continue;
     add_rib(i,j,ar[i][j],0);
     add_rib(i,j,1000000000,1);
 }   
}

s=1;
t=n;
while (cost<=k)
{
 for (int i=1;i<=n;i++)
 id[i]=0;
 for (int i=1;i<=n;i++)
 d[i]=1000000000;
 qh=qt=0;
 q[qt]=s;
 d[s]=0;
 qt=1;
 while (qh-qt)
 {
  long v=q[qh];++qh;
  id[v]=2;
  if (qh==n)qh=0;
   for (int i=0;i<g[v].size();i++)
    {
        rib &r=g[v][i];
        if (r.f<r.u&&d[v]+r.c<d[r.b])
        {
         d[r.b]=d[v]+r.c;
         if (id[r.b]==0)
         {
          q[qt]=r.b;++qt;if (qt==n)qt=0;
         }
         else if (id[r.b]==2)
         {
          if (qh==1)qh=n-1;else qh--;
          q[qh]=r.b;
         }
         id[r.b]=1;
         p[r.b]=v;p_rib[r.b]=i;
        }
   }
 }
 /*
 for (int i=1;i<=n;i++)
 cout<<d[i]<<" ";
 cout<<endl;
 */
  if (d[t]==0)addflow=1e9;
 else addflow=(k-cost)/d[t];
 if (addflow==0)break;
 if (d[t]>500000000)break;
 
 for (int v=t;v!=s;v=p[v])
      {
       int pv=p[v];int pr=p_rib[v];
       addflow=min(addflow,g[pv][pr].u-g[pv][pr].f);
      }
      
      for (int v=t;v!=s;v=p[v])
      {
          long pv=p[v];long pr=p_rib[v];
          long r=g[pv][pr].back;
          g[pv][pr].f+=addflow;
          g[v][r].f-=addflow;
          cost+=g[pv][pr].c*addflow;
      }
      flow+=addflow;
}

cout<<flow<<endl;

cin.get();cin.get();
return 0;}