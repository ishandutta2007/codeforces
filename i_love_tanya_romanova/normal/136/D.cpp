/*
You son of man I am here as a witness
You son of man can't you see what burns inside me

This fire will consume as the flames purify
With the peace that passes understanding
This is my outcry

From dust to dust we will return
The flesh is temporary the soul is eternal

I am here as a witness
This is you will see is fire, purifies

This fire will consume as the flames purify
(This fire will consume as the flames purify)

Son of man can't you see
Son of man you can't save yourself
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long x[2000],y[2000];
vector<long> v1,v2;
long ans;
vector<long> a1,a2;

long gb(long x)
{
 long r=0;
     for (int i=0;i<=8;i++)
      if (x&(1<<i))++r;
 return r;
}

long a,b,c,d,e;
long er,s;

bool isrect(vector<long> v)
{
 do 
 {
     v.push_back(v[0]);
     er=0;
     for (int i=1;i<4;i++)
     {
      a=v[i-1];
      b=v[i];
      c=v[i+1];
      s=(x[a]-x[b])*(x[c]-x[b])+(y[a]-y[b])*(y[c]-y[b]);
      if (s)er=1;
     }
     v.pop_back();
     if (er==0)return true;
 }while (next_permutation(v.begin(),v.end()));
 return false;
}

bool issquare(vector<long> v)
{
 do 
 {
     long d1,d2;
     
     v.push_back(v[0]);
     er=0;
     for (int i=1;i<4;i++)
     {
      a=v[i-1];
      b=v[i];
      c=v[i+1];
      s=(x[a]-x[b])*(x[c]-x[b])+(y[a]-y[b])*(y[c]-y[b]);
      if (s)er=1;
      d1=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
      d2=(x[c]-x[b])*(x[c]-x[b])+(y[c]-y[b])*(y[c]-y[b]);
      if (d1!=d2)er=1;
     }
     v.pop_back();
     if (er==0)return true;
 }while (next_permutation(v.begin(),v.end()));
 return false;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for(int i=0;i<8;i++)
{
 cin>>x[i]>>y[i];
}

for (int mask=0;mask<(1<<8);mask++)
{
 if (gb(mask)!=4)continue;
 v1.clear();
 v2.clear();
 for (int i=0;i<8;i++)
 {
  if (mask&(1<<i))v1.push_back(i);
  else v2.push_back(i);
 }
 if (isrect(v1)&&issquare(v2))
 {
  ans=1;
  a1=v1;
  a2=v2;
 }
}

swap(a1,a2);
for (int i=0;i<a1.size();i++)
 a1[i]++,a2[i]++;
 
if (ans==0)
cout<<"NO"<<endl;
else
{
 cout<<"YES"<<endl;
 for (int i=0;i<a1.size();i++)
 {
     if (i)cout<<" ";
     cout<<a1[i];
 }
 cout<<endl;
 for (int i=0;i<a2.size();i++)
 {
     if (i)cout<<" ";
     cout<<a2[i];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}