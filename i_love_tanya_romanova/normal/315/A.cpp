/*
Looking back through time to my childhood days
I used to have a place where I could escape the reality
But lately things have been so difficult for me
trying to reach for the light in the fall of darkness

Waiting watching my life I'm wasting my time
I'm losing grip from life
Going back to my dreamspace leaving it all behind
soon the things will be allright when I get there

Am I safe in here, nothing left to fear
I will close my eyes and float away with stream

Wandering here in this eternal darkness
no signs of light anywhere I am going in sane
Now I am leaving this life
No hope left I want to die
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

long n,a[100000],b[100000],ans,fl[10000];

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>a[i]>>b[i];
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
if (i-j)
if (b[j]==a[i])fl[i]=1;
for (int i=1;i<=n;i++)
ans+=fl[i];
cout<<n-ans<<endl;

cin.get();cin.get();
return 0;}