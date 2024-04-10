/*
All is gone now, atone
Linear time overthrown
When you find it's all a lie
All worlds will die

Time was all mine, I know
Read the signs that I've shown
If you read between the lines
You'll know once the end comes

Signs will arrive tonight
Guiding light decrease my pain
That I created on my own

Blind be my eyes tonight
Hide the sight that sees in vain
Before and after is all done
And everything is in time gone

As I moved into worlds forsaken
I saw things mankind can never own
When we move on through minds awaken
Die while you're alive and then you'll know

Speak to mankind
Through the raining light benign

Signs will arrive tonight
Guiding light decrease my pain
That I created on my own

Blind be my eyes tonight
Hide the sight that sees in vain
Before and after is all done
And everything is in time gone

Signs will arrive tonight
Guiding light decrease my pain
That I created on my own

Blind be my eyes tonight
Hide the sight that sees in vain
Before and after is all done
And everything is in time gone
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

long n,m,h,ts,calc[2000];
double p2,p1;

double gc(long n,long m)
{
 if (m>n)return 0;
 double res=0;
 for (int i=n;i>n-m;i--)
  res=res+log(i+.0),res=res-log(.0+n-i+1);
 return exp(res);
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>h;
for (int i=1;i<=m;i++)
{
 cin>>calc[i];
 ts+=calc[i];
}

if (ts<n){cout<<-1<<endl;return 0;}
if (n==1){cout<<0<<endl;return 0;}
if (calc[h]==1){cout<<0<<endl;return 0;}
--n;
--calc[h];
--ts;

double ans=1.0;
for (int i=1;i<=n;i++)
ans=ans*(ts-calc[h]-i+1)/(ts-i+1);

cout<<fixed<<1.0-ans<<endl;

cin.get();cin.get();
return 0;}