/*
Dark years brought endless rain,
out in the cold I lost my way.
but storms won't last, they clear the air
for something new
the sun came out and brought you through.

A lifetime full of words to say,
A hope that time will slow the passing day.

I've been wrong, time's over
and I've been shamed with no words to find.
But if the sun will rise, bring us tomorrow,
walk with me.
Crimson day.

Don't speak, no use for words
lie in my arms, sleep secure.
I wonder what you're dreaming of,
lands rare and far
A timeless flight to reach the stars.

A lifetime full of words to say,
a hope that time will slow the passing day.

I've been wrong, time's over
and I've been shamed with no words to find.
But if the sun will rise, bring us tomorrow,
walk with me.
Crimson day.

I've come so far to meet you here,
to share this life with one I hold so dear.
and I won't speak but what is true,
the world outside is created just for you.
It's for you, for you.

I've been wrong, time's over
and I've been shamed with no words to find.
But if the sun will rise, bring us tomorrow,
walk with me.
Crimson day.
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long n,m,bb,s,ans;

long long solve(long long a,long long b,long long s)
{
     if (s%2==0)return 0;
     if (a*b==s)return 2*(a/2+1)*(b/2+1)-1;
     long long res=0;
     long long todel=a*b-s;
     if (todel%4)return 0;
     todel/=4;
     
     for (int i=1;i<=a/2;i++)
     {
      if (todel%i)continue;
      bb=todel/i;
      if (bb*2>b)continue;
      res+=2;   
     }
     return res;
}
int main(){
//freopen("line3.in","r",stdin);
//freopen("line3.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>s;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (i*j>=s)
ans+=1ll*(n-i+1)*(m-j+1)*solve(i,j,s);

cout<<ans<<endl;

cin.get();cin.get();
return 0;}