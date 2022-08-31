/*
Satan, I promised you my soul
Master, I gave you full control
Now I changed my mind
I want to be free

Judas, he had something to sell
Still you did send him straight to hell
You just made him burn
Nothing in return

Why don't you listen to me?
Show me the door, give me the key
Unchain my soul
Please set me free

(Let me out)
Out of this prison
(Scream and shout)
Somebody listen to what I have to say
To free my mind

(Let me out)
I have a vision
(Scream and shout)
Impossible mission
To clear my soul, let go and press rewind

Darkness and hate took over me
I live my life in misery
Sold my soul too cheap
Please give it back

Find it before it is too late
Give me the key to my escape
I am not the one, please let me go

Once more I'm being blessed
My horrifying days has passed
Now I am free to live my life

(Let me out)
Out of this prison
(Scream and shout)
Somebody listen to what I have to say
To free my mind

(Let me out)
I have a vision
(Scream and shout)
Impossible mission
To clear my soul, let go and press rewind
To clear my soul, let go and press rewind

Now I'm back to where I started
Fresh as one can be
I am just as broken hearted
As the man I used to be

Do I really want this weakness?
Do I really want this pain?
Want to live my life in success
So I sold my soul again

(Let me out)
Out of this prison
(Scream and shout)
Somebody listen to what I have to say
To free my mind

(Let me out)
I have a vision
(Scream and shout)
Impossible mission
To clear my soul, let go and press rewind
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

long nmask;
long long answ;
long n,k,dp[3000][1<<13][2];
long mov;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
--k;
dp[0][0][0]=1;

for (int i=1;i<=n;i++)
{
 cin>>mov;
 
 for (int j=0;j<=(1<<k);j++)
  dp[i%2][j][0]=dp[i%2][j][1]=0;
 
 for (int mask=0;mask<(1<<k);mask++)
 {
  // add 2
  if (mov!=4)
  {
   nmask=mask+1;
   if(nmask!=(1<<k))
   {
   dp[i%2][nmask][0]=(dp[i%2][nmask][0]+dp[1-i%2][mask][0])%bs;
   dp[i%2][nmask][1]=(dp[i%2][nmask][1]+dp[1-i%2][mask][1])%bs;
   }
   else
   {
    dp[i%2][0][1]=(dp[i%2][0][1]+dp[1-i%2][mask][0])%bs;
    dp[i%2][0][1]=(dp[i%2][0][1]+dp[1-i%2][mask][1])%bs; 
   } 
  }
  // add 4
  if (mov!=2)
  {
   if (mask%2)
   {dp[i%2][2][0]=(dp[i%2][2][0]+dp[1-i%2][mask][0])%bs;
    dp[i%2][2][1]=(dp[i%2][2][1]+dp[1-i%2][mask][1])%bs;
   }
   else
   {
    nmask=mask+2;
   if(nmask!=(1<<k))
   {dp[i%2][nmask][0]=(dp[i%2][nmask][0]+dp[1-i%2][mask][0])%bs;
   dp[i%2][nmask][1]=(dp[i%2][nmask][1]+dp[1-i%2][mask][1])%bs;
   }
   else
   {
   dp[i%2][0][1]=(dp[i%2][0][1]+dp[1-i%2][mask][0])%bs;
   dp[i%2][0][1]=(dp[i%2][0][1]+dp[1-i%2][mask][1])%bs;
   }
   }
  }
 }/*
 for (int j=0;j<(1<<k);j++)
 cout<<dp[i%2][j][0]<<" "<<dp[i%2][j][1]<<endl;
 cout<<endl;*/
}

answ=0;
for (int i=0;i<(1<<k);i++)
answ=answ+dp[n%2][i][1];
cout<<answ%bs<<endl;

cin.get();cin.get();
return 0;}