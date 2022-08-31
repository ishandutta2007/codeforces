/*
He had an unfamiliar face
Complete life in disarray
A simple man, power drunk
No worries of living, no more anything

Deep inside I've seen it rise
Actions progress to no end
Mirror, mirror please look inside
Do you see the reasons that we sin

Not one to be forgot
Spoiled rotten, so they say
Once burned, forever marked
Hurt by just a few but so many have to pay

Pressure coming down
Down on me, gonna break
Broken fingernails
Digging in, scratch my face

Nervous, like a cat
Gonna jump through my skin
Shadows on the wall
Stretching out, grope for me

Reasons, deep in me
Let me be
Let me bleed
Set me free
The reasons that we sin
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

long n,k,t,q,ans;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
t=5-k;
for (int i=1;i<=n;i++)
{
 cin>>q;
 if (q<=t)++ans;
}
cout<<ans/3<<endl;

cin.get();cin.get();
return 0;}