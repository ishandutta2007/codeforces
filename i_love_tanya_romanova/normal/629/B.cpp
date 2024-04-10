/*
I told you I was hurt
Bleeding on the inside
I told you I was lost
In the middle of my life

There's times I stayed alive for you
There's times I would've died for you
There's times it didn't matter at all

Will you help me find the right way up
Or let me take the wrong way down
Will you straighten me out
Or make me take the long way around
I took the low road in
I'll take the high road out
I'll do whatever it takes
To be the mistake you can't live without

Standing in the dark
I can see your shadow
You're the only light
That's breaking through the window

There's times I stayed alive for you
There's times I would've died for you
There's times it didn't matter at all

Will you help me find the right way up
Or let me take the wrong way down
Will you straighten me out
Or make me take the long way around
I took the low road in
I'll take the high road out
I'll do whatever it takes
To be the mistake you can't live without

We'll I'm not gonna give it away
Not gonna let it go, just to wake up someday gone! Gone!
The worst part is looking back
And knowing that I was wrong

Help me find the right way up
Or let me take the wrong way down
Will you straighten me out
Or make me take the long way around
I took the low road in
I'll take the high road out
I'll do whatever it takes
To be the mistake you can't live without

I'll do whatever it takes
To be the mistake you can't live without
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 100500;

const double INF = 1e18;

using namespace std;

int n;
string st;
int a, b;
int cnt[200][1000];
int ans;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> st;
		cin >> a >> b;
		for (int i = a; i <= b; i++)
		{
			cnt[st[0]][i]++;
		}
	}
	for (int i = 1; i <= 366; i++)
	{
		ans = max(ans, min(cnt['M'][i], cnt['F'][i])*2);
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}