/*
The job is done and I go out
Another boring day
I leave it all behind me now
So many worlds away

I meet my girl, she's dressed to kill
But all we gonna do
Is walk around to catch the thrill
On streets we call the zoo

We eat the night, we drink the time
Make our dreams come true
And hungry eyes are passing by
On streets we call the zoo

We eat the night, we drink the time
Make our dreams come true
And hungry eyes are passing by
On streets we call the zoo

Enjoy the zoo
And walk down 42nd street
You wanna be excited too
And you will feel the heat

We eat the night, we drink the time
Make our dreams come true
And hungry eyes are passing by
On streets we call the zoo

We eat the night, we drink the time
Make our dreams come true
And hungry eyes are passing by
On streets we call the zoo
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
#define right adsgasgadsg

using namespace std;

long n,m,a,b,ar[20][20];
long long dp[1<<19][20];
long long answ;
long q;

long gsmall(long x)
{
 long p=0;
 while (!(x&(1<<p)))++p;
 return p;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=0;i<m;i++)
{
 cin>>a>>b;
 --a,--b;
 ar[a][b]=ar[b][a]=1;
}

for (int i=0;i<n;i++) 
dp[(1<<i)][i]=1;

for (int mask=1;mask<(1<<n);mask++)
 for (int last=0;last<n;last++)
  if (dp[mask][last])
  {
   q=gsmall(mask);
   for (int j=q+1;j<n;j++)
   {
    if ((mask&(1<<j))==0)
     if (ar[last][j]==1)
     {
      dp[mask|(1<<j)][j]+=dp[mask][last];
     }
   }
  }

for (int mask=1;mask<(1<<n);mask++)
{
 q=gsmall(mask);
 for (int j=0;j<n;j++)
  if (ar[j][q])
   answ+=dp[mask][j];
}

for (int i=0;i<n;i++)
 for (int j=i+1;j<n;j++) 
 answ-=ar[i][j];// a->b->a
 
 answ/=2; // orientd
 
cout<<answ<<endl;


cin.get();cin.get();
return 0;}