/*
What else should I be
All apologies
What else could I say
Everyone is gay
What else could I write
I don't have the right
What else should I be
All apologies

In the sun
In the sun I feel as one
In the sun
In the sun
I'm married
Buried

I wish I was like you
Easily amused
Find my nest of salt
Everything is my fault
I'll take all the blame
Aqua seafoam shame
Sunburn with freezeburn
Choking on the ashes of her enemy

In the sun
In the sun I feel as one
In the sun
In the sun
Married, Maried, Maried!
Buried!
Yeah yeah yeah yeah

All in all is all we are [x20]
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

long long n,ans,ar[200000];

int main(){
//freopen("sumdist.in","r",stdin);
//freopen("sumdist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
cin>>ar[i];
for (int i=1;i<n;i++)
if (ar[i]<ar[i-1])ans+=ar[i-1]-ar[i];
cout<<ans<<endl;

cin.get();cin.get();
return 0;}