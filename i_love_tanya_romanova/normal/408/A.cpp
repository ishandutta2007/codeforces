/*
Slazing scents taint with blood
Signed his path of death
Trace him to the place of fright
Searching for his daily bread
When midnight comes around
Be warned because he is out of sight

What carnal secrets does he hide
His ruthless rage will come
Buried deep inside his mind
The rites of the saw began

The saw is the law
The saw is the law

Executed children
Laughing mothers by their side
Feel the pain of ripping flesh
Those who've died
Have paid the price
And drawn their final breath

What carnal secrets does he hide
His ruthless rage will come
Buried deep inside his mind
The rites of the saw began

The saw is the law
The saw is the law

The saw is the law
The saw is the law

What carnal secrets did he hide
His worries of the flesh have come
With tears in his eyes and a gun in his hand
So ends the story of the chainsawman

The saw is the law
The saw is the law

The saw is the law
The saw is the law
The saw is the law
The saw is the law

The saw is the law
The law is the saw
The saw is the law
The law is the saw
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

long n,ans,s,sz[20000],q;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
ans=1e9;
for (int i=1;i<=n;i++)
{
    cin>>sz[i];
}
for (int i=1;i<=n;i++)
{
 s=sz[i]*15;
 for (int j=1;j<=sz[i];j++)
 {
  cin>>q;s+=q*5;
 }
 ans=min(ans,s);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}