/*
Fate silent warriors sleeping souls will arise.
Once forgotten soldiers come to life.
Fallen mercenary, dormancy is done,
Not content with wars we never won.

Memories can't ignore
Anguish of before
Satisfy the scorn.
Rise ghosts of war.

Target assassinate, time of your life has expired.
Hatred victimize, gaze in their eyes as they die.
Violence inflicting of pain, savage morticians deny
Drive the salt in the wound, arouse the subconscious to lie.

(Memories can't ignore
Anguish of before
Satisfy the scorn.
Rise ghosts of war.)

I deal in pain.
All life I drain.
I dominate.
I seal your fate.
I deal in pain.
All life I drain.
Memories can't ignore,
Rise ghost of war.
*/

#pragma comment(linker, "/STACK:16777216")
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

vector<long long> v;
vector<long long> v1[10000];
long long pr[10000];
long long q,n,tval,tdeg;
long long bigg;
long long dp[1005];

int main(){
//freopen("cooling.in","r",stdin);
//freopen("cooling.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

bigg=1000000000;
bigg*=1000000000;

pr[1]=1;
for(int i=2;i<=1000;i++)
if (pr[i]==0)for (int j=i*2;j<=1000;j+=i)
pr[j]=1;

for (int i=1;i<=1000;i++)
if (pr[i]==0)v.push_back(i);

for (int i=0;i<v.size();i++)
{
 q=1;
 v1[i].push_back(q);
 
 while (true)
 {
  if (bigg/v[i]<q)break;
  q*=v[i];
  v1[i].push_back(q);
 }
    
}

for (int i=0;i<=1000;i++)
dp[i]=bigg+1;

dp[1]=1;

for (int i=0;i<v.size();i++)
{
    for (int j=1000;j>=1;--j)
    {
    
    for (int q=0;q<v1[i].size();q++)
    {
     tdeg=j*(q+1);
     if (tdeg>1000)continue;
     if (bigg/v1[i][q]<dp[j])continue;
     tval=dp[j]*v1[i][q];
     if (tval<dp[tdeg])dp[tdeg]=tval;
    }
    
    }
}

cin>>n;
cout<<dp[n]<<endl;

cin.get();cin.get();
return 0;}