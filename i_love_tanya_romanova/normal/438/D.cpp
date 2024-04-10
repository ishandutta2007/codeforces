/*
We're the little creatures deep inside your mind
Some call us their fantasy, but some do never find
We can teach philosophy, but still we must commend
The state of our existence right into your hand
Welcome to this place in here, come overstep all your fears

Where have you all been once when I was alone?
When I was a hero in their crazy wicked show
You've sent no little spark into my darkened view of life
Did not make me ask for what is wrong and what is right
And still I regret to be here, I'm dreaming of Anna in tears

Inside, so deep inside
You will die if I don't dream anymore
Inside, so deep inside
You will die if I don't dream anymore

Inside, so deep inside
You will die if I don't dream anymore
Inside, so deep inside
You will die if I don't dream anymore
Dream anymore
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

pair<long long, long long> tpp;
long long f[500000];
pair<long, long> t[500000];
long long n,m,tp,a,b,c;
long long ar[500000];
long long q;

long long sum(long long r)
{
 long long res=0;
 for (;r>=0;r=(r&(r+1))-1)
  res+=f[r];
 return res;
}

void inc(long ps,long val)
{
 long i=ps;
 for (;i<n+5;i=(i|(i+1)))f[i]+=val;
}

long long sum(long l,long r)
{
 return sum(r)-sum(l-1);
}

void build(long v,long tl,long tr)
{
 if (tl==tr)
 {
  t[v]=make_pair(ar[tl],tl);
  return;
 }
 long mid=tl+tr;
 mid/=2;
 build(v*2,tl,mid);
 build(v*2+1,mid+1,tr);
 if (t[v*2].first>t[v*2+1].first)
  t[v]=t[v*2];
  else t[v]=t[v*2+1];
}

void update(long v,long tl,long tr,long ps,long val)
{
 if (tl==tr)
 {
  t[v]=make_pair(val,ps);
  return;
 }
 long mid=tl+tr;
 mid/=2;
 if (ps>mid)update(v*2+1,mid+1,tr,ps,val);
 else update(v*2,tl,mid,ps,val);
 if (t[v*2].first>t[v*2+1].first)
  t[v]=t[v*2];
  else t[v]=t[v*2+1];
} 

pair<long,long> gett(long v,long tl,long tr,long l,long r)
{
 if (l>r)return make_pair(-1,-1); 
// cout<<v<<" "<<tl<<" "<<tr<<" "<<l<<" "<<r<<endl;
// cin.get();
 if (tl==l&&tr==r)
  return t[v];
 long tm=tl+tr;
 tm/=2;
 pair<long, long> tp1,tp2;
 tp1=gett(v*2,tl,tm,l,min(r,tm));
 tp2=gett(v*2+1,tm+1,tr,max(l,tm+1),r);
 if (tp1.first>tp2.first)return tp1;
 else return tp2;
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

build(1,1,n);
for (int i=1;i<=n;i++)
 inc(i,ar[i]);
 
for (int i=1;i<=m;i++)
{
 cin>>tp;
 if (tp==1)
 {
  cin>>a>>b;
  cout<<sum(a,b)<<endl;
 }
 if (tp==3)
 {
  cin>>a>>b;
  q=ar[a];
  inc(a,b-q);
  update(1,1,n,a,b);
  ar[a]=b;
 }
 if (tp==2)
 {
  cin>>a>>b>>c;
  while (true)
  {
   tpp=gett(1,1,n,a,b);
//   cout<<tpp.first<<" "<<tpp.second<<endl;
   if (tpp.first<c)break;
   inc(tpp.second,tpp.first%c-tpp.first);
   update(1,1,n,tpp.second,tpp.first%c);
   ar[tpp.second]=tpp.first%c;
  }
 }
}

cin.get();cin.get();
return 0;}