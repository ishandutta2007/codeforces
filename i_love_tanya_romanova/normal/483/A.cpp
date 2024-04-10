/*
Spread the fragile wings, reach for the sky
Leave all sadness behind
Higher and higher to reach the stars
A mere butterfly in the storm of life

From earth you are born
And back to earth you are drawn
Death's own all the same
The wise, the strong, the frail

Spread the fragile wings, reach for it all
Sun burns the wings, greedy ones must fall
A dreamer soul burns like a candle
Lit from both ends
Thirsty heart can never be quenched

From earth you are born
And back to earth you are drawn
Death's own all the same
The wise, the strong, the frail

Remember when you were born
At that same moment
You were sentenced to die
And to carry the burden of life
Our dreams are built into castles
And those walls will crumble down
Nothing is forever, to each his own

Spread the fragile wings, reach it for the last time
The tireless hope to live a good life
Our hope is in vain, our wishes will never come true
Each life will end, every dream will die

Remember when you were born
At that same moment
You were sentenced to die
And to carry the burden of life
Our dreams are built into castles
And those walls will crumble down
Nothing is forever, to each his own
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
#define free adsgasdg

using namespace std;

long long l,r,aa,ab,ac;
long long gcd(long long a,long long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>l>>r;
for (long long a=l;a<=r;a++)
 for (long long b=a+1;b<=r;b++)
  for (long long c=b+1;c<=r;c++)
   if (gcd(a,b)==1&&gcd(b,c)==1&&gcd(a,c)>1)
    aa=a,ab=b,ac=c;

if (aa==0)
cout<<-1<<endl;
else cout<<aa<<" "<<ab<<" "<<ac<<endl;

cin.get();cin.get();
return 0;}