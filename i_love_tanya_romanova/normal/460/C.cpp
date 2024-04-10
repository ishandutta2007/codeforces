/*
I run my calm on fumes.
I run my calm on fumes.

I've let you have your way around.
But I'm warning you.
I'm warning you.

You pushed me just that one more time.
And I'm done with you.
Oh I'm done with you.

Down to the bone.
I go with the wild.
You're down to the bone.
I go with the wild.

Eleven.
Eleven.

I run my calm on fumes.
I run my calm on fumes.

I've made my peace with cut and bruise.
A long time ago.
Used to be so small.

But now I've listened to your last excuse.
See I'm stronger now.
So much stronger now.

All muscle and bone.
I go with the wild.
All muscle and bone.
I go with the wild.

Eleven.
Eleven.
Eleven.

I go with the wild.
You're down to the bone.

Eleven.
I go with the wild.
You're down to the bone.

Eleven.
Eleven.

Down to the bone.
Eleven.
Muscle and bone.
Eleven.
I go with the wild...
You're down to my bone.
Eleven.
I go with the wild.
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
#define right adsgasgadsg

using namespace std;

long long n,m,w,ar[200000],l,r,mid;
long long th,ah,ad[200000];

bool solve(long long h)
{
 for (int i=1;i<=n;i++)
  ad[i]=0;
  ah=0;
 for (int i=1;i<=n;i++)
 {
  th=ar[i]+ah;
  if (th<h){ad[i]=h-th;}
  ah+=ad[i];
  if (i>=w)ah-=ad[i-w+1];
 }
 long long s=0;
 for (int i=1;i<=n;i++)
  s+=ad[i];
return (s<=m);
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>w;
for (int i=1;i<=n;i++)
 cin>>ar[i];

l=1;
r=2e9;
while (l<r)
{
 mid=l+r+1;
 mid/=2;
 if (solve(mid))l=mid;
 else r=mid-1;
}
cout<<l<<endl;

cin.get();cin.get();
return 0;}