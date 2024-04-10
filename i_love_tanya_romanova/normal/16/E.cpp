/*
Stuck in an ivory tower
They think paper equals power
No use to mankind
It's the blind leading the blind

How can they learn so much?
But know nothing at all
Without a book for a crutch
Falling into withdrawal

Delusion fo importance
Clouds up their feeble minds
Ignorance and intelligence
Split by a fine line

Removed from the real world
When they speak I want to hurl
Academic condemnation
Fit only for obliteration

How could it come to this?
How could it be so vile?

Fighting democracy
Doing it with a smile
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

long n;
double ar[200][200];
vector<long> v;
long ways;
double p;
double dp[1<<20];

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>n;
for (int i=0;i<n;i++)
 for (int j=0;j<n;j++)
  cin>>ar[i][j];

dp[(1<<n)-1]=1;

for (int mask=(1<<n)-1;mask+1;--mask)
{
 v.clear();
 for (int j=0;j<n;j++)
  if (mask&(1<<j))v.push_back(j);
 
 ways=v.size();
 ways=ways*(ways-1)/2;
 p=1.0/ways;
 for (int j=0;j<v.size();j++)
  for (int q=0;q<v.size();q++)
   if (j!=q)
    dp[mask-(1<<v[q])]+=dp[mask]*p*ar[v[j]][v[q]];
}

cout.precision(12);
for (int i=0;i<n;i++)
{
 if (i)cout<<" ";
 cout<<fixed<<dp[1<<i];
}
cout<<endl;

cin.get();cin.get();
return 0;}