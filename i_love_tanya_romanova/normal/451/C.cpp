/*
In the corner beside my window
There hangs a lonely photograph
There is no reason I'd never notice
A memory that could hold me back

There is a wound that's always bleeding
There is a road I'm always walking
And I know you'll never return to this place

Gone through days without talking
There is a comfort in silence
So used to losing all ambition
Struggling to maintain what's left

There is a wound that's always bleeding
There is a road I'm always walking
And I know you'll never return to this place

Once undone, there's only smoke
Burning in my eyes to blind
To cover up what really happened
Force the darkness unto me

There is a wound that's always bleeding
There is a road I'm always walking
And I know you'll never return to this place
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
#define N 120000

using namespace std;

long long d1,d2,tests,n,k,d,ans;
long long tob;
long long v1,v2,v3,has,need;
long long up,dwn;

void check()
{
long long temp=k-has;
if (temp<0||temp%3>0)return;// fld
long long rem=n-k;
//cout<<rem<<"   "<<tob<<endl;
rem-=need;
if (rem<0)return ; // cn't
if (rem%3)return; // cn't
ans=1;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
 cin>>n>>k>>d1>>d2;
 ans=0;
 for (int mask=0;mask<4;mask++)
 {
  v1=0;
  v2=v1;
  if (mask&1)v2-=d1;
  else v2+=d1;
  v3=v2;
  if (mask&2)v3-=d2;
  else v3+=d2;
  up=max(max(v1,v2),v3);
  dwn=min(min(v1,v2),v3);
  has=v1+v2+v3-dwn*3;
  need=up*3-v1-v2-v3;
  check();
 }
 if (ans)cout<<"yes"<<endl;
 else cout<<"no"<<endl;
}

cin.get();cin.get();
return 0;}