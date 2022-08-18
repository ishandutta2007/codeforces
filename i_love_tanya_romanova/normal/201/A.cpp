/*
One baby to another says I'm lucky to have met you
I don't care what you think unless it is about me
It is now my duty to completely drain you
I travel through a tube and end up in your infection

Chew your meat for you, pass it back and forth
In a passionate kiss from my mouth to yours
I like you

With eyes so dilated I've become your pupil
You've taught me everything without a poison apple
The water is so yellow, I'm a healthy student
Indebted and so grateful, vacuum out the fluids

Chew your meat for you, pass it back and forth
In a passionate kiss from my mouth to yours
I like you

You, you, you
You, you

One baby to another says I'm lucky to have met you
I don't care what you think unless it is about me
It is now my duty to completely drain you
I travel through a tube and end up in your infection

Chew your meat for you, pass it back and forth
In a passionate kiss from my mouth to yours
Sloppy lips to lips, you're my vitamins
I like you
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

using namespace std;

long x,ans;
long upr;

bool has(long l,long val)
{
 upr=l*l/2+1;
 if (upr>=val)return true;
 return false;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x;
for (int i=1;i<=100;i+=2)
 if (has(i,x))
  {ans=i;break;}

if (x==3)ans=5;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}