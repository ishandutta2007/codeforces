/*
Clouds are darkening a moonless night
In the empire of the dead
Rain is pouring on a ground
Bare of life
The dead are rising
They're walking the streets
Of ruble and dust
As I try to stay alive

Seems as if the gods
Have finally turned away
On the edge
On the edge of judgement day
And the sentence is death
Come and take your final breath

Empire of the living dead
Unlocked by a mortal hand
Hallelujah
Empire of the living dead
Set free from the underworld
To walk the mortals land
To walk the earth

Aboulic creatures like empty shells
Are prowling the night
No escape nowhere to hide
The jaws of hell are open wide
Ready to take on the world
To destroy all humankind

But as long there is life in my veins
The hope for deliverance remains

No one will hear your prayers
No one will hear you crave
No one will hear you scream
Oh no you can't be saved

Empire of the living dead

As the sun is going down
I know that it's too late
Nothing can save me now
I know there's no escape
Doomed to die
I'm waiting for the night
For I know
I'll never see the light
Again

This is judgment day
This is judgment day

Empire of the living dead
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st;
long n,m,mod;
long ttl[1<<10];
long dp[2][666][666];
long ones,zeros;
long cur,temp;
long nxt;
long c[1<<10][1<<10];

void add(long &a,long &b)
{
 a+=b;
 if (a>=mod)a-=mod;
}

int main(){
//freopen("billing.in","r",stdin);
//freopen("billing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>n>>m>>mod;

for (int i=0;i<=1000;i++)
 for (int j=0;j<=i;j++)
  if (j==0||j==i)
   c[i][j]=1;
  else
   c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;

for (int i=1;i<=m;i++)
{
 cin>>st;
 for (int j=1;j<=n;j++)
  if (st[j-1]=='1')ttl[j]++;
}

for (int i=1;i<=n;i++)
{
 if (ttl[i]==1)++ones;
 if (ttl[i]==0)++zeros;   
}

dp[m%2][zeros][ones]=1;

for (int iter=m;iter<n;iter++)
{
    cur=iter%2;
    nxt=1-cur;
    
    for (int i=0;i<=n;i++)
     for (int j=0;j<=n-i;j++)
      dp[nxt][i][j]=0;
    
   /* for (int i=0;i<=n;i++){
     for (int j=0;j<=n;j++)
         cout<<dp[cur][i][j]<<" ";
     cout<<endl;
     }
     cout<<endl;
     */
    for (int i=0;i<=n;i++)
     for (int j=0;j<=n-i&&j+i<=(n-iter+1)*2;j++)
     {
         if (dp[cur][i][j]==0)continue;
         // two zeroes
         if (i>1)
         {
//          cout<<i<<" "<<j<<" "<<dp[cur][i][j]<<endl;
          
          temp=1ll*dp[cur][i][j]*c[i][2]%mod;
          add(dp[nxt][i-2][j+2],temp);
         }
         // 0-1
         if (i>0&&j>0)
         {
          temp=1ll*dp[cur][i][j]*i*j%mod;
          add(dp[nxt][i-1][j],temp);
         }
         // two ones
         if (j>1)
         {
          temp=1ll*dp[cur][i][j]*c[j][2]%mod;
          add(dp[nxt][i][j-2],temp);
         }
     }
}

cout<<dp[n%2][0][0]<<endl;

cin.get();cin.get();
return 0;}