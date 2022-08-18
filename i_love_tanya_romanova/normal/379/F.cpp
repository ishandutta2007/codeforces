/*
        
  ,   
     
   .
    ,   
       
    ,   
    ,   ? 
     
   ,    
       
     . 
     
       
     
     fm .

   ,   
   ,    ? 
 , ,   
  , , 
     ?

      
 ,  -    
     
      ? 
     
  ,    
    
       . 
       
     ,   
     
     . 
     
   
      
    .

 ,   
   ,    ? 
 , ,   
  , , 
     ?

   ,   
   ,    ? 
 , ,   
  , , 
     ?

 ,   
   ,    ? 
 , ,   
  , , 
     ? 
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long T1[1200000],T2[1200000];
long P[1200000][22];
long t1,t2,n;
vector<long> g[1200000];
long tv;
long q;
long qu[1200000];
long cur,res;
long H[1200000],D[1200000];
long app[1200000];
long anss[1200000];

bool upper(long a,long b)
{
 return (T1[a]<=T1[b]&&T2[a]>=T2[b]);
}

void dfs(long v,long p)
{
 P[v][0]=p;
 for (int i=1;i<=20;i++)
     P[v][i]=P[P[v][i-1]][i-1];
 
 T1[v]=t1;
 ++t1;
 for(int i=0;i<g[v].size();i++)
 dfs(g[v][i],v);
 T2[v]=t2;
 ++t2;
}

long lca(long a,long b)
{
 if (upper(a,b))return a;
 if (upper(b,a))return b;
 for (int i=20;i>=0;--i)
 if(!upper(P[a][i],b))a=P[a][i];
 return P[a][0];
}

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
g[0].push_back(1);
g[0].push_back(2);
g[0].push_back(3);

qu[1]=qu[2]=qu[3]=0;

tv=4;

for (int i=1;i<=n;i++)
{
 cin>>q;
 --q;
 g[q].push_back(tv);
 g[q].push_back(tv+1);
 tv+=2;
 qu[i*2+2]=q;
 qu[i*2+3]=q; 
 app[i*2+2]=app[i*2+3]=i;
} 

t1=t2=0;
dfs(0,0);

cur=res=0;
H[0]=D[0]=0;

long ttl=0;

for (int i=1;i<=n*2+5;i++)
{
 q=qu[i];
 H[i]=H[q]+1;
 if (H[q]==H[cur])
 {
  D[i]=D[cur]+1;
  res=max(res,max(H[i],D[i]));
  cur=i;
 }  
 else
 {
  long v=lca(i,cur);
  D[cur]=max(D[cur],H[cur]+H[i]-2*H[v]);
  res=max(res,D[cur]);
  res=max(res,max(H[i],H[cur]));
 }
 anss[app[i]]=res;
}

for (int i=1;i<=n;i++)
cout<<anss[i]<<endl;

cin.get();cin.get();
return 0;}