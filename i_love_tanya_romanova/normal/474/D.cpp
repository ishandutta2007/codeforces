/*
Came out of nowhere and our eyes collide
Like a wall collapsing, a crushing tide
And I saw you laughing and I saw your smile
And it made me anxious baby, it made me high

You ask, I answer no, that seat's been removed
You're a deep rooted tree, an artist's muse
And I watch you listen and I watch you share
And you make me want more and you make me scared
And you're so much more than I'd ever hoped

So, won't you breathe?
Oh, won't you breathe?
Breathe me in
So, I am whole

Oh, won't you breathe?
Oh, won't you breathe?
Breathe me in
So, I am whole

And we're miles from home, we're one another's tribe
An autumn season in a summer's time
And I watch you circle, baby, I watch you fall
And you make me feel what I thought I could never feel at all
And you're so much more than I'd ever hoped

So, won't you breathe?
Oh, won't you breathe?
Breathe me in
So, I am whole

Oh, won't you breathe?
Oh, won't you breathe?
Breathe me in
So, I am whole

Let it out, let it go, okay to breathe
Let it out, let it go, okay
So much more than
Oh, let it out, let it go, okay to breathe
Let it out, let it go, okay
So much more than

So much more than I had ever hoped
So much more than I had ever
So much more than I had ever
So much more than I had ever hoped

Oh, won't you breathe me in?
Oh, won't you breathe me in?
Oh, won't you breathe me in?
Oh, won't you breathe me in?
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
#define free adsgasdg

using namespace std;

long tests,k,dp[1<<18],s[1<<18],l,r;

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests>>k;
dp[0]=1;
s[0]=1;
for (int i=1;i<=100000;i++)
{
    dp[i]=dp[i-1];
    if (i>=k)dp[i]+=dp[i-k];
    dp[i]%=bs;
    s[i]=s[i-1]+dp[i];
    s[i]%=bs;
}

for (;tests;--tests)
{
 cin>>l>>r;
 cout<<(s[r]-s[l-1]+bs)%bs<<endl;
}
cin.get();cin.get();
return 0;}