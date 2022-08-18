/*
I see the world and it's full of hate
Around me hypocrites and I know them
They want to take away my emotions
But I resist
I destroy them

I know them

Great future, safe life, money, abundance
They promise everything but it's bullshit
I'm not a motherfucker ignorant
I will strike
I will fight

They cannot take my life
They cannot stop me
They cannot take my rights
No

They cannot control me
They cannot change me
The cannot repress me

No
Never!

I know them

I go ahead, never never turn back
Live your fucking life and give me respect
I have my life and it's only mine
I will strike
I will fight
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

long n,m,ar[405][405],r[405][405];
vector<long> v[165000];
long ptr[165000];
long ans,q;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
for (int i=0;i<n;i++)
{
 for (int j=0;j<m;j++)
 {
  cin>>ar[i][j];
  r[i][j]=m;
 }
}

ans=1;
for (int up=n-1;up>=0;--up)
{
 for (int i=0;i<=160000;i++)
  v[i].clear();
 for (int i=0;i<=160000;i++)
 ptr[i]=0;
 
 for (int i=0;i<m;i++)
 {
  q=ar[up][i];
  if (v[q].size()>0){long t=v[q].size()-1;r[up][v[q][t]]=i;}
  v[q].push_back(i);
 }
 
 for (long j=0;j<m;j++)
 {
  for (int i=up+1;i<n;i++)
  {
   q=ar[i][j];
   while (ptr[q]<v[q].size()&&v[q][ptr[q]]<j)++ptr[q];
   
   if (ptr[q]<v[q].size())
   r[i][j]=min(r[i][j],v[q][ptr[q]]);
   
   if (ptr[q]>0)
   r[i][v[q][ptr[q]-1]]=min(r[i][v[q][ptr[q]-1]],j);
  }
 }
 for (int dwn=up;dwn<n;dwn++)
 {
  for (int j=m-1;j>=0;--j)
  {
   if (dwn>up)r[dwn][j]=min(r[dwn][j],r[dwn-1][j]);
   if (j+1<m)r[dwn][j]=min(r[dwn][j],r[dwn][j+1]);
   ans=max(ans,(r[dwn][j]-j)*(dwn-up+1));
  }
 }
 /*
 for (int i=0;i<n;i++)
 {
  for (int j=0;j<m;j++)
  cout<<r[i][j]<<" ";
  cout<<endl;
 }
 cout<<endl<<"%"<<ans<<endl;*/
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}