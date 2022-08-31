/*
Night will come and I will follow
For my victims, no tomorrow
Make it fast, your time of sorrow
On his trail, I'll make you follow

Quarters for the criminally insane
The sentence read for life I must remain
The path I chose has led me to my grave
To try again I'd have no other way

Quarters for the criminally insane
Escape for me has fast become a game
Soon to be, I'll leave without a trace
Endangered species end the human race

Branded in pain
Marked criminally insane
Locked away and kept restrained
Disapprobation, but what have I done
I have yet only just begun
To take your fuckin' lives!

(Night will come and I will follow
For my victims, no tomorrow
Make it fast, your time of sorrow
On his trail, I'll make you follow)
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

struct rib{
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

long m,a,b,kk,temp,d[200000],qq,q[200000],p[200000],id[200000],p_rib[200000];

long ar[100][100];

void add(long x1,long y1,long x2,long y2)
{
 if (x2==0||x2>n)return;
 if (y2==0||y2>m)return;
 long p1,p2;
 p1=x1*m+y1-m;
 p2=x2*m+y2-m;
 if (ar[x1][y1]==ar[x2][y2])add_rib(p1,p2,1,0);
 else add_rib(p1,p2,1,1);
}

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 cin>>ar[i][j];
 
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  if (i%2==j%2)
  {
   add_rib(0,(i*m+j-m),1,0);
   add(i,j,i-1,j);
   add(i,j,i+1,j);
   add(i,j,i,j-1);
   add(i,j,i,j+1);
  }
  else add_rib(i*m+j-m,n*m+1,1,0);
  
  s=0;
  t=n*m+1;
  n=t+1;
  k=1e9;
  
while (flow<k)
{
      for (int i=0;i<n;i++)id[i]=0;
      for (int i=0;i<n;i++)d[i]=1e9;
      qh=qt=0;
      q[qt]=s;d[s]=0;++qt;
      
      while (qh!=qt)
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
      
      /*for (int i=0;i<n;i++)
      cout<<d[i]<<" ";
      cout<<endl;
      */
      if (d[t]>1e8)break;
      long addflow=k-flow;
      
      for (int v=t;v!=s;v=p[v])
      {
       long pv=p[v];long pr=p_rib[v];
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

//cout<<cost<<" "<<flow<<endl;
cout<<cost<<endl;

cin.get();cin.get();
return 0;}