/*
Yeah, I feel you too
Feel those things you do
In your eyes I see a fire that burns
To free the you

That's running through
Deep inside you know
Seeds I plant will grow

One day you will see
And dare to come down to me
Yeah, come on, come on now take the chance
That's right, let's dance

Snake, I am a snake
Tempting that bite you take
Let me make your mind
Leave yourself behind

Be not afraid
I've got what you need
Hunger I will feed

One day you will see
And dare to come down to me
Yeah, come on, come on now take the chance
Ha, ha, come dance

Yeah, come dancing

One day you will see
And dare to come down to me
Yeah, come on, come on now take the chance

Yeah, I feel you too
Feel those things you do
In your eyes I see a fire that burns
To free the you

That's running through
Deep inside you know
Seeds I plant will grow

One day you will see
And dare to come down to me
Yeah, come on, come on now take the chance
That's right, let's dance

Mmm, it's nice to see you here
Ha, ha
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long long h,n,l,dir,span,ans;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>h>>n;

span=(1ll<<h)/2;
l=1;

dir=0;

while (span>0)
{
// cout<<l<<" "<<span<<" "<<ans<<endl;
 ans++;
 if (l+span-1<n&&dir==0)
 {
  ans+=2*span-1;
 }
 if (l+span-1>=n&&dir==1)
 {
  ans+=2*span-1;
 }
 if (dir==0&&l+span-1>=n)dir^=1;
 if (dir==1&&l+span-1<n)dir^=1;
 if (l+span-1<n)
  l+=span;
 span/=2;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}