/*
Should we come to sail for the mellow and grey
Would it bring us comfort say, just a rainy day away
I've got a little something on my mind
A little line of evening rhyme, a boogie bubble refrain again

Come let's dream some, come take a ride in my dream machine
Let's make a funny one, let's take a ride in my dream machine

Should we come to stray in this nightmare play
I would like to ask you if I may dream today away
And for about a year we'd loose this fear
Of old men going nowhere near the grey to play the game

Come let's dream some, come take a ride in my dream machine
Let's make a funny one, let's take a ride in my dream machine
And when the dream is done, it's time to have another one
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

long long n,ar1[200000],ar2[200000],s1[200000],s2[200000];
long long tests,l,r,tp,a,b;

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar1[i];
 ar2[i]=ar1[i];
}
sort(ar2+1,ar2+n+1);
for (int i=1;i<=n;i++)
 {
  s1[i]=s1[i-1]+ar1[i];
  s2[i]=s2[i-1]+ar2[i];
 }
cin>>tests;
for (;tests;--tests)
{
 cin>>tp>>l>>r;
 if (tp==1)cout<<s1[r]-s1[l-1]<<endl;
 else cout<<s2[r]-s2[l-1]<<endl;   
}

cin.get();cin.get();
return 0;}