/*
Move it to the front
Reaching for the light
Loosin' all control
Using all your might
Wheels are gonna spin
Asses gonna shake
We are gonna kick
Walls are gonna break

The road is hard
The fight is tough
Gonna play it fast
She likes it rough
With my strength
With all my soul
Makin' love
I'm losing control

Guts begin to churn
Minds are in a haze
Hell is gonna burn
Axes in a blaze
Go in for the kill
Always on the run
Fighting for you life
The battle's never won

The road is hard
The fight is tough
Gonna play it fast
She likes it rough
With my strength
With all my soul
Makin' love
I'm losing control

Move it to the front
Reaching for the light
Losin' all control
Using all your might
Wheels are gonna spin
Asses gonna shake
We are gonna kick
Walls are gonna break

Backs are turned
Rock an' roll
To the wall
I'm losing my mind
Yea!
Hey, hey!
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

long long c[2200][2200],n,m,k,res;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;

for (int i=0;i<=2000;i++) 
 for (int j=0;j<=i;j++)
  if (j==0||j==i)
   c[i][j]=1;
   else c[i][j]=
   (c[i-1][j]+c[i-1][j-1])%bs;

res=c[n-1][2*k]*c[m-1][2*k];
res%=bs;
cout<<res<<endl;

cin.get();cin.get();
return 0;}