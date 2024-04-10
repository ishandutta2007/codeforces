//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

//#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,ans,s,u[1000];

double hl,hr,v[100000],qx,a[100000],b[100000],ady,adx,qddy,dy,qdy,dx;
long hits,ps,fl,fll;
string c[10000];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>hl>>hr>>n;
for (int i=0;i<n;i++)
cin>>v[i]>>c[i]>>a[i]>>b[i];


for (hits=1;hits<=100;++hits)
{
 dx=100000;
 dy=(hits-1)*100;
 
 ady=dy+hl;
 qdy=dy;
 if (hits%2)ady+=hr; else ady+=100-hr;
 adx=dx;
 
 for (int  i=0;i<n;i++)
 u[i]=0;
 
 
 qx=0;
 ps=1;
 fl=0;
 s=0;
 for (int i=0;i<hits;i++)  
 {
 
  if (i==0)dy=hl; else dy=100;
  ps=1-ps;
  dx=adx/ady*dy;
  qx+=dx;
  fll=0;
  for (int j=0;j<n;j++)
  if ((c[j]=="F"&&ps==0)||(c[j]=="T"&&ps==1))
  {if (a[j]<=qx+eps&&b[j]>=qx-eps){s+=v[j];u[j]++;fll=1;}}
 
 //if (hits==1)cout<<qx<<" "<<"QQQ"<<endl; 
  if (fll==0)fl=1;
 }
  for (int i=0;i<n;i++)
  if (u[i]>1)fl=1;
  if (fl==0)ans=max(ans+1e-9,s+1e-4);
  
  
  //============================
   for (int  i=0;i<n;i++)
 u[i]=0;
 
 
 qx=0;
 ps=0;
 fl=0;
 s=0;
 ady=qdy; 
 ady+=100-hl;
 
 if (hits%2==0)ady+=hr; else ady+=100-hr;
 
 adx=100000;
 
 for (int i=0;i<hits;i++)  
 {
  if (i==0)dy=100-hl; else dy=100;
  ps=1-ps;
  dx=adx/ady*dy;
  qx+=dx;
  fll=0;
  for (int j=0;j<n;j++)
  if ((c[j]=="F"&&ps==0)||(c[j]=="T"&&ps==1))
  {if (a[j]<=qx+eps&&b[j]>=qx-eps){//if (hits==1)cout<<j<<" "<<i<<endl;
  s+=v[j];u[j]++;fll=1;}}
  
  if (fll==0)fl=1;
// if (hits==1)cout<<qx<<" "<<"QQQ"<<endl; 
 }
// cout<<fl<<endl;
  for (int i=0;i<n;i++)
  if (u[i]>1)fl=1;
  if (fl==0)ans=max(ans+1e-9,s+1e-4);
  
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}