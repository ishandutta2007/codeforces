/*
Scrape the pain off of my lips and watch our lives unwind
When I am in the camera eye self-immolation can never purify

Look at me, I'm on display
Another animal in this zoo our creator betrayed
If you don't feel the lesson, you're blind and deaf my son
But don't run

Look at me, I'm on the wire

I am not your saviour

Scrape the pain off of my lips and watch our lives unwind
When I am in the camera eye self-immolation can never purify

I am not your saviour

Look at me, I'm never afraid
I'll never look back in disdain

Scrape the pain off of my lips and watch our lives unwind
When I am in the camera eye self-immolation can never purify
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
//#include <memory.h>

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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,tp[200000];
double dou;
long ans[20000];
long answ;

int main(){
//freopen("test.in","r",stdin);
//freopen("test.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>tp[i]>>dou;

for (int i=1;i<=n;i++)
{
    ans[i]=-1000000;
}
for (int i=1;i<=n;i++)
{
    ans[i]=max(ans[i],n-n+1);
    for (int j=i+1;j<=n;j++)
    if (tp[j]>=tp[i])ans[j]=max(ans[j],ans[i]+1);
}
answ=0;
for (int i=1;i<=n;i++)
answ=max(answ,ans[i]);
cout<<n-answ<<endl;

cin.get();cin.get();
return 0;}