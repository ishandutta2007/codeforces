/*
Lend me your steel-bearing hand
So I may reign the jewel throne
My soul feels the Gods' demand
As the lost Kings uphold my side

Blood and sand
Mark their way
The usurper's tears
Guide my sword, hey
I said, hey

Fantasia slept in my thoughts
As I was a son of infinity
The emperor, forgotten, rests in my dreams
As, back to the wall, I start the conquest

Blood and sand
Mark their way
The usurper's tears
Guide my sword

Innocence and wrath
Now lie far beyond
As we cross the deserts
To reach the fortress' gates
Tragical serenades
Are whispered in the wind
As eyes in fury
Grant us our strength

Throning on the dignity of might
But the successor is to enter the hall
False truth saw them climbing the steps
But I remain the jewel throne's choice

Blood and sand
Mark their way
The usurper's tears
Guide my sword
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

long n,q,has[200000][22],can[1<<21],s[200000][22];
long nxt[200000][22];
long ans;

void check(long l,long r)
{
 long val=0;
 for (int i=0;i<20;i++)
  if (s[r][i]!=s[l-1][i])
   val|=(1<<i);
  can[val]=1;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 for (int j=0;j<20;j++)
  if (q&(1<<j))has[i][j]=1;
}

for (int i=1;i<=n;i++)
 for (int j=0;j<20;j++)
  s[i][j]=s[i-1][j]+has[i][j];

for (int i=19;i+1;--i)
 nxt[n][i]=n;

for (int i=n-1;i;--i)
{
 for (int j=0;j<20;j++)
 {
  nxt[i][j]=nxt[i+1][j];
  if (has[i][j])nxt[i][j]=i;
 }
}

for (int i=1;i<=n;i++)
{
 for (int j=0;j<20;j++)
  {check(i,nxt[i][j]);
  }
 check(i,i); 
}

for (int i=0;i<(1<<20);i++)
 if (can[i])++ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}