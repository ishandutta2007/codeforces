/*
Monuments of dying dreams
As far away as Eden
These hours standing still
Finding comfort in a distant past

Slaves of yesterday
You are blind
Blind to the sunrise

A roaming spirit, forever lost
Among the living
Walking down the fatal road
Cursed to be left behind

Slaves of yesterday
You are blind
Blind to the sunrise

Slaves of yesterday
Slaves of yesterday

Slaves of yesterday
You are blind
Blind to the sunrise
Blind to the sunrise
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
#define bs 1000000009
#define bsize 256
#define nice dhhssgsggsgsgs

using namespace std;

vector<long> vec1,vec2;
long n,m;
long q;
long par[11000][111];

vector<long> solve(long l)
{
 for (int i=0;i<=10000;i++)
  for (int ttl=0;ttl<=l;ttl++)
   par[i][ttl]=0;
 for (int i=1;i<=100;i++)
 par[i*i][1]=i;
 for (int i=0;i<=10000;i++)
  for (int j=1;j<l;j++)
   for (int ad=0;ad<=100;ad++)
   {
    if (par[i][j]==0)continue;
    if (ad*ad+i>10000)continue;
    if (par[i+ad*ad][j+1])continue;
    par[i+ad*ad][j+1]=ad;
   }
 q=10000;
 vector<long> ans;
 for (int i=l;i;--i)
 {
  ans.push_back(par[q][i]);
  q-=par[q][i]*par[q][i];
 }
 return ans;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
vec1=solve(n);
vec2=solve(m);

for (int i=0;i<n;i++)
{
 for (int j=0;j<m;j++)
 {
  cout<<vec1[i]*vec2[j]<<" ";
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}