/*
Love made a fool of me, I am betrayed by love
I let her in my secrets, my heart
I still fall for her beauty and the smell of her skin
She gave a meaning to everything

There in the woods she taught me how to touch a girl
I taught her to enchant any person in the world

I feel my end is near, I think I have to die
I pay a high price feeling lust between her thighs
I feel my end is near, I thought I knew her well
How could I ever be cast under my own spell

And now my bride is gone, she finally sealed my fate
I love her more than life and this is what she takes
A man with a broken heart, lost the reason to live
Lost in despair with nothing left to give

There in the woods she taught me how to touch a girl
I taught her to enchant any person in the world

I feel my end is near, I think I have to die
I pay a high price feeling lust between her thighs
I feel my end is near, I thought I knew her well
How could I ever be cast under my own spell

I feel my end is near, I think I have to die
I pay a high price feeling lust between her thighs
I feel my end is near, I thought I knew her well
How could I ever be cast under my own spell
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

long n,ar[20000];
long dp[4500][4500];
long nxt[5000];
long pp,answ;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

if (n==1){cout<<1<<endl;return 0;}

for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
 {
  if (ar[j]==ar[i]){nxt[i]=j;break;}
 }

for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
  dp[i][j]=2;

for (int i=1;i<=n;i++)
{
 pp=nxt[i];
 for (int j=i+1;j<=n;j++)
 {
  if (pp<=j)pp=nxt[pp];
  if (pp==0)break;
  dp[j][pp]=max(dp[j][pp],dp[i][j]+1);
 }
}

answ=0;
for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  answ=max(answ,dp[i][j]);
 cout<<answ<<endl;
 
cin.get();cin.get();
return 0;}