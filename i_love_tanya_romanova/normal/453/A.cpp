/*
We've waited far too long
To watch it all crash and fall through
So when you feel like shit
You've gotta keep on pushin'

If you saw the world through my eyes
Then you wouldn't feel so high rise
It's time to take our chance
You've gotta sit back and hold tight

And there's forces working in our heads
But we don't understand them
I need a map to find
My way out all the time

There's curses lurking in our heads
But we don't want to find them
We need to come back down
And face what we've become

We've become

The more I think the more I wish
I push stop then hit rewind
What I would give to have a day back then
When no one really cares

I remember when we all used to
Kick back, take days off school
So many times I've smiled
Many times I've cried but never did we try
Never did we try because

There's forces working in our heads
But we don't understand them
I need a map to find
My way out all the time

There's curses lurking in our heads
But we don't want to find them
We need to come back down
And face what we've become

It's haunting me, I'm so alone
I'm just trying to find my way back home
I'm so alone, alone

But there's forces working in our heads
And we don't understand them
I need a map to find
My way out all the time

'Cause curses lurking in our heads
And we don't want to find them
We need to come back down
And face what we've become
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

long n,m;

double ans,dp[200000];
double prob;

double pw(double a,long b)
{
 if (b==0)return 1;
 if (b%2)return a*pw(a,b-1);
 return pw(a*a,b/2);
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>n;

for (int mx=1;mx<=m;mx++)
{
 prob=1;
 prob=pw(mx*1.0/m,n);
 dp[mx]=prob;
}

for (int i=1;i<=m;i++)
 ans+=i*(dp[i]-dp[i-1]);
cout.precision(12);
cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}