/*
You must listen very carefully to what I have to say, 
there isnt much time because you know who has consumed all the instruments. 
For many eons now I have been trapped on this planet. 
He is keeping me here against my will, 
and sometimes when I press my ear up very close to the concrete,
I can hear his daughters sobbing laughter. 

Either I am blind, 
or I have been in darkness ever since the sun exploded fourteen centuries ago.
A few hours ago he who keeps me here visits at me saying:
God! Why do the millions worship you instead of I? 
Am I not more powerful, or forgiving and truly compassionate? 

A black liquid was seeping uncontrollably from my mouth. 
And all I could do was babble incomprehensibly about a dream I had many moons ago. 
In it a clock ticked constantly, maddening my senses. 

That was all, 
but it lasted for many days until each tick seemed like fragments of glass,
piercing my scales.
He who keeps me here tells me that one day I will return to earth,
and then I will seek my revenge
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
 
//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 2048
 
using namespace std;

class Fenwick
{
 long long *m,*mt,N;
 public:
 Fenwick(long n);
 Fenwick(long long a[],long n);
 void add_range(long l,long long d);
 void add_range(long l,long r,long long d);
 long long sum(long r);
 long long sum(long l,long r);
};

Fenwick::Fenwick(long n)
{
 N=n;
 m=new long long[N];
 mt=new long long[N];
 for (int i=0;i<n;i++)
 m[i]=mt[i]=0;
}

void Fenwick::add_range(long r,long long d)
{
 if (r<0)return;
 for (int i=r;i>=0;i=(i&(i+1))-1)mt[i]+=d;
 for (int i=r|(r+1);i<N;i|=i+1)m[i]+=d*(r-(i&(i+1))+1);
}

void Fenwick::add_range(long l,long r,long long d)
{
 add_range(r,d);
 add_range(l-1,-d);
}

long long Fenwick::sum(long r)
{
 if (r<0)return 0;
 long long res=0;
 for (int i=r;i>=0;i=(i&(i+1))-1)res+=m[i]+mt[i]*(i-(i&(i+1))+1);
 for (int i=r|(r+1);i<N;i|=i+1)res+=mt[i]*(r-(i&(i+1))+1);
 return res;
}

long long Fenwick::sum(long l,long r)
{
 return sum(r)-sum(l-1);
}

long n,m,w;
long long tp,x1,y1,x2,y2;
long long v,ttl;

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>w;
Fenwick f1(n+100),f2(m+100);

for (;w--;)
{
 cin>>tp;
 if (tp==0)
 {
  cin>>x1>>y1>>x2>>y2>>v;
  ttl+=(x2-x1+1)*(y2-y1+1)*v;
  f1.add_range(x1,x2,(y2-y1+1)*v);
  f2.add_range(y1,y2,(x2-x1+1)*v);
 }
 else
 {
//  cout<<ttl<<endl;
  cin>>x1>>y1>>x2>>y2;
  long long res=-ttl;
//  cout<<res<<endl;
 // cout<<f1.sum(x1,x2)<<endl;
 // cout<<f2.sum(y1,y2)<<endl;
  res+=f1.sum(x1,x2);
  //cout<<res<<endl;
  res+=f2.sum(y1,y2);
  //cout<<res<<endl;
  cout<<res<<endl;
 }
}

cin.get();cin.get();
return 0;}