/*
They never broke my will
'Cause my heart was strong
They won't justify, condemnation
My vindication, but I will survive

Stood my ground 'til the end
Engage the enemy, protect my friends

Nostradamus
Nostradamus

Tame the beast
They send to kill
The congregation
Never broke my will

Nostradamus
Nostradamus

He has overcome
He can take the throne

Nostradamus, dedication
Nostradamus, he's avenged
Nostradamus, our salvation
Nostradamus, he's avenged

I walked through fire
To justify their inquisitions
All condemned to die

Nostradamus
Nostradamus

Adversity on which I thrived
Destroys the altar
Now, I'm vilified

Nostradamus
Nostradamus

He has seized the day
He is here to stay

Nostradamus, dedication
Nostradamus, he's avenged
Nostradamus, our salvation
Nostradamus, he's avenged

Vindication
He has been avenged

They never broke my will
'Cause my heart was strong
They can't justify
I will survive

He has overpowered
It's his finest hour

Nostradamus, dedication
Nostradamus, he's avenged
Nostradamus, our salvation
Nostradamus, he's avenged

Nostradamus
Nostradamus
Nostradamus
Nostradamus
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
#define bsize 512

const int N = 300000;

using namespace std;

int n, m, a[N], b[N];
vector<int> g[N];
vector<int> order;
int dp[N];
int used[N];
void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
	order.push_back(v);
}

void trace()
{
	for (int i = 1; i <= m; i++)
	{
		g[a[i]].push_back(b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
		dfs(i);
	}
}
int solve(int sz)
{
	for (int i = 1; i <= n; i++)
	{
		g[i].clear();
	}

	for (int i = 1; i <= sz; i++)
	{
		g[a[i]].push_back(b[i]);
	}
	
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 0;
	}

	for (int i = 0; i < order.size(); i++)
	{
		int v = order[i];
		dp[v] = 1;
		for (int j = 0; j < g[v].size(); j++)
		{
			int to = g[v][j];
			dp[v] = max(dp[v], dp[to] + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);	
	return ans;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
	}

	trace();

	if (solve(m) < n)
	{
		cout << -1 << endl;
		return 0;
	}

	int l, r;
	l = 0;
	r = m;
	while (l < r)
	{
		int mid = l + r;
		mid /= 2;
		if (solve(mid) == n)
			r = mid;
		else
			l = mid + 1;
	}

	cout << l << endl;

	cin.get(); cin.get();
	return 0;
}