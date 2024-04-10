/*
Sudden gleams arise the sky
Rulers of the global fire
Death in perpetuity
To contaminate the clean

Spiteful anger
Devotion carved in stone
There is no
Redeemer
Darkened skies above

Hellfire
Hellfire
Hellfire

Can't push my face into the ground
Trapped and collapsed internal parts
Watch the fading blood red lights
Avert from moon and stars

Thrashing the tomb
To reveal what is inside
Disfigured
Rotten corpses
Leaving crucified

Hellfire
Hellfire
Hellfire

They sleep the wrath of aeons
Life that drowned in fire
With ghosts and the ancient stones
Leave the sentenced fate behind

Haunt the dreams in endless wars
Praying for the day of doom
Never find somebody's lap
To die into

Sudden gleams arise the sky
Rulers of the global fire
Death in perpetuity
To contaminate the clean

Hellfire
Hellfire
Hellfire
Hellfire
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200131;

int n, ar[N];

long long pw(long long a, long long b)
{
	if (b == 0)
		return 1;
	if (b % 2)
		return a*pw(a, b - 1) % bs;
	return pw(a*a%bs, b / 2);
}
int used[N];
int c_len;
int found_cycle;
int dep[N];

vector<int> g[N];

void dfs(int v)
{
	//cout << v << " " << dep[v] << endl;

	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to] == 2)
			continue;
		if (used[to] == 1)
		{
			found_cycle = 1;
			c_len = dep[v] - dep[to] + 1;
			break;
		}
		dep[to] = dep[v] + 1;
		dfs(to);
	}
	used[v] = 2;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		g[i].push_back(ar[i]);
	}

	int c_count = 0;

	long long ans = 1;

	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
		found_cycle = 0;
		c_len = 0;
		dfs(i);
		if (found_cycle)
		{
			c_count += c_len;
			//cout << c_len << "%" << endl;
			long long hr = pw(2, c_len) - 2;
			if (hr < 0)
				hr += bs;
			ans *= hr;
			ans %= bs;
		}
	}

	long long hr = pw(2, n - c_count);
	ans = ans*hr;
	ans %= bs;
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}