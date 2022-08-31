/*
September's here again
Every insecurity reminds you
Who's at the helm?
Darker times
With fear in the eyes
Who's the man in charge?

Invented isolation
Alone and safe inside
Struggle with words,
That make sense in time
Yet waiting for someone to enter say "I have a better plan"

Never have to worry
For all that we know
The truth be told
As we lay down low
Walking the thin line
Let the happiness in
For now it's fine
We're living the lie

When light breaks
Another way to matter
All questions somehow answered
When life comes crushing
At the early break of day
We've only come so far
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
#define bs 1000000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 1100;

int n, ans1, ans2, cnt;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	ans1 = 1e9;

	cin >> n;
	for (int start = 0; start < 7; start++)
	{
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if ((i+start) % 7>4)
				++cnt;
		}
		ans1 = min(ans1, cnt);
		ans2 = max(ans2, cnt);
	}
	cout << ans1 << " " << ans2 << endl;

	cin.get(); cin.get();
	return 0;
}