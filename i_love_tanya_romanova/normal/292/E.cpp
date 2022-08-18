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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-5
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;
long bsize;

long n,m,ar1[200000],ar2[200000],tp,ps,psquerry[200000],blockquerry[200000];
long x[200000],y[200000],k[200000],rem,qblock,mv;
long lstquerry;
long a,b,shift;

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
bsize=200;

cin>>n>>m;
for (int i=0;i<n;i++)
cin>>ar1[i];
for (int i=0;i<n;i++)
cin>>ar2[i];

for (int i=1;i<=m;i++)
{
 cin>>tp;
 if (tp==1)
 {
  cin>>x[i]>>y[i]>>k[i];
  
  --x[i];
  --y[i];
  
  rem=y[i]%bsize;
  qblock=y[i]/bsize;
  mv=bsize-rem;
  
  tp=qblock*bsize;
  //cout<<"!"<<rem<<" "<<qblock<<" "<<mv<<endl;
  
  for (int j=0;j<bsize;j++)
  {
   if (j>=rem&&j<rem+k[i]){
   psquerry[tp+j]=i;//cout<<"#"<<i<<" "<<j<<" "<<endl;
   }
   else if (blockquerry[qblock]!=0)
   psquerry[tp+j]=blockquerry[qblock];
  }
  blockquerry[qblock]=0;
  
  k[i]-=mv;
//  cout<<k[i]<<"!"<<endl;
  if (k[i]>0){
  while (k[i]>=bsize)
  {
   ++qblock;
   blockquerry[qblock]=i;
   k[i]-=bsize;
  }
  ++qblock;
  tp=qblock*bsize;
  for (int j=0;j<bsize;j++){
     // cout<<tp+j<<"@"<<endl;
   if (k[i]>j){psquerry[tp+j]=i;//cout<<tp+j<<"D"<<endl;
   }
   else if (blockquerry[qblock]!=0)
   psquerry[tp+j]=blockquerry[qblock];
}
  blockquerry[qblock]=0;
 }   
 
 }
 
 else
 {
  cin>>ps;
//  for (int j=0;j<n;j++)cout<<psquerry[j]<<" ";
//  cout<<endl;

  --ps;
  lstquerry=-1;
  rem=ps%bsize;
  qblock=ps/bsize;
  if (blockquerry[qblock]==0)lstquerry=psquerry[ps];else 
  lstquerry=max(lstquerry,blockquerry[qblock]);
  
  
  if (lstquerry<1)
  cout<<//"Q"<<
  ar2[ps]<<endl;
  else {
        shift=ps-y[lstquerry];
 // cout<<"!!!"<<lstquerry<<" "<<shift<<endl;
        cout<<//"Q"<<
        ar1[x[lstquerry]+shift]<<//"!"<<
        endl;
       }
 }
}

cin.get();cin.get();
return 0;}