/*
State of love and trust as I busted down the pretext
Sin still plays and preaches, but to have an empty court, uh huh
And the signs are passin', grip the wheel, can't read it
Sacrifice receiving the smell that's on my hands, hands, yeah

And I listen for the voice inside my head
Nothin', I'll do this one myself

Lay her down as priest does, should the Lord be accountin'
Will be in my honor, make it pain, painfully quick, uh huh
Promises are whispered in the age of darkness
Want to be enlightened like I want to be told the end, end, yeah

And the barrel shakes aimed a directly at my head
Oh, help me, help me from myself
And I listen from both sides of a friend
Nothin', I'll do this one myself
Myself, myself

Hey, na na na na, hey that's something
Hey, na na na na, hey that's something
Hey, na na na na, hey that's something
Wanna back, back it away, yeah

And I listen, yeah, for the voice inside my head
Nothin', I'll do this one myself
Oh, ah, and the barrel waits, trigger shakes
Aimed right at my head, don't won't you help me
Help me from myself

State of love and trust, and a
State of love and trust, and a
State of love and trust, and a
State of love and yeah yeah
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

long n,m,d,ans;

long bd(long a,long b)
{
 long res=1e9;
 res=min(res,a);
 res=min(res,b);
 res=min(res,n-a+1);
 res=min(res,m-b+1);
 return res;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>d;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  if (i%2==j%2)
   if (bd(i,j)==d)++ans;

cout<<ans<<endl;
cin.get();cin.get();
return 0;}