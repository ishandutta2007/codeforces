/*
Surrender our broken minds
The tears that we have shed
The secret of keeping hope
Our fear will never fade
The chains of fate unbroken
Ablaze the sails of sorrow
The last crusade of mankind
When worlds collide the end is near
In league with the devil
There's no turning back
Your hunger for power
The oppression of life
Behold what have we done
How long will we carry on
Betray the sinner forgive the saviour
The point of no return
We are condemned forever
There is no place for glory
We will be drowned forever
There is no place for glory
We will be drowned soon in seas of doom
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

vector<long> v;
long m,k,a[1<<10],b[1<<10];
long ar[1<<10][1<<10];
map<long, long> mapp,rmap;
long cnt,cnt2,cnt1;
vector<long> ans[1<<10];

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>k;
for (int i=1;i<=m;i++)
{
 cin>>a[i]>>b[i];
 v.push_back(a[i]);
 v.push_back(b[i]);
}

sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 if (i==0||v[i]!=v[i-1])
 {
  mapp[v[i]]=cnt;
  rmap[cnt]=v[i];
  ++cnt;
 }
}

for (int i=1;i<=m;i++)
{
 a[i]=mapp[a[i]];
 b[i]=mapp[b[i]];
 ar[a[i]][b[i]]=1;
 ar[b[i]][a[i]]=1;
}

for (int i=0;i<cnt;i++)
{
    for (int j=0;j<cnt;j++)
    {
     if(j==i)continue;
     if (ar[i][j])continue;
     cnt1=cnt2=0;
     for (int q=0;q<cnt;q++)
      if (ar[i][q]){++cnt1;
      if (ar[j][q])++cnt2;}
     if (cnt2*100>=cnt1*k)
     ans[i].push_back(j);
//     cout<<i<<" "<<j<<" "<<cnt1<<" "<<cnt2<<endl;
    }
}

for (int i=0;i<cnt;i++)
{
 cout<<rmap[i]<<": "<<ans[i].size();
 for (int j=0;j<ans[i].size();j++)
 {
  cout<<" "<<rmap[ans[i][j]];
 }
 cout<<endl;
}
cin.get();cin.get();
return 0;}