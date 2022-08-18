/*
Do you see what I see?
Truth is an offence
Your silence for your confidence

Do you hear what I hear?
Doors are slamming shut
Limit your imagination
Keep you where they must

Do you feel what I feel?
Bittering distress
Who decides what you express?

Do you take what I take?
Endurance is the word
Moving back instead of forward
Seems to me absurd

Doesn't matter what you see
Or into it, what you read
You can do it your own way
If it's done just how I say

Independence limited
Freedom of choice is made for you my friend
Freedom of speech is words that they will bend
Freedom with their exception

Do you fear what I fear?
Living properly
Truths to you are lies to me

Do you choose what I choose?
More alternatives
Energy derives from both the plus and negative

Do you need what I need?
Boundaries overthrown
Look inside to each his own

Do you trust what I trust?
Me, myself and I
Penetrate the smokescreen
I see through the selfish lie

Doesn't matter what you see
Or into it, what you read
You can do it your own way
If it's done just how I say

Independence limited
Freedom of choice is made for you my friend
Freedom of speech is words that they will bend
Freedom with their exception

Do you know what I know?
Your money and your wealth
You silence just to hear yourself

Do you want what I want?
Desire not a thing
I hunger after independence
Lengthen freedom's ring

Doesn't matter what you see
Or into it, what you read
You can do it your own way
If it's done just how I say

Independence limited
Freedom of choice is made for you my friend
Freedom of speech is words that they will bend
Freedom no longer frees you

Doesn't matter what you see
Or into it, what you read
You can do it your own way
If it's done just how I say
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
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long long n,k,m,pw[10000],dp[1050][1050][3];
long long nrem,ttl[1<<20],ans,q;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k>>m;

pw[1]=1%k;
for (int i=2;i<=n;i++)
 pw[i]=pw[i-1]*10%k;
 
dp[0][0][0]=1;
for (int i=0;i<n;i++)
{
 for (int rem=0;rem<k;rem++)
 for (int hd=0;hd<2;hd++)
 {
  for (int dig=0;dig<10;dig++)
  {
   nrem=rem+pw[i+1]*dig;
   nrem%=k;
   if (nrem==0&&(hd>0||dig>0))
    ttl[i+1]=(ttl[i+1]+dp[i][rem][hd])%m;
   else
    dp[i+1][nrem][hd|(dig>0)]=(dp[i+1][nrem][hd|(dig>0)]+dp[i][rem][hd])%m;
  }
 }
}

ans=ttl[n];
q=9;
for (int i=n-1;i;--i)
{
 ans+=q*ttl[i];
 ans%=m;
 q=q*10%m;
}
ans%=m;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}