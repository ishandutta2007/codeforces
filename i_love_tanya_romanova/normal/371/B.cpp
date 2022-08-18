/*
Dominance in devotion
Grabs us and disappears
Have to take some direction
Through the glass that we must break

Zero to none
Killing radical
The instinct to destroy what's left
Lives in everyone

All prepared for the moment
Yet to come complete the rest
Patriots all confused by
Characters of broken men

Zero to none
Killing radical
The instinct to destroy what's left
Lives on in everyone

A dream within a dream
A womb within a grave
Calm without a riot

Every heart, every soul, all the trust
Terror wars are radical

A dream within a dream
A womb within a grave
Calm within a riot

All the peace, all the hope, all the trust
As desperation takes everyone
God's hell is radical
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
#define eps 1e-4
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000
#define double long double

using namespace std;

long a,b,ans,deg1,deg2;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b;
deg1=deg2=0;
while (a%2==0){deg1++;a/=2;}
while (b%2==0){deg2++;b/=2;}
ans+=abs(deg1-deg2);

deg1=deg2=0;
while (a%3==0){deg1++;a/=3;}
while (b%3==0){deg2++;b/=3;}

ans+=abs(deg1-deg2);

deg1=deg2=0;
while (a%5==0){deg1++;a/=5;}
while (b%5==0){deg2++;b/=5;}
ans+=abs(deg1-deg2);

if (a-b)cout<<-1<<endl;
else cout<<ans<<endl;

cin.get();cin.get();
return 0;}