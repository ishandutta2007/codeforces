/*
Pain comes, lonely, weekend, shoulder, been here before.
Locked up, stepped on, so prominent, so loud, I can't belong.
Only by my so wide-eyed other side I can't belong.
Rain comes, priceless, do whatever works best, been here before.

If I could be good enough, then I would be blown away.
And I could be their everyone, and I could be there everyday.
If I could be good enough, then I could just glow.

If I could let go, then I could change the world, but I can't stop always tearing myself down.
I can be good enough. Yeah, I will break ground.

I focus on the dawn, man, 'cause something doesn't feel right.
I feel it in my bones like God is throwing stones. Yeah, I'm gonna find the light.
And the weight of what you're going through is bigger than your will to change.
You have to start somewhere; despair won't wear wherever again.

If I could be good enough, then I would be blown away.
And I could be their everyone, and I could be there everyday.
If I could be good enough, then I could just glow.

If I could let go, then I could change the world, but I can't stop always tearing myself down.
I can be good enough. Yeah, I will break ground.

Proud. Calm. Loud. Strong. Heart. Soul. I let go.

If I could let go, then I could change the world, but I can't stop always tearing myself down.
I can be good enough. Yeah, I will break ground, but I can't stop always tearing myself down.
I can be good enough. Yeah, I will break ground. Yeah, I will break ground.
I can be good enough. Yeah, I will break ground.
*/

#pragma GCC optimize("O3")
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
const int N = 200031;

int n,m,k;
int l,r;

long long solver(int first,int len)
{
	long long here=0;

	for (int i=1;i<=len;i++)
	{
		if (first==1)
		{
			here+=len-i+1;
			return here;
		}
		here+=first;
		first-=1;
		if (here>2e9)
			return here;
	}
	return here;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>k;
	int l,r;
	l=1;
	r=m;
	while (l<r)
	{
		int mid=l+r+1;
		mid/=2;
		long long here=solver(mid,k)+solver(mid,n-k+1)-mid;
		if (here>m)
			r=mid-1;
		else
			l=mid;
	}
	cout<<l<<endl;

	cin.get(); cin.get();
	return 0;
}