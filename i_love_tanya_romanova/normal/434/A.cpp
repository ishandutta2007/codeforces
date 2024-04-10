/*
Hey, I'm your life
I'm the one who takes you there
Hey, I'm your life
I'm the one who cares

They, they betray
I'm your only true friend now
They, they'll betray
I'm forever there

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your dream, mind astray
I'm your eyes while you're away
I'm your pain while you repay
You know it's sad but true, sad but true

You, you're my mask
You're my cover, my shelter
You, you're my mask
You're the one who's blamed

Do, do my work
Do my dirty work, scapegoat
Do, do my deeds
For you're the one who's shamed

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your dream, mind astray
I'm your eyes while you're away
I'm your pain while you repay
You know it's sad but true, sad but true

I'm your dreams, I'm your eyes, I'm your pain
I'm your dreams, I'm your eyes, I'm your pain
You know it's sad but true

Hate, I'm your hate
I'm your hate when you want love
Pay, pay the price
Pay for nothing's fair

Hey, I'm your life
I'm the one who took you there
Hey, I'm your life
And I no longer care

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your truth, telling lies
I'm your reasoned alibis
I'm inside, open your eyes
I'm you, sad but true
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

long long n,m,ar[200000];
vector<long long> v[200000];
long long ans;
long long s,s1,q;
long long p,done[200000];
long long h,h1;
long long prev;

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>n;
prev=-1;
for (int i=1;i<=n;i++){
cin>>ar[i];if (ar[i]==prev)continue;
if (i>1)v[ar[i]].push_back(prev);
if (i>1)v[prev].push_back(ar[i]);
prev=ar[i];}

for (int i=2;i<=n;i++)
 ans+=abs(ar[i]-ar[i-1]);

s=ans;

for (int i=1;i<=n;i++)
{
 if (done[ar[i]])continue;
 q=ar[i];
 done[q]=1;
 h=0;
 for (int j=0;j<v[q].size();j++)
  h+=abs(v[q][j]-q);
 sort(v[q].begin(),v[q].end());
 p=v[q].size()/2;
 h1=0;
 for (int j=0;j<v[q].size();j++)
  h1+=abs(v[q][j]-v[q][p]);
 ans=min(ans,s-h+h1);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}