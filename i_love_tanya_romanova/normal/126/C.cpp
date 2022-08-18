/*
We're walking in the air, we're floating in a moonlit sky
The people far below are sleeping as we fly
I'm holding very tight, I'm riding in a midnight blue
I'm finding I can fly, so high above with you

Far across the world, the villages go by like dreams
The rivers and the hills, the forests and the streams

Children gaze open mouth, taken by surprise
Nobody down below believes their eyes

We're surfing in the air, we're swimming in the frozen sky
We're drifting over ice, see mountains floating by

Suddenly swooping low on an ocean deep
Arousing of a mighty monster from its sleep

We're walking in the air, we're floating in a midnight sky
And everyone who sees us, greets us as we fly
I'm holding very, holding very tight, I'm riding in a midnight blue
I'm finding I can fly, so high above with you
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

string st;
long n,ar[2050][2050],s1[2050],s2[2050],s3[2050],s4[2050];
long cur,ans;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=st.size();j++)
  ar[i][j]=st[j-1]-48;
}

for (int i=1;i<=n;i++) // ur
 for (int j=n;j>i;j--)
 {
  cur=s1[i]+s2[j];
  cur%=2;
  if (cur!=ar[i][j]){++ans;++s1[i];++s2[j];}
 }

for (int i=n;i;i--)
 for (int j=1;j<i;j++)
 {
  cur=s3[i]+s4[j];
  cur%=2;
  if (cur!=ar[i][j]){++ans;++s3[i];++s4[j];}
 }

for (int i=1;i<=n;i++)
{
 cur=s1[i]+s2[i]+s3[i]+s4[i];
 cur%=2;
 if (cur!=ar[i][i])++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}