/*
I caught a chill and it's still frozen on my skin
I think about why I'm alone by myself no one else to explain
How far do I go no one knows
If the end is so much better why don't we just live forever?

Don't tell me I'm the last one in line
Don't tell me I'm too late this time

I don't wanna live to waste another day
Underneath the shadow of mistakes I've made
'Cuz I feel like I'm breaking inside

I, I, I, I don't wanna fall and say I lost it all
'Cuz maybe there's a part of me that hit the wall
Leaving pieces of me behind
And I feel like I'm breaking inside

Out here nothing's clear
Except the moment I decided to move on and I ignited
Disappear into the fear
You know there ain't no coming back when you're still carrying the past

You can't erase, separate
Cigarette in my hand, hope you all understand
I won't be the last one in line
I finally figured out what's mine

I don't wanna live to waste another day
Underneath the shadow of mistakes I've made
'Cuz I feel like I'm breaking inside

I, I, I, I don't wanna fall and say I lost it all
'Cuz maybe there's a part of me that hit the wall
Leaving pieces of me behind, leaving pieces of me behind
And I feel like I'm breaking inside

I won't be the last one in line
I finally figured out what's mine

I don't wanna live to waste another day
Underneath the shadow of mistakes I've made
'Cuz I feel like I'm breaking inside

I, I, I, I don't wanna fall and say I lost it all
'Cuz maybe there's a part of me that hit the wall
Leaving pieces of me behind, leaving pieces of me behind
And I feel like I'm breaking inside

And I feel like I'm breaking
And I feel like I'm breaking inside
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
#define MAG 10000
#define l 19

using namespace std;

long a,b,ans;

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b;
while (a>0&&b>0&&a+b>2)
{
 if (a>b)
  ans++,
  a-=2,
  b--;
  else
  ans++,
  a--,
  b-=2;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}