/*
A straight razor and a flick of the wrist
Brass knuckles and a willing fist
A big knife and a little scream
They do wonders for my self-esteem

Warm blood and a cold embrace
The catch is better than the chase
They all ask why I'm doing this
Violence is bliss

What you see, all I know to be
Is a madman out on a killing spree
One thing I say
I did it all my way
Gave rise to the dawn of the dying age

When I feel the urge and it's tarting to surge
Soon I'm blowing like an atom bomb
When you comprehend
Your life's coming to an end
I'm going, going, going, going, gone

Two things that I can't ignore
Dark nights and an unlocked door
I get the feeling and I follow through
I get high like I'm sniffing glue

It's time to let the games commence
This really helps my self-confidence
Blood orgy for the hedonist
Violence is bliss

What you see, all I know to be
Is a madman out on a killing spree
One thing I say
I did it all my way
Gave rise to the dawn of the dying age

When I feel the urge and it's tarting to surge
Soon I'm blowing like an atom bomb
When you comprehend
Your life's coming to an end
I'm going, going, going, going, gone

I never leave any telltale traces
Only fear frozen on dead faces
An orgasm of depravity
It's the best kind of therapy

I always flee the scene of the crime
No victims, left to drop the dime
So many lives yet to be dismissed
Violence is bliss
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

long n,m;
string tp;
long val;
vector<long> v1,v2,v3;
long dp[105][105][105][3];
long q,answ;

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
 cin>>tp>>val;
 if(tp=="ATK")v1.push_back(val);
  else v2.push_back(val);
}

for (int i=1;i<=m;i++)
{
 cin>>q;
 v3.push_back(q);
}

sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());
sort(v3.begin(),v3.end());

for (int i=0;i<=v1.size();i++)
 for (int j=0;j<=v2.size();j++)
  for (int q=0;q<=v3.size();q++)
   dp[i][j][q][0]=dp[i][j][q][1]=-1e9;
 
dp[0][0][0][0]=dp[0][0][0][1]=0;

for (int i=0;i<=v1.size();i++)
 for (int j=0;j<=v2.size();j++)
  for (int q=0;q<v3.size();q++)
  {
//   cout<<i<<"   "<<j<<"  "<<q<<"  "<<dp[i][j][q][0]<<"   "<<dp[i][j][q][1]<<endl;
   if (i<v1.size()&&v3[q]>=v1[i]) // at att
    dp[i+1][j][q+1][0]=max(dp[i+1][j][q+1][0],dp[i][j][q][0]+v3[q]-v1[i]),
    dp[i+1][j][q+1][1]=max(dp[i+1][j][q+1][1],dp[i][j][q][1]+v3[q]-v1[i]);
   if (j<v2.size()&&v3[q]>v2[j]) // att def
    dp[i][j+1][q+1][0]=max(dp[i][j+1][q+1][0],dp[i][j][q][0]),
    dp[i][j+1][q+1][1]=max(dp[i][j+1][q+1][1],dp[i][j][q][1]);
    
   dp[i][j][q+1][1]=max(dp[i][j][q+1][1],dp[i][j][q][1]+v3[q]);// s push
   
   //skp
   dp[i][j][q+1][0]=max(dp[i][j][q+1][0],dp[i][j][q][0]);
   dp[i][j][q+1][1]=max(dp[i][j][q+1][1],dp[i][j][q][1]);
   
  }

answ=0;
answ=max(answ,dp[v1.size()][v2.size()][v3.size()][1]);
//cout<<dp[v1.size()][v2.size()][v3.size()][1]<<endl;

for (int i=0;i<=v1.size();i++)
 for (int j=0;j<=v2.size();j++)
  for (int q=0;q<=v3.size();q++) 
  answ=max(answ,dp[i][j][q][0]);
 
 cout<<answ<<endl;
 
cin.get();cin.get();
return 0;}