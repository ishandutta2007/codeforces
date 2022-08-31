/*
I'm self-obsessed
Wrong words I said
It's clear that some things aren't worth really trying

So let it go, let it be
Then we'll talk and I can
Dream you're not here
Persevere, I could live without this

The one you'd like to go
Is taken much too slow

You're not impressed
Wrong words I said
A mere subject of your self-indulgence

So let it go, let it be
Shall we to talk about it
My misery is when you breathe
There's no doubt about it
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

long n,m,ar[4200000];
long cnt;
long x;
long val[4200000];
long ps;
long t[4200000];

void update(long v,long l,long r,long ps,long val)
{
 if (l==r){t[v]+=val;return;}
 long m=l+r;m/=2;
 if (m>=ps)update(v*2,l,m,ps,val);
 else update(v*2+1,m+1,r,ps,val);
 t[v]=t[v*2]+t[v*2+1];
}

long solve(long v,long l,long r,long need)
{
 if (l==r)return l;
 long m=l+r;m/=2;
 if (t[v*2]>=need)return solve(v*2,l,m,need);
 return solve(v*2+1,m+1,r,need-t[v*2]);
}

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=m;i++)
cin>>ar[i];

cnt=0;ar[m+1]=n+10;
m++;

for (int j=1;j<=n;j++)
{
 cin>>x;
 if (x>=0)
 {
  ++cnt;
  val[cnt]=x;
  update(1,1,n,cnt,1);
 }
 else
 {
  ps=0;
  while (t[1]>=ar[ps+1])++ps;
  //cout<<ps<<" "<<ar[ps]<<"  "<<t[2]<<"   "<<solve(1,1,n,ar[ps])<<endl;
  
  for (;ps;--ps)update(1,1,n,solve(1,1,n,ar[ps]),-1);   
 }
 //cout<<"**"<<t[1]<<endl;
}


 if (t[1]==0)cout<<"Poor stack!"<<endl;
 else
 {
  for (int i=1;i<=t[1];i++)
   cout<<val[solve(1,1,n,i)];//<<" "<<solve(1,1,n,i)<<endl;
   cout<<endl;
 }
 
cin.get();cin.get();
return 0;}