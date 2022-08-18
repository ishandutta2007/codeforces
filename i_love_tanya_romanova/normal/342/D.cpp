/*
You wanted money, you wanted fame,
You broke the rules before you know the game
Wounds tearing you up like a knife
Wish it was the end of your life, it's a nightmare
Going down that road on account of you
No escape from the things you put me through
I don't know, I don't care, I can't go anywhere,
It's a nightmare coming back to you!

Don't wanna die, just wanna live!
I've got stop taking what they give
So many roads moving all around
I only see the one going down it's a nightmare
Going down the road on account of you
No escape from the things you put me through
I don't know, I don't care, I can't go anywhere it's a nightmare
Coming back to you!

We got to fight, we got to try
When all is gone we'll know the reason why
To kill the enemy we will win the wars
To find the place our life was before, it's a nightmare
Going down that road on account of you
No escape from the things you put me through
I don't know, I don't care, I can't go anywhere
It's a nightmare coming back to you!.. to you!.. to you!..
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

char c;
long n;
long long answ;
long sti,stj;
long bad[20000][5];
long long dp[20000][9];
long bd[20000][5];

bool check(long i,long j)
{
     if (i<0)return true;
     if (i>=n)return true;
     if (j<0)return true;
     if (j>=3)return true;
     if (bad[i][j])return true;
     return false;
}

bool cput(long mask)
{
 long fl=0;
 if (mask&1){fl|=check(sti,stj-1);fl|=check(sti,stj-2);}
 if (mask&2){fl|=check(sti+1,stj);fl|=check(sti+2,stj);}
 if (mask&4){fl|=check(sti,stj+1);fl|=check(sti,stj+2);}
 if (mask&8){fl|=check(sti-1,stj);fl|=check(sti-2,stj);}
 fl=1-fl;
 return fl;
}

void sett(long a,long b){bd[a][b]=1;}

void gener(long mask)
{
 for (int i=0;i<n;i++)
 for (int j=0;j<3;j++)
 bd[i][j]=0;
 for (int i=0;i<n;i++)
  for (int j=0;j<3;j++)
   bd[i][j]=bad[i][j];
 sett(sti,stj);
 if (mask&1){sett(sti,stj-1);sett(sti,stj-2);}
 if (mask&2){sett(sti+1,stj);sett(sti+2,stj);}
 if (mask&4){sett(sti,stj+1);sett(sti,stj+2);}
 if (mask&8){sett(sti-1,stj);sett(sti-2,stj);}
}

void clean()
{
     for (int i=0;i<=n;i++)
     for (int j=0;j<=16;j++)
     dp[i][j]=0;
     dp[0][0]=1;
}

void calc(long x=0,long y=0,long mask=0,long next_mask=0)
{
 if (x==n)return;
 if (y>=3){dp[x+1][next_mask]+=dp[x][mask];dp[x+1][next_mask]%=bs;return;}
 int my_mask=(1<<y);
 if (mask&my_mask){calc(x,y+1,mask,next_mask);return;}
 if (bd[x][y]){calc(x,y+1,mask,next_mask);return;}// bl, c't put
 if (bd[x][y]==0&&bd[x+1][y]==0)calc(x,y+1,mask,next_mask|my_mask);//gor
 if (bd[x][y]==0&&bd[x][y+1]==0&&y+1<3&&!(mask&(my_mask<<1)))
 calc(x,y+2,mask,next_mask);//vert
}

void solve()
{
     for (int i=0;i<n;i++)
      for (int mask=0;mask<8;mask++)
       calc(i,0,mask,0);
}

int main(){
//freopen("revolutions.in","r",stdin);
//freopen("revolutions.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int tt=0;tt<3;tt++)
for (int i=0;i<n;i++)
{
 cin>>c;
 if (c=='O'){sti=i;stj=tt;}
 if (c=='X')bad[i][tt]=1;   
}

for (int mask=1;mask<16;++mask)
{
 if (cput(mask)==false)continue;
 gener(mask);
 clean();solve();
 
 /*for (int i=0;i<3;i++)
 {
     for (int j=0;j<n;j++)
     cout<<bd[j][i];
     cout<<endl;
 }*/
 long vbits=0;
 for (int i=0;i<4;i++)
 if (mask&(1<<i))++vbits;
 if (vbits%2)answ=answ+dp[n][0];
 else answ=answ-dp[n][0];
 
// cout<<mask<<"  "<<dp[n][0]<<endl;   
}

while(answ<0)answ+=bs;
while (answ>=bs)answ-=bs;
cout<<answ<<endl;

cin.get();cin.get();
return 0;}