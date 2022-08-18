/*
Strong, I need to be strong
'Cause this is the chance
That I'm not alone
Lies, betraying all your lies
Keeping you stuck and hiding your cries

That's the way you can keep your chances
That's the way to get my revenge

Life is the way it is
Live it like your own belief
'Cause when you reach your thoughts
It's not as easy when you don't believe

Wrong, it's hard to feel wrong
Facing this pride that makes your burn and die
Lies, you're a slave of your lies
That fill your eyes running inside your mind

You shout so loud
To mask your anger of being a rat
Stuck by your own act you bleed
With no regrets
You shout so loud
To mask your fear of being so lost
But it's so daft as the pain of never having been loved

Just look at yourself to find a way
Sometimes you feel that to reach a way out
It's up to you to look inside
Your own treasure
You keep inside you
No one will do it
Don't let your ghosts surround you

You are not invulnerable
All your sins will be exposed
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
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 100000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 500331;

int n, k;
string st;
int ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> k;

	cin >> st;
	
	for (int let = 'a'; let <= 'z'; let++)
	{
		int ptr = -1;
		int bad = 0;

		for (int i = 0; i < st.size(); i++)
		{
			if (i>0)
			{
				if (st[i - 1] != let)
					--bad;
			}
			while (true)
			{
				if (ptr + 1 == st.size())
					break;
				if (st[ptr + 1] != let&&bad == k)
					break;
				++ptr;
				if (st[ptr] != let)
					++bad;
			}
			ans = max(ans, ptr - i + 1);
		}
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}