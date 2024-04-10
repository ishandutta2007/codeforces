/*
Crave
Consume
Possess
Discard

Deceive
Derange
Destruct
Repeat

In modern ivory towers
Existence is dehumanized
When complacency calculates
Exploitation becomes relative

Forging the blade for your decapitation
Orchestrating downfall
Preaching excessiveness

The downside of contentment
The vile philosophy
Of a system poised to fail itself

All hail the meltdown
Unite under the banner of gluttony
Bear witness to the great experiment
Of poverty through profit

A culture of avarice
Detached from reason

So scream the primal scream of greed
And pound the drums of ruin
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
#include <ctime> 
 
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

long long n,a[1<<20],b[1<<20],s,mn,ans[1<<20];
vector<long long> v;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>a[i];
for (int i=1;i<=n;i++)
 cin>>b[i];

s=0;
mn=1e18;

for (int i=1;i<=n;i++)
{
 s+=a[i]-b[i];
 if (s<mn)mn=s;   
}

for (int i=1;i<=n;i++)
{
    if (mn>=0) ans[i]=1;
    mn+=b[i]-a[i];
}

s=0;
mn=1e18;

for (int i=1;i<=n;i++)
{
 if (i<n-i+1)
  swap(a[i],a[n-i+1]);
 if (i<n-i)
  swap(b[i],b[n-i]);
}

for (int i=1;i<=n;i++)
{
 s+=a[i]-b[i];
 if (s<mn)mn=s;   
}

for (int i=1;i<=n;i++)
{
    if (mn>=0) ans[n-i+1]=1;
    mn+=b[i]-a[i];
}

for (int i=1;i<=n;i++)
 if (ans[i])
  v.push_back(i);

cout<<v.size()<<endl;
for (int i=0;i<v.size();i++)
{
    if (i)cout<<" ";
    cout<<v[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}