/*
A cruel sleep 'cross our land, all withered and dying
As they fall, the victims, they're dying a sad death
In our land, we lay down and suffer again

A dark girl 'cross our land is pacing, is praying
And with her, a fever, a marching black fever
No eyes see, no features, just black form, suffering

You have her sympathy, you have her tears
She tries only to take all your fears
The pain she feels when she drinks your soul is hers to suffer, it is her toll
Believe me, she's helpless when she curses our land
When she swallows light, it's not her hand

Poison awaits when you kiss her, her heart cries out for you, for me
Untold misery is hers to serve out for eternity
Out cold, mankind will stay forevermore if she gets her way
She can't help it, it's her, her curse to sing your pain in her own verse

She is the dark, the nightmares you hide
The pain you feel, the suffering inside
Though she was like you, through her dark past
But now, the conqueror, her choirs vast
Oh, please forgive her as mankind dies
As angels weep and heaven cries

Poison awaits when you kiss her, her heart cries out for you, for me
Untold misery is hers to serve out for eternity
Out cold, mankind will stay forevermore if she gets her way
She can't help it, it's her, her curse to sing your pain in her own verse
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
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long match[1200000];
stack<long> v;
long temp;
long m,a,b;
vector<long> res[2200000];

void build(long v,long tl,long tr)
{
 if (tl==tr)
 {
  if (match[tl]!=-1)res[v].push_back(match[tl]);
  return;
 }
 long tm=tl+tr;
 tm/=2;
 build(v*2,tl,tm);
 build(v*2+1,tm+1,tr);
 
 long ps1,ps2;
 ps1=0;
 ps2=0;
 while (ps1<res[v*2].size()||ps2<res[v*2+1].size())
 {
  if (ps1==res[v*2].size()){res[v].push_back(res[v*2+1][ps2]);++ps2;}
  else if (ps2==res[v*2+1].size()){res[v].push_back(res[v*2][ps1]);++ps1;}
  else if (res[v*2][ps1]<res[v*2+1][ps2]){res[v].push_back(res[v*2][ps1]);++ps1;}
  else {res[v].push_back(res[v*2+1][ps2]);++ps2;}
 }
}

long gett(long v,long tl,long tr,long l,long r)
{
 if (l>r)return 0;
 if (l==tl&&r==tr)
 {
  long l1,r1,mid;
  if (res[v].size()==0)return 0;
  if (res[v][res[v].size()-1]<a)return 0;
  l1=0;
  r1=res[v].size()-1;
  while (l1<r1)
  {
   mid=l1+r1;
   mid/=2;
   if (res[v][mid]<a)l1=mid+1;
   else r1=mid;
  }
   return res[v].size()-l1;
 }
 long tm=tl+tr;
 tm/=2;
 return gett(v*2,tl,tm,l,min(r,tm))+gett(v*2+1,tm+1,tr,max(l,tm+1),r);
}

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
match[i]=-1;

for (int i=0;i<st.size();i++)
{
 if (st[i]=='(')v.push(i);
 else
 {
  if (v.size()==0)continue;
  temp=v.top();
  v.pop();
  match[i]=temp;
 }   
}

/*for (int i=0;i<st.size();i++)
cout<<match[i]<<" ";
cout<<endl;
*/

build(1,0,st.size()-1);
cin>>m;
for (int i=0;i<m;i++)
{
 cin>>a>>b;
 --a;
 --b;
 cout<<gett(1,0,st.size()-1,a,b)*2<<endl;   
}
cin.get();cin.get();
return 0;}