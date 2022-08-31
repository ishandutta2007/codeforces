/*
New friends
Last night
An offer was made

Nordbrikt
Would leave
Five hundred strong

Long is the hour when lying awake
Sleeping his hard when so much is at stake
I've reached my goal, called the final door
Behind it- three doors more

Lying in my bed
Thinking of the things they said
Time is running out
What to do I moon about

Out in the open sea I've swum without a sight
A sight of an opposite shore, a sight of some light
Turning back, staying here, my strength is running out
Forward, or I drown

Rising from my bed
Thinking of the things they said
The moment draws nigh
One chance a year when the water is high

Corridors
I run
Heavy doors
Which one?

Where did I come from? Was I already here?
It all seems familiar, yet I have no idea

New friends
Last night
An offer was made

Nordbrikt
Would leave
Five hundred and one

"Joy and sorrow we have encountered
Always stood as one
Your heart will follow, and maybe tomorrow
You will find what you seek

Go now, and don't look back!
Bring my greetings to the Greek King!"

The wind flew the raven banner with pride
Eagles were soaring aloft
Filled with hope and excitement side by side
Five hundred and one cast off

So long is the way to the unknown
Long is the way we have come
At the head of the ships a horn was blown
We sailed off with the morning sun
Five hundred and one
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define N ((1<<21)+31)
//#define root 1
#define M 150

using namespace std;

long long t,w,b;
long long ans;
long long gcd(long long a,long long b)
{
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

long long safe(long long a,long long b)
{
	if (a==0||b==0)
		return 0;
	if (8e18/b<=a)
		return 8e18;
	return a*b;
}

long long lcm(long long a,long long b)
{
	long long q=gcd(a,b);
	a/=q;
	return safe(a,b);
}

int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	
	cin>>t>>w>>b;
	
	long long com=lcm(w,b);
	long long oh=min(w,b);
	long long full=t/com;
	
	ans+=full*oh;
	
	long long rem=t%com;
	if (rem>=oh)
		rem=oh-1;
	ans+=rem+1;
	
	--ans;
	
	long long Q=gcd(ans,t);
	cout<<ans/Q<<"/"<<t/Q<<endl;
	
	return 0;
	
}