/*
Artificial red, smoke, poison consumed
In the house of ill repute
Is this the way I spend my days
In recovery of a fatal disease?

Ooh, ooh
Ooh, ooh

On a cloud of pink has turn to gray
And I'm alone again, yeah
Someone to hold against my own
Alone, untouched is what I crave

Ooh, ooh
Ooh, ooh

Artificial red, smoke, poison consumed
In the house of ill repute
Is this the place I search for love
When my need is within me, a gift from above?

Ooh, ooh
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

long long n,q,calc[200000];
long long answ,dp[200000];
long long pre;

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
 calc[q]++;
}

for (int i=1;i<=100000;i++)
{
 dp[i]=max(dp[i],dp[i-1]);
 if (i==1)pre=0;
 else pre=dp[i-2];
 dp[i]=max(dp[i],pre+1ll*calc[i]*i);
}

answ=0;
for (int i=1;i<=100000;i++)
 answ=max(answ,dp[i]);

cout<<answ<<endl;

cin.get();cin.get();
return 0;}