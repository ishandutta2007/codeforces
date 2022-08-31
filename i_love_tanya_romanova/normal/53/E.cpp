/*
He's in a rush run
He has to hurry dash
He's in a rat race
Never at a slow pace

Forever dangerous
And never serious
Up on your energy
Expect no sympathy

Appreciation is overrated
Resting is for fools

He lets his blood boil
Always in turmoil
Blasting his every way
Throughout the shortest day

Forever dangerous
And never serious
Swimming against the stream
And steal all of your dreams

Aggravation is appreciated
He'll use you like a tool
Association is overrated
Friends are for fools

He's in a rush
Fever round his eyes
I do not dare and cross him
He'll smash you with his lies

Ever so dangerous
He'll haunt you seriously
I wouldn't go within a mile radius of him
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
#define bs 1000000009
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,m,k,a,b,ar[20][20],dp[1<<10][1<<10];
long ans;
long cnt[1<<20];
long kk;

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>kk;
for (int i=0;i<m;i++)
{
 cin>>a>>b;
 --a;
 --b;
 ar[a][b]=ar[b][a]=1;
 dp[(1<<a)+(1<<b)][(1<<a)+(1<<b)]=1;
}

for (int i=0;i<=(1<<n);i++)
 cnt[i]=cnt[i/2]+i%2;

for (int mask1=1;mask1<(1<<n);mask1++)
 for (int mask2=1;mask2<(1<<n);mask2++)
  for (int k=0;k<n;k++)
    if (mask1&(1<<k))
     for (int q=0;q<n;q++)
     {
         if (dp[mask1][mask2]==0)continue;
         if (ar[k][q]==0)continue;
         if ((mask1&(1<<q)))continue;
         int nmask=mask2; // leaves
         if (mask2&(1<<k))
          nmask-=(1<<k);
         nmask+=(1<<q);
       //  cout<<mask1<<" "<<mask2<<"  "<<nmask<<" "<<k<<" "<<q<<endl;
         if (nmask&((1<<q)-1))
         continue;
         dp[mask1+(1<<q)][nmask]+=dp[mask1][mask2];
     }
/*
for (int i=0;i<(1<<n);i++)
cout<<i<<" ^  "<<dp[(1<<n)-1][i]<<endl;
*/
for (int i=0;i<(1<<n);i++)
 if(cnt[i]==kk)
  ans+=dp[(1<<n)-1][i];

cout<<ans<<endl;

cin.get();cin.get();
return 0;}