/*
I'm at the point of no return
I'm watching the candle burn - both ends
There's a lesson we both can learn - this time
So if you wanna make my day
There's something you've gotta say
Now please don't laugh and turn away - this time
I don't wanna make a fuss
But this is the time for us
And I ain't gonna miss the bus - this time

No return -
So there'll be no turning back once I know that you'll be by my side
No return -
Maybe you'll give me all the love that you always felt you had to hide
No return -
I've come a thousand miles across the ocean
But that ain't half as far as my emotion
And now I reached the point of no return

While on my way down the avenue
I had to stop for a drink or two - or three
Now not that I was stalling you - for time
It's just I wanted to feel my best
And I almost passed the test
I need your lovin' to do the rest - this time

No return -
So please don't ever do what you've done so many times before
No return -
Because I've made up my mind that this time I'll make it thru your door
No return -
I rode above the clouds so far below me
But didn't get as high as when you hold me
And now I've reached the point of no return

I'm at the point of no return
I'm watching the candle burn - both ends
There's a lesson we both can learn - this time
I don't wanna make a fuss
But this is the time for us
I ain't gonna miss the bus - this time
*/

//#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 210031;

long long fact[N];
long long invf[N];

long long pw(long long a,long long b)
{
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv(long long x)
{
	return pw(x,bs-2);
}

long long C(long long n,long long m)
{
	if (m>n)
		return 0;
	long long res=fact[n];
	res*=invf[n-m];
	res%=bs;
	res*=invf[m];
	return res%bs;
}

long long f,w,h;
long long c1,c2;
long long ans_u,ans_d;

long long get_ways(long long total_items,long long stacks,long long bound)
{
	if (total_items==0&&stacks==0)
		return 1;
	if (stacks==0)
		return 0;

	total_items-=stacks*bound;
	if (total_items<0)
		return 0;
	return C(total_items+stacks-1,stacks-1);
}

int main(){
//	freopen("japanese.in","r",stdin);
//	freopen("japanese.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	fact[0]=1;
	for (int i=1;i<N;i++)
	{
		fact[i]=fact[i-1]*i%bs;
	}

	for (int i=0;i<N;i++)
	{
		invf[i]=inv(fact[i]);
	}

	// all ways

	cin>>f>>w>>h;
	for (int ttl=0;ttl<=f+w;ttl++)
	{
		for (int tp1=0;tp1<=1;tp1++)
		{
			if (tp1==0)
			{
				c1=(ttl+1)/2;
				c2=ttl-c1;
			}
			else
			{
				c2=(ttl+1)/2;
				c1=ttl-c2;
			}
			long long here=get_ways(f,c1,1)*get_ways(w,c2,1);
			here%=bs;
			ans_d=(ans_d+here)%bs;
		}
	}

	//cout<<ans_d<<endl;

	// bad ways
	for (int ttl=0;ttl<=f+w;ttl++)
	{
		for (int tp1=0;tp1<=1;tp1++)
		{
			if (tp1==0)
			{
				c1=(ttl+1)/2;
				c2=ttl-c1;
			}
			else
			{
				c2=(ttl+1)/2;
				c1=ttl-c2;
			}
			long long here=get_ways(f,c1,1)*get_ways(w,c2,h+1);
			here%=bs;
			ans_u=(ans_u+here)%bs;
		}
	}

	ans_d=inv(ans_d);

	cout<<ans_u*ans_d%bs<<endl;

	cin.get(); cin.get();
	return 0;
}