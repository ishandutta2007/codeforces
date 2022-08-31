/*
Blurred and pale
I saw your face
As my body rests
Everything has languished
But the sense
Of a memory fading

The morning light
So thin I can feel it breaking
It crosses the wall
Towards my body

The wall above
I saw it changing
In the morning light
Emptiness expanding
Wounds kept fresh
Through careful tending
*/

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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 102231;

int n, g[N], indeg[N];
int used[N];
int cnt;

long long gcd(long long a, long long b)
{
	while (a&&b)a > b ? a %= b : b %= a;
	return a + b;
}

long long lcm(long long a, long long b)
{
	long long q = gcd(a, b);
	return a / q*b;
}

void dfs(int v)
{
	used[v] = 1;
	++cnt;
	if (used[g[v]])
		return;
	dfs(g[v]);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> g[i];
		indeg[g[i]]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] == 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	long long ans = 1;

	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
		cnt = 0;
		dfs(i);
		ans = lcm(ans, cnt);
	}

	if (ans % 2 == 0)
		ans /= 2;
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}